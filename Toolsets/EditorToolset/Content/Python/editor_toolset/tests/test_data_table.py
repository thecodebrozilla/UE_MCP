# Copyright Epic Games, Inc. All Rights Reserved.

import json
import os
import tempfile
from contextlib import contextmanager
from typing import Iterator
from unittest.mock import patch

import unreal

from toolset_registry.tests.toolset_testcase import ToolCallTestCase
from toolset_registry.tests.automation import create_temp_folder
from editor_toolset.toolsets.data_table import DataTableTools


@contextmanager
def create_data_table(name: str = 'test_data_table') -> Iterator[unreal.DataTable]:
    with create_temp_folder() as folder:
        yield DataTableTools.create(folder, name, unreal.AttributeMetaData.static_struct())


class DataTableToolsTestCase(ToolCallTestCase):
    """Test DataTableTools toolset."""

    def test_create(self):
        """Ensures we can create a DataTable asset."""
        with create_data_table() as data_table:
            self.assertIsInstance(data_table, unreal.DataTable)
            self.assertEqual(list(DataTableTools.list_rows(data_table)), [])

    def test_get_schema(self):
        """Ensures get_schema returns all column names as a JSON string."""
        with create_data_table() as data_table:
            schema = DataTableTools.get_schema(data_table)
            self.assertIsInstance(schema, str)
            cols = json.loads(schema)
            self.assertEqual(
                set(cols.keys()), {'baseValue', 'minValue', 'maxValue', 'derivedAttributeInfo',
                                   'bCanStack'})

    def test_add_list_rows(self):
        """Ensures list_rows reflects rows that have been added."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['RowA', 'RowB'])
            rows = DataTableTools.list_rows(data_table)
            self.assertEqual(rows, ['RowA', 'RowB'])

    def test_add_rows_duplicate(self):
        """Ensures adding a row name that already exists in the table raises an error."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['TestRow'])
            with self.assertToolRaisesRuntimeError():
                DataTableTools.add_rows(data_table, ['TestRow'])

    def test_add_rows_duplicate_names(self):
        """Ensures add_rows raises an error when the input list contains duplicate names."""
        with create_data_table() as data_table:
            with self.assertToolRaisesRuntimeError():
                DataTableTools.add_rows(data_table, ['RowA', 'RowB', 'RowA'])

    def test_remove_rows(self):
        """Ensures we can remove rows and they no longer appear in list_rows."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['RowA', 'RowB', 'RowC'])
            DataTableTools.remove_rows(data_table, ['RowA', 'RowB'])
            rows = DataTableTools.list_rows(data_table)
            self.assertEqual(rows, ['RowC'])

    def test_remove_rows_nonexistent(self):
        """Ensures removing a nonexistent row raises an error."""
        with create_data_table() as data_table:
            with self.assertToolRaisesRuntimeError():
                DataTableTools.remove_rows(data_table, ['DoesNotExist'])

    def test_remove_rows_duplicate_names(self):
        """Ensures remove_rows raises an error when the input list contains duplicate names."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['RowA', 'RowB'])
            with self.assertToolRaisesRuntimeError():
                DataTableTools.remove_rows(data_table, ['RowA', 'RowB', 'RowA'])

    def test_rename_rows(self):
        """Ensures rows can be renamed and the new names appear in list_rows."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['RowA', 'RowB', 'RowC'])
            DataTableTools.rename_rows(data_table, {'RowA': 'RowX', 'RowB': 'RowY'})
            rows = DataTableTools.list_rows(data_table)
            self.assertEqual(rows, ['RowX', 'RowY', 'RowC'])

    def test_rename_rows_preserves_data(self):
        """Ensures renaming a row does not change its column values."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['RowA'])
            DataTableTools.set_rows(data_table, json.dumps({'RowA': {'baseValue': 7.0}}))
            DataTableTools.rename_rows(data_table, {'RowA': 'RowRenamed'})
            result = json.loads(DataTableTools.get_rows(data_table, ['RowRenamed']))
            self.assertAlmostEqual(result['RowRenamed']['baseValue'], 7.0)

    def test_rename_rows_swap(self):
        """Ensures two rows can have their names swapped."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['RowA', 'RowB'])
            DataTableTools.set_rows(data_table, json.dumps({
                'RowA': {'baseValue': 1.0},
                'RowB': {'baseValue': 2.0},
            }))
            DataTableTools.rename_rows(data_table, {'RowA': 'RowB', 'RowB': 'RowA'})
            result = json.loads(DataTableTools.get_rows(data_table, ['RowA', 'RowB']))
            self.assertAlmostEqual(result['RowA']['baseValue'], 2.0)
            self.assertAlmostEqual(result['RowB']['baseValue'], 1.0)

    def test_rename_rows_nonexistent(self):
        """Ensures renaming a row that does not exist raises an error."""
        with create_data_table() as data_table:
            with self.assertToolRaisesRuntimeError():
                DataTableTools.rename_rows(data_table, {'DoesNotExist': 'NewName'})

    def test_rename_rows_conflict(self):
        """Ensures renaming to a name already in use by another row raises an error."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['RowA', 'RowB'])
            with self.assertToolRaisesRuntimeError():
                DataTableTools.rename_rows(data_table, {'RowA': 'RowB'})

    def test_rename_rows_duplicate_new_names(self):
        """Ensures renaming two rows to the same new name raises an error."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['RowA', 'RowB'])
            with self.assertToolRaisesRuntimeError():
                DataTableTools.rename_rows(data_table, {'RowA': 'RowX', 'RowB': 'RowX'})

    def test_get_rows(self):
        """Ensures get_rows returns only the requested rows with the correct columns."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['RowA', 'RowB', 'RowC'])
            result = json.loads(DataTableTools.get_rows(data_table, ['RowA', 'RowB']))
            self.assertIsInstance(result, dict)
            self.assertIn('RowA', result)
            self.assertIn('RowB', result)
            self.assertNotIn('RowC', result)
            self.assertIn('bCanStack', result['RowA'])
            self.assertIn('derivedAttributeInfo', result['RowA'])

    def test_get_rows_nonexistent(self):
        """Ensures get_rows raises an error for a missing row."""
        with create_data_table() as data_table:
            with self.assertToolRaisesRuntimeError():
                DataTableTools.get_rows(data_table, ['DoesNotExist'])

    def test_deprecated_column(self):
        """Ensures operations behave correctly when a column is deprecated after table creation."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['RowA', 'RowB'])
            DataTableTools.set_rows(data_table, json.dumps({
                'RowA': {'baseValue': 1.0, 'bCanStack': True},
                'RowB': {'baseValue': 2.0},
            }))

            # Simulate 'bCanStack' being deprecated by patching get_schema to exclude it.
            full_schema = json.loads(DataTableTools.get_schema(data_table))
            reduced_schema = json.dumps({k: v for k, v in full_schema.items() if k != 'bCanStack'})

            with patch.object(DataTableTools, 'get_schema', return_value=reduced_schema):
                # get_rows must not expose the deprecated column.
                result = json.loads(DataTableTools.get_rows(data_table, ['RowA']))
                self.assertNotIn('bCanStack', result['RowA'])
                self.assertAlmostEqual(result['RowA']['baseValue'], 1.0)

                # set_rows must reject attempts to write to the deprecated column.
                with self.assertToolRaisesRuntimeError():
                    DataTableTools.set_rows(
                        data_table, json.dumps({'RowA': {'bCanStack': False}}))

                # add_rows and rename_rows must still succeed even though the deprecated
                # column is present in the underlying export data.
                DataTableTools.add_rows(data_table, ['RowC'])
                DataTableTools.rename_rows(data_table, {'RowC': 'RowD'})
                self.assertIn('RowD', DataTableTools.list_rows(data_table))

    def test_set_rows(self):
        """Ensures set_rows updates row data and can set multiple rows at once."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['RowA', 'RowB'])
            DataTableTools.set_rows(data_table, json.dumps({
                'RowA': {'baseValue': 5.0, 'bCanStack': True},
                'RowB': {'baseValue': 3.0},
            }))
            result = json.loads(DataTableTools.get_rows(data_table, ['RowA', 'RowB']))
            self.assertAlmostEqual(result['RowA']['baseValue'], 5.0)
            self.assertEqual(result['RowA']['bCanStack'], True)
            self.assertAlmostEqual(result['RowB']['baseValue'], 3.0)

    def test_set_rows_nonexistent(self):
        """Ensures set_rows raises an error for a missing row."""
        with create_data_table() as data_table:
            with self.assertToolRaisesRuntimeError():
                DataTableTools.set_rows(data_table, json.dumps({'DoesNotExist': {}}))

    def test_set_rows_invalid_json(self):
        """Ensures set_rows raises an error for invalid JSON input."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['TestRow'])
            for bad_value in ('not json', '[]', '42', '"hello"', 'null'):
                with self.assertToolRaisesRuntimeError():
                    DataTableTools.set_rows(data_table, bad_value)
            # Row values must also be JSON objects
            with self.assertToolRaisesRuntimeError():
                DataTableTools.set_rows(data_table, json.dumps({'TestRow': 'not an object'}))

    def test_set_rows_invalid_properties(self):
        """Ensures set_rows raises an error when properties don't match the schema."""
        with create_data_table() as data_table:
            DataTableTools.add_rows(data_table, ['TestRow'])
            with self.assertToolRaisesRuntimeError():
                DataTableTools.set_rows(
                    data_table, json.dumps({'TestRow': {'nonExistentColumn': 'value'}}))

    def test_search_row_structs_name(self):
        """Ensures search_row_structs filters by name wildcard."""
        structs = DataTableTools.search_row_structs('AttributeMetaData')
        self.assertIn(unreal.AttributeMetaData.static_struct(), structs)

    def test_search_row_structs_no_matches(self):
        """Ensures search_row_structs returns an empty list when nothing matches."""
        structs = DataTableTools.search_row_structs('ZZZNoSuchStruct')
        self.assertEqual(structs, [])

    def test_search_row_structs_default(self):
        """Ensures search_row_structs returns results when called with no arguments."""
        structs = DataTableTools.search_row_structs()
        self.assertGreater(len(structs), 0)
        self.assertIn(unreal.AttributeMetaData.static_struct(), structs)

    def test_import_file(self):
        """Ensures import_file populates a DataTable from CSV row values."""
        csv_content = '---,baseValue\nRowA,1.5\nRowB,2.5\n'
        with create_temp_folder() as folder, tempfile.TemporaryDirectory() as tmp_dir:
            path = os.path.join(tmp_dir, 'data.csv')
            with open(path, 'w') as f:
                f.write(csv_content)
            result = DataTableTools.import_file(
                folder, 'ImportedTable', path,
                unreal.AttributeMetaData.static_struct())
            self.assertEqual(len(result), 1)
            table = result[0]
            self.assertIsInstance(table, unreal.DataTable)
            self.assertEqual(set(DataTableTools.list_rows(table)), {'RowA', 'RowB'})
            rows = json.loads(DataTableTools.get_rows(table, ['RowA', 'RowB']))
            self.assertAlmostEqual(rows['RowA']['baseValue'], 1.5, places=4)
            self.assertAlmostEqual(rows['RowB']['baseValue'], 2.5, places=4)

    def test_import_file_unsupported_extension(self):
        """Ensures import_file rejects file extensions CSVImportFactory does not declare."""
        with create_temp_folder() as folder, tempfile.TemporaryDirectory() as tmp_dir:
            path = os.path.join(tmp_dir, 'data.json')
            with open(path, 'w') as f:
                f.write('{}')
            with self.assertToolRaisesRuntimeError():
                DataTableTools.import_file(
                    folder, 'NotATable', path,
                    unreal.AttributeMetaData.static_struct())
