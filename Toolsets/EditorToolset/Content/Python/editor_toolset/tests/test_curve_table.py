# Copyright Epic Games, Inc. All Rights Reserved.

import os
import tempfile
import unittest
from contextlib import contextmanager
from typing import Iterator

import unreal

from toolset_registry.tests.toolset_testcase import ToolCallTestCase
from toolset_registry.tests.automation import create_temp_folder
from editor_toolset.toolsets.curve_table import CurveTableTools


def _make_key(time: float, value: float) -> unreal.SimpleCurveKey:
    key = unreal.SimpleCurveKey()
    key.set_editor_property('time', time)
    key.set_editor_property('value', value)
    return key


@contextmanager
def create_curve_table(name: str = 'test_curve_table') -> Iterator[unreal.CurveTable]:
    with create_temp_folder() as folder:
        yield CurveTableTools.create(folder, name)


class CurveTableToolsTestCase(ToolCallTestCase):
    """Test CurveTableTools toolset."""

    def test_create(self):
        """Ensures we can create a CurveTable asset."""
        with create_curve_table() as curve_table:
            self.assertIsInstance(curve_table, unreal.CurveTable)

    def test_list_rows(self):
        """Ensures list_rows reflects rows that have been added."""
        with create_curve_table() as curve_table:
            initial_count = len(list(CurveTableTools.list_rows(curve_table)))
            CurveTableTools.add_row(curve_table, 'TestRow')
            rows = list(CurveTableTools.list_rows(curve_table))
            self.assertIn('TestRow', rows)
            self.assertEqual(len(rows), initial_count + 1)

    def test_add_row(self):
        """Ensures we can add a row and it appears in list_rows."""
        with create_curve_table() as curve_table:
            CurveTableTools.add_row(curve_table, 'TestRow')
            self.assertIn('TestRow', CurveTableTools.list_rows(curve_table))

    def test_add_row_default_value(self):
        """Ensures the default value is applied when adding a row."""
        with create_curve_table() as curve_table:
            CurveTableTools.add_row(curve_table, 'TestRow', default_value=5.0)
            _, sampled = unreal.DataTableFunctionLibrary.evaluate_curve_table_row(
                curve_table, 'TestRow', 999.0, '')
            self.assertAlmostEqual(sampled, 5.0, places=4)

    def test_add_row_duplicate(self):
        """Ensures adding a duplicate row name fails gracefully."""
        with create_curve_table() as curve_table:
            CurveTableTools.add_row(curve_table, 'TestRow')
            num_rows = len(CurveTableTools.list_rows(curve_table))
            with self.assertToolRaisesRuntimeError():
                CurveTableTools.add_row(curve_table, 'TestRow')
            self.assertEqual(num_rows, len(CurveTableTools.list_rows(curve_table)))

    def test_remove_row(self):
        """Ensures we can remove a row and it no longer appears in list_rows."""
        with create_curve_table() as curve_table:
            CurveTableTools.add_row(curve_table, 'TestRow')
            self.assertIn('TestRow', CurveTableTools.list_rows(curve_table))
            CurveTableTools.remove_row(curve_table, 'TestRow')
            self.assertNotIn('TestRow', CurveTableTools.list_rows(curve_table))

    def test_remove_row_nonexistent(self):
        """Ensures removing a nonexistent row fails gracefully."""
        with create_curve_table() as curve_table:
            with self.assertToolRaisesRuntimeError():
                CurveTableTools.remove_row(curve_table, 'DoesNotExist')

    def test_rename_row(self):
        """Ensures renaming a row updates list_rows correctly."""
        with create_curve_table() as curve_table:
            CurveTableTools.add_row(curve_table, 'OldName')
            CurveTableTools.rename_row(curve_table, 'OldName', 'NewName')
            rows = CurveTableTools.list_rows(curve_table)
            self.assertIn('NewName', rows)
            self.assertNotIn('OldName', rows)

    def test_rename_row_nonexistent(self):
        """Ensures renaming a nonexistent row fails gracefully."""
        with create_curve_table() as curve_table:
            with self.assertToolRaisesRuntimeError():
                CurveTableTools.rename_row(curve_table, 'DoesNotExist', 'NewName')

    def test_rename_row_duplicate(self):
        """Ensures renaming to an existing row name fails gracefully."""
        with create_curve_table() as curve_table:
            CurveTableTools.add_row(curve_table, 'Row1')
            CurveTableTools.add_row(curve_table, 'Row2')
            with self.assertToolRaisesRuntimeError():
                CurveTableTools.rename_row(curve_table, 'Row1', 'Row2')

    def test_set_keys(self):
        """Ensures set_keys replaces all keys in a row."""
        with create_curve_table() as curve_table:
            CurveTableTools.add_row(curve_table, 'TestRow')
            CurveTableTools.add_key(curve_table, 'TestRow', _make_key(0.0, 1.0))
            new_keys = [_make_key(2.0, 3.0), _make_key(4.0, 5.0)]
            self.assertTrue(CurveTableTools.set_keys(curve_table, 'TestRow', new_keys))
            keys = CurveTableTools.get_keys(curve_table, 'TestRow')
            self.assertEqual(len(keys), 2)
            self.assertFalse(any(abs(k.get_editor_property('time') - 0.0) < 1e-6 for k in keys))

    def test_add_key(self):
        """Ensures we can add a key and it appears in get_keys with the correct values."""
        with create_curve_table() as curve_table:
            CurveTableTools.add_row(curve_table, 'TestRow')
            self.assertTrue(CurveTableTools.add_key(curve_table, 'TestRow', _make_key(0.0, 1.0)))
            keys = CurveTableTools.get_keys(curve_table, 'TestRow')
            self.assertEqual(len(keys), 1)
            self.assertAlmostEqual(keys[0].get_editor_property('time'), 0.0, places=4)
            self.assertAlmostEqual(keys[0].get_editor_property('value'), 1.0, places=4)

    def test_get_keys(self):
        """Ensures get_keys returns all keys added to a row."""
        with create_curve_table() as curve_table:
            CurveTableTools.add_row(curve_table, 'TestRow')
            CurveTableTools.add_key(curve_table, 'TestRow', _make_key(0.0, 1.0))
            CurveTableTools.add_key(curve_table, 'TestRow', _make_key(1.0, 2.0))
            keys = CurveTableTools.get_keys(curve_table, 'TestRow')
            self.assertEqual(len(keys), 2)

    def test_get_keys_empty(self):
        """Ensures get_keys returns an empty list for a new row."""
        with create_curve_table() as curve_table:
            CurveTableTools.add_row(curve_table, 'TestRow')
            keys = CurveTableTools.get_keys(curve_table, 'TestRow')
            self.assertEqual(list(keys), [])

    def test_add_key_nonexistent_row(self):
        """Ensures add_key raises an error for a row that does not exist."""
        with create_curve_table() as curve_table:
            with self.assertToolRaisesRuntimeError():
                CurveTableTools.add_key(curve_table, 'DoesNotExist', _make_key(0.0, 1.0))

    def test_set_keys_nonexistent_row(self):
        """Ensures set_keys raises an error for a row that does not exist."""
        with create_curve_table() as curve_table:
            with self.assertToolRaisesRuntimeError():
                CurveTableTools.set_keys(curve_table, 'DoesNotExist', [_make_key(0.0, 1.0)])

    def test_get_keys_nonexistent_row(self):
        """Ensures get_keys raises an error for a row that does not exist."""
        with create_curve_table() as curve_table:
            with self.assertToolRaisesRuntimeError():
                CurveTableTools.get_keys(curve_table, 'DoesNotExist')

    def test_keys_preserved_across_rename(self):
        """Ensures key data is preserved when a row is renamed."""
        with create_curve_table() as curve_table:
            CurveTableTools.add_row(curve_table, 'OldName')
            CurveTableTools.add_key(curve_table, 'OldName', _make_key(0.0, 42.0))
            CurveTableTools.rename_row(curve_table, 'OldName', 'NewName')
            keys = CurveTableTools.get_keys(curve_table, 'NewName')
            self.assertEqual(len(keys), 1)

    def test_import_file(self):
        """Ensures import_file populates a CurveTable from CSV times and values."""
        # First CSV row: X (time) values. First column is a label placeholder.
        # Subsequent rows: <row name>, then Y values aligned to the X header.
        csv_content = '---,0.0,1.0,2.0\nCurveA,10.0,20.0,30.0\nCurveB,5.0,15.0,25.0\n'
        with create_temp_folder() as folder, tempfile.TemporaryDirectory() as tmp_dir:
            path = os.path.join(tmp_dir, 'curves.csv')
            with open(path, 'w') as f:
                f.write(csv_content)
            result = CurveTableTools.import_file(folder, 'ImportedCurves', path,
                                                  unreal.RichCurveInterpMode.RCIM_LINEAR)
            self.assertEqual(len(result), 1)
            table = result[0]
            self.assertIsInstance(table, unreal.CurveTable)
            self.assertEqual(set(CurveTableTools.list_rows(table)), {'CurveA', 'CurveB'})
            keys_a = CurveTableTools.get_keys(table, 'CurveA')
            self.assertEqual(len(keys_a), 3)
            self.assertAlmostEqual(keys_a[0].get_editor_property('time'), 0.0, places=4)
            self.assertAlmostEqual(keys_a[0].get_editor_property('value'), 10.0, places=4)
            self.assertAlmostEqual(keys_a[2].get_editor_property('time'), 2.0, places=4)
            self.assertAlmostEqual(keys_a[2].get_editor_property('value'), 30.0, places=4)

    def test_import_file_unsupported_extension(self):
        """Ensures import_file rejects file extensions CSVImportFactory does not declare."""
        with create_temp_folder() as folder, tempfile.TemporaryDirectory() as tmp_dir:
            path = os.path.join(tmp_dir, 'curves.json')
            with open(path, 'w') as f:
                f.write('{}')
            with self.assertToolRaisesRuntimeError():
                CurveTableTools.import_file(folder, 'NotCurves', path,
                                            unreal.RichCurveInterpMode.RCIM_LINEAR)

    def test_import_file_rejects_cubic(self):
        """Ensures import_file rejects RCIM_CUBIC because RichCurves tables
        are not editable by the rest of CurveTableTools."""
        csv_content = '---,0.0,1.0\nRow,1.0,2.0\n'
        with create_temp_folder() as folder, tempfile.TemporaryDirectory() as tmp_dir:
            path = os.path.join(tmp_dir, 'curves.csv')
            with open(path, 'w') as f:
                f.write(csv_content)
            with self.assertToolRaisesRuntimeError():
                CurveTableTools.import_file(
                    folder, 'CubicCurves', path,
                    unreal.RichCurveInterpMode.RCIM_CUBIC)
