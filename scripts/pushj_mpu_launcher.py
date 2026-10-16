#!/usr/bin/env python3
"""Build the single frozen r61b MPU implementation, without runtime probes."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tempfile

import pushj_asm as asmutil

SOURCE = 'inner_split_pass.kernel_runtime.sc'
STEM = 'inner_split_pass.kernel_runtime'
ROOT_FILES = dict(zip(asmutil.ROOTS, (
    ('k1_setup.m.asm', 'candidate_k1'),
    ('k2_push.m.asm', 'candidate_K2'),
    ('k3_deposit.m.asm', 'candidate_k3'),
)))
DEFAULT_ASSEMBLY_ORDER = [
    'k2_special_ibx.m.asm', 'k2_special_ibz.m.asm', 'k2_special_iby23.m.asm',
    'k2_e_fast_tail.m.asm', 'k2_special_ibz_tail.m.asm', 'k2_push.m.asm',
    'k3_deposit.m.asm', 'k1_setup.m.asm', 'k2_special_iby.m.asm',
    'k3_tail_body.m.asm', 'k2_spatial.m.asm', 'k2_e_fast.m.asm',
    'k2_special_e.m.asm', 'k2_reciprocal_rn.m.asm', 'k2_weights.m.asm',
]
COUNTERS = re.compile(r'\b(?:StartCycleCounter|ReadCycleCounter|StopCycleCounter|STARTCOUNTER|READCOUNTER|STOPCOUNTER|debug_print)\b', re.I)


def require(condition, message):
    if not condition:
        raise ValueError(message)


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def load_manifest(root):
    """Return the built-in PushJ assembly metadata."""
    require(DEFAULT_ASSEMBLY_ORDER, 'No frozen PushJ assembly order configured')
    return {'assembly_order': DEFAULT_ASSEMBLY_ORDER,
            'supported_spu_workers_per_block': [1, 2, 4],
            'source_sha256': {}}


def worker_count(command):
    values = [arg.split('=', 1)[1] for arg in command
              if arg.startswith('-DSYMPIC_PUSHJ_WORKERS=')]
    require(len(values) == 1 and values[0] in ('1', '2', '4'),
            'Expected one SYMPIC_PUSHJ_WORKERS definition: 1, 2 or 4')
    return int(values[0])


def check_layout(spu, ir, workers):
    require(workers in (1, 2, 4), 'Unsupported PushJ worker count')
    require(re.search(r'target datalayout = "[^"\n]*p:32:', ir), 'SPU pointers must be 32 bits')
    bank = '%struct.pushJ_weight_bank_t = type { %struct.pushJ_wt_axis_bank_t*, %struct.pushJ_wt_axis_bank_t*, %struct.pushJ_wt_axis_bank_t*, i8*, i8*, i8*, i8*, i8* }'
    require(bank in ir, 'Frozen eight-pointer bank ABI changed')
    allocations = []
    for suffix, size, region in [('pushJ_x_storage', 13568, 1), ('pushJ_bank_y', 4096, 2),
                                 ('pushJ_z_storage', 8704, 3), ('pushJ_state_storage', 5632, 4)]:
        decls = re.findall(r'^\s*\.size\s+(\S*' + suffix + r'),\s*(\d+)\s*$', spu, re.M)
        require(len(decls) == 1 and int(decls[0][1]) == size, 'Allocation size changed: ' + suffix)
        symbol = decls[0][0]
        section = re.findall(r'^\s*\.section\s+"(\.MEMORY' + str(region) + r'\.sdata\.' + re.escape(symbol)
                             + r'\.@public)","([a-zA-Z0-9]+)",@progbits\s*$', spu, re.M)
        require(len(section) == 1 and section[0][1] == ('awsrb' if region == 2 else 'awsr'),
                'Allocation bank/ACC flags changed: ' + suffix)
        allocations.append({'symbol': symbol, 'bytes': size, 'region': region, 'flags': section[0][1]})
    shared = re.findall(r'^\s*\.section\s+"([^"\n]*shJ_incf_priv[^"\n]*)","([a-zA-Z0-9]+)",@progbits\s*$', spu, re.M)
    require(len(shared) == 1 and shared[0][1] == 'awsrb', 'J requires shared ACC storage')
    # Verify the compiled shared objects as well as the per-APE bank ABI.
    # Each J slice has 375 deposit vectors plus four K2 scratch vectors.
    shared_objects = []
    for suffix, size, alignment in [('shE0', 4800, 8), ('shB0', 4800, 8),
                                    ('shB1', 4800, 8), ('shJ0', 3000, 8),
                                    ('shJ_incf_priv', workers * 379 * 64, 64),
                                    ('shParticle', workers * 48 * 8, 64),
                                    ('pushJ_ctx', 272, 8)]:
        decls = re.findall(r'^\s*\.size\s+(\S*' + suffix + r'),\s*(\d+)\s*$', spu, re.M)
        require(len(decls) == 1 and int(decls[0][1]) == size,
                'Shared allocation size changed: ' + suffix)
        symbol = decls[0][0]
        section = re.search(r'^\s*\.section\s+"(\.sdata[^"\n]*' + re.escape(symbol)
                            + r'\.@public)","awsrb",@progbits\s*\n\s*\.p2align\s+(\d+)\s*\n'
                            + re.escape(symbol) + ':', spu, re.M)
        require(section is not None and (1 << int(section[2])) >= alignment,
                'Shared bank/alignment changed: ' + suffix)
        shared_objects.append({'symbol': symbol, 'bytes': size,
                               'alignment': 1 << int(section[2])})
    shared_bytes = sum(item['bytes'] for item in shared_objects)
    require(shared_bytes + 512 <= 256 * 1024, 'PushJ shared DM capacity exceeded')
    return {'allocations': allocations, 'shared_J': shared,
            'spu_workers_per_block': workers, 'shared_objects': shared_objects,
            'shared_array_bytes': shared_bytes, 'shared_reserve_bytes': 512,
            'J_slice_bytes': 379 * 64, 'particle_slice_bytes': 48 * 8}


def transform(original, sources):
    sources = dict(sources)
    require(not COUNTERS.search(asmutil._code(original)), 'Compiler MPU contains instrumentation')
    edits = []
    for old, (filename, symbol) in ROOT_FILES.items():
        start, end = asmutil._span(original, old)
        body = original[start:end]
        source = sources[filename]
        hs, he = asmutil._span(source, symbol)
        hand = source[hs:he]
        replacement = body[:asmutil._entry(body, old).end()]
        replacement += asmutil._token(symbol).sub(old, hand[asmutil._entry(hand, symbol).end():])
        edits.append((start, end, replacement))
    result = original
    for start, end, replacement in sorted(edits, reverse=True):
        result = result[:start] + replacement + result[end:]
    # These continuations must remain adjacent in their head's input section.
    tails = {'k2_special_ibz_tail.m.asm', 'k2_e_fast_tail.m.asm'}
    for head, tail in [('k2_special_ibz.m.asm', 'k2_special_ibz_tail.m.asm'), ('k2_e_fast.m.asm', 'k2_e_fast_tail.m.asm')]:
        continuation, count = re.subn(r'^\s*\.section[^\n]*\n', '', sources[tail], count=1, flags=re.M)
        require(count == 1, 'Missing continuation section: ' + tail)
        sources[head] += '\n' + continuation
    roots = {filename for filename, _ in ROOT_FILES.values()}
    for name, source in sources.items():
        if name not in roots | tails:
            result += '\n// frozen r61b helper ' + name + '\n' + source
    labels = asmutil._labels(result)
    require(len(labels) == len(set(labels)), 'Duplicate MPU labels')
    require(all(labels.count(root) == 1 for root in ROOT_FILES), 'Root definition missing')
    require(not COUNTERS.search(asmutil._code(result)), 'Frozen MPU contains instrumentation')
    require(not re.search(r'%(k2_reduce_acc\d|k2_private_frame|k2_stage_descriptors|k2_iby_(acc_descriptor|broadcast_index)|k2_e_broadcast_indexes)\b', result),
            'Standalone scratch storage cannot be linked into the project')
    return result


def output_index(command):
    indexes = [i for i, arg in enumerate(command) if arg == '-o']
    require(len(indexes) == 1 and indexes[0] + 1 < len(command), 'Expected one explicit -o output')
    return indexes[0] + 1


def run(command):
    # Check pinned shared adapters for every SCALE translation unit, including
    # incremental GEO rebuilds that do not need an MPU root replacement.
    scale_sources = [Path(arg).resolve() for arg in command[1:] if arg.endswith('.kernel_runtime.sc')]
    if '-c' in command and scale_sources:
        load_manifest(scale_sources[0].parents[2])
    if '-c' not in command or not any(Path(arg).name == SOURCE for arg in command[1:]):
        return subprocess.run(command).returncode
    require(not any(arg.startswith('@') for arg in command), 'Response files are unsupported for frozen compilation')
    require(not any(arg.startswith('-save-temps') and arg != '-save-temps=obj' for arg in command), 'Conflicting save-temps option')
    for owner in ('spu', 'mpu'):
        flags = [arg for arg in command if arg in ('-fscale-' + owner + '-masight', '-fno-scale-' + owner + '-masight')]
        require(flags and flags[-1] == '-fno-scale-' + owner + '-masight', 'Automatic counters must be disabled: ' + owner)
    source = next(Path(arg).resolve() for arg in command[1:] if Path(arg).name == SOURCE)
    root = source.parents[2]
    freeze = load_manifest(root)
    workers = worker_count(command)
    require(workers in freeze['supported_spu_workers_per_block'], 'Worker count is not in freeze manifest')
    hand_dir = source.parent / 'pushj_frozen'
    sources = {name: (hand_dir / name).read_text() for name in freeze['assembly_order']}
    index = output_index(command)
    output = Path(command[index]).resolve()
    compiler = shutil.which(command[0])
    require(compiler, 'Compiler executable not found')
    sdk = Path(compiler).resolve().parent
    # Compile and bundle privately. A failed replacement cannot leave an auto
    # compiler object at the final target path for a later incremental build.
    with tempfile.TemporaryDirectory(prefix='pushj-frozen-', dir=output.parent) as directory:
        work = Path(directory)
        compile_command = list(command)
        compile_command[index] = str(work / (STEM + '.sc.o'))
        if '-save-temps=obj' not in compile_command:
            compile_command.insert(1, '-save-temps=obj')
        subprocess.run(compile_command, check=True)
        parts = {suffix: work / (STEM + '.' + suffix) for suffix in ('spu.s', 'spu.o', 'mpu.s', 'mpu.o', 'spu.ll')}
        parts['host.o'] = work / (STEM + '-host-x86_64-unknown-linux-gnu.o')
        for path in parts.values():
            require(path.is_file() and path.stat().st_size, 'Missing compiler component: ' + str(path))
        before = {key: sha(path) for key, path in parts.items()}
        layout = check_layout(parts['spu.s'].read_text(), parts['spu.ll'].read_text(), workers)
        require(not COUNTERS.search(asmutil._code(parts['spu.s'].read_text())), 'Compiler SPU contains instrumentation')
        generated = transform(parts['mpu.s'].read_text(), sources)
        hand_asm, hand_obj, fat = work / 'frozen.mpu.s', work / 'frozen.mpu.o', work / 'frozen.fat.o'
        hand_asm.write_text(generated)
        subprocess.run([str(sdk / 'llvm-mc'), '--triple=aurora_m', '--filetype=obj', str(hand_asm), '-o', str(hand_obj)], check=True)
        inputs = [parts['spu.o'], hand_obj, parts['host.o']]
        require(not any(',' in str(path) for path in inputs), 'Bundler paths cannot contain commas')
        subprocess.run([str(sdk / 'clang-offload-bundler'), '-type=o', '--bundle-align=4096',
                        '-targets=scale-aurora_s,scale-aurora_m,host-x86_64-unknown-linux-gnu',
                        '-inputs=' + ','.join(map(str, inputs)), '-outputs=' + str(fat)], check=True)
        require(before == {key: sha(path) for key, path in parts.items()}, 'Compiler components changed during replacement')
        require(fat.is_file() and fat.stat().st_size, 'Empty bundled object')
        evidence = output.parent / 'pushj-frozen'
        evidence.mkdir(exist_ok=True)
        for name, path in {'compiler.mpu.s': parts['mpu.s'], 'compiler.spu.s': parts['spu.s'],
                           'compiler.spu.ll': parts['spu.ll'], 'frozen.mpu.s': hand_asm, 'frozen.mpu.o': hand_obj}.items():
            shutil.copy2(path, evidence / name)
        receipt = {'version': freeze['version'], 'status': 'built', 'runtime_executed': False,
                   'spu_workers_per_block': workers, 'particle_simd_width': 8,
                   'source_sha256': freeze['source_sha256'], 'compiler_components_sha256': before,
                   'layout': layout, 'frozen_mpu_sha256': sha(hand_obj), 'output_sha256': sha(fat),
                   'counter_instructions': 0, 'roots': list(ROOT_FILES), 'compile_command': compile_command}
        (evidence / 'manifest.json').write_text(json.dumps(receipt, indent=2) + '\n')
        os.replace(fat, output)
    print('Frozen pushJ r61b: ' + str(evidence / 'manifest.json'), flush=True)
    return 0


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', nargs=argparse.REMAINDER)
    args = parser.parse_args()
    try:
        command = args.command[1:] if args.command[:1] == ['--'] else args.command
        require(command, 'Compiler command required after --')
        return run(command)
    except (ValueError, OSError, KeyError, subprocess.CalledProcessError) as exc:
        print('Frozen pushJ build failed: ' + str(exc), file=sys.stderr)
        return 1


if __name__ == '__main__':
    raise SystemExit(main())
