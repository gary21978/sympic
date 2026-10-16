#!/usr/bin/env python3
"""Run a frozen PushJ build on a Linux MAPU device/guest in a fresh output directory."""
import argparse
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess

from compare_pushj_results import compare, expected_files


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build-dir', required=True, type=Path)
    parser.add_argument('--case-dir', required=True, type=Path)
    parser.add_argument('--out-dir', required=True, type=Path)
    parser.add_argument('--steps', type=int)
    parser.add_argument('--particles', type=int)
    parser.add_argument('--grid', type=int, nargs=3, metavar=('X', 'Y', 'Z'))
    parser.add_argument('--ref-dir', type=Path)
    parser.add_argument('--reference-dumps', type=int, default=4)
    parser.add_argument('--capture-only', action='store_true')
    args = parser.parse_args()
    if args.capture_only and args.ref_dir:
        parser.error('capture-only cannot specify a reference')
    root = Path(__file__).resolve().parents[1]
    build, case, output = (p.resolve() for p in (args.build_dir, args.case_dir, args.out_dir))
    reference = (args.ref_dir or case / 'result_npy').resolve()
    # Match the existing guest runner lock so device jobs cannot overlap.
    with open('/run/sympic-mapu-case.lock', 'w') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        output.mkdir(parents=True, exist_ok=False)
        config_name = re.fullmatch(r'\s*\(optload\s+"(cyclone_small\.ss)"\)\s*',
                                  (case / 'test.ss').read_text())
        if not config_name:
            raise ValueError('Unexpected demo-pushj entry')
        config = (case / config_name[1]).read_text()
        original = config
        overrides = [('NUM_TIMESTEP', args.steps), ('NPG0', args.particles)]
        if args.grid:
            overrides += list(zip(('XMAX', 'YMAX', 'ZMAX'), args.grid))
        for name, value in overrides:
            if value is not None:
                if value < 1:
                    raise ValueError(name + ' must be positive')
                config, count = re.subn(r'\(' + name + r'\s+\d+\)', f'({name} {value})', config)
                if count != 1:
                    raise ValueError('Expected one ' + name + ' setting')
        setting = lambda name: int(re.search(r'\(' + name + r'\s+(\d+)\)', config)[1])
        steps, interval = setting('NUM_TIMESTEP'), setting('NUM_DUMP_TIMESTEP')
        dumps = (steps + interval - 1) // interval
        (output / config_name[1]).write_text(config)
        (output / 'test.ss').write_bytes((case / 'test.ss').read_bytes())
        manifests = list(build.glob('src/mapu_/CMakeFiles/*/pushj-frozen/manifest.json'))
        if len(manifests) != 1:
            raise RuntimeError(f'Expected one frozen PushJ build manifest under {build}; found {manifests}')
        manifest_path = manifests[0]
        manifest = json.loads(manifest_path.read_text())
        executable = build / 'bin/sympic.out'
        if not executable.exists():
            executable = build / 'bin/sympic'
        evidence = {'workers': manifest['spu_workers_per_block'], 'steps': steps,
                    'grid': [setting(name) for name in ('XMAX', 'YMAX', 'ZMAX')],
                    'particles_per_cell': setting('NPG0'), 'expected_dumps': dumps,
                    'case_derived': config != original, 'build_manifest': manifest,
                    'input_sha256': {name: sha(case/name) for name in ('test.ss', config_name[1])},
                    'executed_config_sha256': sha(output/config_name[1]),
                    'artifacts': {str(path.relative_to(build)): sha(path) for path in
                                  (executable, build/'bin/gapsio2to0') if path.is_file()}}
        (output / 'inputs.json').write_text(json.dumps(evidence, indent=2) + '\n')
        env = dict(os.environ, STDLIB=str(root/'src/stdlib.scm'), OMP_NUM_THREADS='1',
                   MAPS_KMD_MODE='2', MALOG_STDOUT_LEVEL='error', MALOG_SIMPLE_FILE_LEVEL='error',
                   MALOG_LEVEL='error', MAPS_API_LOG_ALWAYS='0',
                   LD_LIBRARY_PATH=str(build/'lib') + ':/opt/maps/lib:/opt/maps/toolchain/lib/scale/release:/opt/maps/toolchain/lib/scale/llvm_dynamic')
        print(f'Run workers={evidence["workers"]} steps={steps} particles={evidence["particles_per_cell"]}: {output}', flush=True)
        # MPI must not consume the remaining commands when this runner is
        # invoked from a shell script supplied over SSH standard input.
        mpirun = ['mpirun', '--allow-run-as-root', '--oversubscribe', '-n', '1']
        with (output / 'application.log').open('w') as log:
            process = subprocess.run(mpirun + [str(executable), 'test.ss'],
                                     cwd=output, env=env, stdin=subprocess.DEVNULL,
                                     stdout=log, stderr=subprocess.STDOUT)
        (output / 'application-exit-code.txt').write_text(str(process.returncode) + '\n')
        if process.returncode:
            raise RuntimeError('Application failed; see application.log')
        log = (output/'application.log').read_text(errors='replace')
        if re.search(r'fatal|panic|Simulator Error|RegisterConflict|multi launch mismatch', log, re.I):
            raise RuntimeError('Device error marker in application.log')
        observed = [int(x) for x in re.findall(r'\bstep=(\d+)\s', log)]
        if observed != list(range(steps)):
            raise RuntimeError(f'Incomplete steps: {observed}, expected {steps}')
        with (output / 'conversion.log').open('w') as log:
            for var in ('tmpEB', 'tmpEN', 'tmpJ'):
                shards = sorted(output.glob(var + '_PROC_*'))
                if not shards:
                    raise RuntimeError('Missing output ' + var)
                subprocess.run(mpirun + [str(build/'bin/gapsio2to0')] +
                               [str(p) for p in shards] + [str(output/var)],
                               cwd=output, env=env, stdin=subprocess.DEVNULL,
                               stdout=log, stderr=subprocess.STDOUT, check=True)
            subprocess.run(['python3', str(root/'scripts/gapsio_to_npy.py'), '--work-dir', str(output),
                            '--out-dir', str(output/'test_npy')], cwd=output, env=env, stdin=subprocess.DEVNULL,
                           stdout=log, stderr=subprocess.STDOUT, check=True)
        actual = {p.name for p in (output/'test_npy').glob('*.npy')}
        if actual != expected_files(dumps):
            raise RuntimeError('Output coverage mismatch')
        if args.capture_only:
            result = {'capture_complete': True, 'numerically_validated': False, 'dumps': dumps}
        else:
            result = compare(output/'test_npy', reference, dumps, args.reference_dumps)
        (output / 'comparison.json').write_text(json.dumps(result, indent=2, allow_nan=False) + '\n')
        passed = result.get('passed', args.capture_only)
        (output / 'exit-code.txt').write_text(('0' if passed else '1') + '\n')
        print(json.dumps({k: v for k, v in result.items() if k != 'arrays'}), flush=True)
        return 0 if passed else 1


if __name__ == '__main__':
    raise SystemExit(main())
