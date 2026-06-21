# Copyright Epic Games, Inc. All Rights Reserved.

from . import unittest_runner

discover_tests = unittest_runner.discover_tests
run_tests = unittest_runner.discover_and_run_tests
run_test = unittest_runner.run_test

# Temporary backwards compatibility for test_programmatic.py.
run_unittest_suite = unittest_runner.run_test