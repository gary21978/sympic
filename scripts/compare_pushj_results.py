#!/usr/bin/env python3
"""Strict demo-pushj output comparison with explicit dump coverage and JSON evidence."""
import argparse
import hashlib
import json
from pathlib import Path

import numpy as np


def expected_files(dumps):
    return {f'{var}_t{i:04d}.npy' for var, count in
            [('tmpEB', 2 * dumps), ('tmpEN', dumps), ('tmpJ', dumps)] for i in range(count)}


def compare(test, reference, dumps, reference_dumps, tolerance=1e-10):
    expected = expected_files(dumps)
    ref_expected = expected_files(reference_dumps)
    actual = {p.name for p in test.glob('*.npy')}
    ref_actual = {p.name for p in reference.glob('*.npy')}
    errors = []
    if actual != expected:
        errors.append({'test_missing': sorted(expected - actual), 'test_extra': sorted(actual - expected)})
    if ref_actual != ref_expected:
        errors.append({'reference_missing': sorted(ref_expected - ref_actual),
                       'reference_extra': sorted(ref_actual - ref_expected)})
    if dumps > reference_dumps:
        errors.append({'error': 'Reference does not cover all test dumps'})
    rows = []
    for name in sorted(expected & actual & ref_actual):
        a, b = np.load(test / name, allow_pickle=False), np.load(reference / name, allow_pickle=False)
        row = {'file': name, 'test_sha256': hashlib.sha256((test/name).read_bytes()).hexdigest(),
               'reference_sha256': hashlib.sha256((reference/name).read_bytes()).hexdigest(),
               'shape': list(a.shape), 'passed': False}
        if a.shape != b.shape or a.size == 0:
            row['error'] = 'shape mismatch or empty array'
        elif not np.isfinite(a).all() or not np.isfinite(b).all():
            row['error'] = 'non-finite data'
        else:
            max_abs = float(np.max(np.abs(a - b)))
            relative = max_abs / max(float(np.max(np.abs(b))), 1.0)
            row.update(max_absolute_error=max_abs, normalized_error=relative,
                       bitwise_equal=bool(np.array_equal(a, b)), passed=relative < tolerance)
        rows.append(row)
    passed = not errors and len(rows) == len(expected) and all(row['passed'] for row in rows)
    return {'passed': passed, 'test_directory': str(test), 'reference_directory': str(reference),
            'dumps_compared': dumps, 'reference_dumps': reference_dumps,
            'tolerance': tolerance, 'expected_arrays': len(expected),
            'passed_arrays': sum(row['passed'] for row in rows), 'errors': errors, 'arrays': rows}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--test-dir', required=True, type=Path)
    parser.add_argument('--ref-dir', required=True, type=Path)
    parser.add_argument('--dumps', type=int, required=True)
    parser.add_argument('--reference-dumps', type=int, required=True)
    parser.add_argument('--json', type=Path, required=True)
    args = parser.parse_args()
    if args.dumps <= 0 or args.reference_dumps <= 0:
        parser.error('dump counts must be positive')
    result = compare(args.test_dir, args.ref_dir, args.dumps, args.reference_dumps)
    args.json.write_text(json.dumps(result, indent=2, allow_nan=False) + '\n')
    worst = max((r.get('normalized_error', 0) for r in result['arrays']), default=0)
    print(f"pass={result['passed_arrays']}/{result['expected_arrays']} max_normalized_error={worst:.6e}")
    for error in result['errors']:
        print(error)
    raise SystemExit(0 if result['passed'] else 1)
