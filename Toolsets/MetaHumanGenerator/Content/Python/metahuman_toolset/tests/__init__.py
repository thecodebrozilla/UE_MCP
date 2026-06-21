# Copyright Epic Games, Inc. All Rights Reserved.

import sys
import unittest


def run_tests(test_name=None, vv=1):
    """Run all tests.

    If param 'test_name' is not None, only run tests matching that name.
    Param 'vv' sets the test runner verbosity level.
    """
    pattern = 'test*.py'
    if test_name:
        pattern = f'{test_name}*.py'

    suite = unittest.defaultTestLoader.discover('metahuman_toolset.tests', pattern)
    test_runner = unittest.TextTestRunner(
        verbosity=vv, stream=sys.stdout, buffer=True)
    test_result = test_runner.run(suite)

    # On test failure, resend error messages to stderr so that automated tests
    # in editor can see that the test failed.
    if not test_result.wasSuccessful():
        for error in test_result.errors:
            test_case, traceback = error
            print(f'ERROR: {test_case}', file=sys.stderr)
            print(traceback, file=sys.stderr)
        for failure in test_result.failures:
            test_case, traceback = failure
            print(f'FAIL: {test_case}', file=sys.stderr)
            print(traceback, file=sys.stderr)
