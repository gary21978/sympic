#!/usr/bin/env python3
"""Regression gates must reject incomplete or non-finite PushJ output."""
from pathlib import Path
import tempfile
import unittest

import numpy as np

from compare_pushj_results import compare, expected_files


class ComparisonChecks(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory()
        self.addCleanup(self.directory.cleanup)
        self.test = Path(self.directory.name) / 'test'
        self.reference = Path(self.directory.name) / 'reference'
        for directory in (self.test, self.reference):
            directory.mkdir()
            for name in expected_files(2):
                np.save(directory/name, np.zeros((4, 4, 4, 7 if name.startswith('tmpEN') else 3)))

    def result(self):
        return compare(self.test, self.reference, 2, 2)

    def test_complete(self):
        result = self.result()
        self.assertTrue(result['passed'])
        self.assertEqual(result['passed_arrays'], 8)

    def test_missing_last_output(self):
        (self.test/'tmpJ_t0001.npy').unlink()
        self.assertFalse(self.result()['passed'])

    def test_missing_reference(self):
        (self.reference/'tmpEN_t0001.npy').unlink()
        self.assertFalse(self.result()['passed'])

    def test_nonfinite_even_when_equal(self):
        for value in (np.nan, np.inf):
            for directory in (self.test, self.reference):
                np.save(directory/'tmpJ_t0001.npy', np.full((4, 4, 4, 3), value))
            self.assertFalse(self.result()['passed'])

    def test_excess_error(self):
        np.save(self.test/'tmpJ_t0001.npy', np.full((4, 4, 4, 3), 1e-8))
        self.assertFalse(self.result()['passed'])

    def test_shape_mismatch(self):
        np.save(self.test/'tmpJ_t0001.npy', np.zeros((1,)))
        self.assertFalse(self.result()['passed'])

    def test_partial_reference_coverage_is_explicit(self):
        for name in expected_files(4) - expected_files(2):
            np.save(self.reference/name, np.zeros((4, 4, 4, 7 if name.startswith('tmpEN') else 3)))
        self.assertFalse(self.result()['passed'])
        result = compare(self.test, self.reference, 2, 4)
        self.assertTrue(result['passed'])
        self.assertEqual(result['dumps_compared'], 2)
        self.assertEqual(result['reference_dumps'], 4)


if __name__ == '__main__':
    unittest.main()
