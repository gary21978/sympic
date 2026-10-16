#!/usr/bin/env python3
"""Exercise PushJ build guards against actual compiler output, without a device."""
import argparse
import json
from pathlib import Path
import re
import unittest

import pushj_mpu_launcher as launcher


class LayoutChecks(unittest.TestCase):
    def test_actual_layout(self):
        layout = launcher.check_layout(self.spu, self.ir, self.workers)
        self.assertEqual(layout['spu_workers_per_block'], self.workers)
        self.assertEqual(layout['shared_array_bytes'], 17672 + 24640 * self.workers)

    def test_worker_definition(self):
        for n in (1, 2, 4):
            self.assertEqual(launcher.worker_count([f'-DSYMPIC_PUSHJ_WORKERS={n}']), n)
        for args in ([], ['-DSYMPIC_PUSHJ_WORKERS=8'],
                     ['-DSYMPIC_PUSHJ_WORKERS=4', '-DSYMPIC_PUSHJ_WORKERS=1']):
            with self.assertRaises(ValueError):
                launcher.worker_count(args)

    def test_mismatched_worker_layout(self):
        with self.assertRaisesRegex(ValueError, 'Shared allocation size'):
            launcher.check_layout(self.spu, self.ir, 1 if self.workers != 1 else 4)

    def test_missing_j_scratch(self):
        spu, count = re.subn(r'(\.size\s+\S*shJ_incf_priv,\s*)\d+',
                            lambda m: m[1] + str(self.workers * 375 * 64), self.spu)
        self.assertEqual(count, 1)
        with self.assertRaisesRegex(ValueError, 'Shared allocation size'):
            launcher.check_layout(spu, self.ir, self.workers)

    def test_shared_acc_flag(self):
        spu, count = re.subn(r'(\.section[^\n]*shJ_incf_priv[^\n]*")awsrb("[^\n]*)',
                            r'\1awsr\2', self.spu)
        self.assertEqual(count, 1)
        with self.assertRaisesRegex(ValueError, 'shared ACC'):
            launcher.check_layout(spu, self.ir, self.workers)

    def test_particle_alignment(self):
        spu, count = re.subn(r'(\.section[^\n]*shParticle[^\n]*\n\s*\.p2align\s+)\d+',
                            r'\g<1>3', self.spu)
        self.assertEqual(count, 1)
        with self.assertRaisesRegex(ValueError, 'alignment'):
            launcher.check_layout(spu, self.ir, self.workers)

    def test_pointer_width(self):
        with self.assertRaisesRegex(ValueError, '32 bits'):
            launcher.check_layout(self.spu, self.ir.replace('p:32:', 'p:64:'), self.workers)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build-dir', type=Path, required=True)
    args = parser.parse_args()
    evidence = args.build_dir / 'src/mapu_/CMakeFiles/mapu_yeefdtd.dir/pushj-frozen'
    LayoutChecks.spu = (evidence / 'compiler.spu.s').read_text()
    LayoutChecks.ir = (evidence / 'compiler.spu.ll').read_text()
    LayoutChecks.workers = json.loads((evidence / 'manifest.json').read_text())['spu_workers_per_block']
    unittest.main(argv=['test_pushj_mpu_launcher.py'])
