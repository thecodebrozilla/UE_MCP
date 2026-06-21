# Copyright Epic Games, Inc. All Rights Reserved.

import os
import tempfile
from contextlib import contextmanager
from typing import Iterator

import unreal

from toolset_registry.tests.toolset_testcase import ToolCallTestCase
from toolset_registry.tests.automation import create_temp_folder
from editor_toolset.toolsets.string_table import StringTableTools


@contextmanager
def create_string_table(name: str = 'test_string_table') -> Iterator[unreal.StringTable]:
    with create_temp_folder() as folder:
        yield StringTableTools.create(folder, name)


class StringTableToolsTestCase(ToolCallTestCase):
    """Test StringTableTools toolset."""

    def test_create(self):
        """Ensures we can create a StringTable asset."""
        with create_string_table() as string_table:
            self.assertIsInstance(string_table, unreal.StringTable)

    def test_get_table_id(self):
        """Ensures get_table_id returns the full object path of the string table asset."""
        with create_string_table('my_string_table') as string_table:
            table_id = StringTableTools.get_table_id(string_table)
            self.assertEqual(table_id, string_table.get_path_name())

    def test_get_namespace(self):
        """Ensures get_namespace returns the asset name as the default namespace."""
        with create_string_table('my_table') as string_table:
            self.assertEqual('my_table', StringTableTools.get_namespace(string_table))

    def test_list_keys_empty(self):
        """Ensures list_keys returns an empty list for a new string table."""
        with create_string_table() as string_table:
            self.assertEqual(StringTableTools.list_keys(string_table), [])

    def test_set_entry_adds_key(self):
        """Ensures set_entry adds the key to list_keys."""
        with create_string_table() as string_table:
            StringTableTools.set_entry(string_table, 'TestKey', 'Hello World')
            self.assertIn('TestKey', StringTableTools.list_keys(string_table))

    def test_get_entry(self):
        """Ensures get_entry returns the value that was set."""
        with create_string_table() as string_table:
            StringTableTools.set_entry(string_table, 'TestKey', 'Hello World')
            self.assertEqual(StringTableTools.get_entry(string_table, 'TestKey'), 'Hello World')

    def test_get_entry_nonexistent(self):
        """Ensures get_entry raises an error for a key that does not exist."""
        with create_string_table() as string_table:
            with self.assertToolRaisesRuntimeError():
                StringTableTools.get_entry(string_table, 'DoesNotExist')

    def test_set_entry_update(self):
        """Ensures set_entry replaces the value of an existing key."""
        with create_string_table() as string_table:
            StringTableTools.set_entry(string_table, 'TestKey', 'Initial Value')
            StringTableTools.set_entry(string_table, 'TestKey', 'Updated Value')
            self.assertEqual(StringTableTools.get_entry(string_table, 'TestKey'), 'Updated Value')

    def test_set_entry_preserves_others(self):
        """Ensures set_entry does not affect other entries."""
        with create_string_table() as string_table:
            StringTableTools.set_entry(string_table, 'KeyA', 'Value A')
            StringTableTools.set_entry(string_table, 'KeyB', 'Value B')
            self.assertEqual(StringTableTools.get_entry(string_table, 'KeyA'), 'Value A')
            self.assertEqual(StringTableTools.get_entry(string_table, 'KeyB'), 'Value B')

    def test_remove_entry(self):
        """Ensures remove_entry removes the key from list_keys when other entries remain."""
        with create_string_table() as string_table:
            StringTableTools.set_entry(string_table, 'KeyA', 'Value A')
            StringTableTools.set_entry(string_table, 'KeyB', 'Value B')
            StringTableTools.remove_entry(string_table, 'KeyA')
            self.assertNotIn('KeyA', StringTableTools.list_keys(string_table))

    def test_remove_entry_nonexistent(self):
        """Ensures remove_entry raises an error for a key that does not exist."""
        with create_string_table() as string_table:
            StringTableTools.set_entry(string_table, 'TestKey', 'Hello World')
            with self.assertToolRaisesRuntimeError():
                StringTableTools.remove_entry(string_table, 'DoesNotExist')

    def test_remove_entry_last_fails_gracefully(self):
        """Ensures remove_entry fails gracefully when removing the last entry.

        The Unreal StringTableLibrary does not support clearing all entries from a
        StringTable programmatically (import_table_from_csv_string ignores empty CSVs).
        The entry should remain after a failed removal.
        """
        with create_string_table() as string_table:
            StringTableTools.set_entry(string_table, 'TestKey', 'Hello World')
            StringTableTools.remove_entry(string_table, 'TestKey')  # fails gracefully
            self.assertIn('TestKey', StringTableTools.list_keys(string_table))

    def test_remove_entry_preserves_others(self):
        """Ensures remove_entry does not affect other entries."""
        with create_string_table() as string_table:
            StringTableTools.set_entry(string_table, 'KeyA', 'Value A')
            StringTableTools.set_entry(string_table, 'KeyB', 'Value B')
            StringTableTools.remove_entry(string_table, 'KeyA')
            self.assertNotIn('KeyA', StringTableTools.list_keys(string_table))
            self.assertIn('KeyB', StringTableTools.list_keys(string_table))
            self.assertEqual(StringTableTools.get_entry(string_table, 'KeyB'), 'Value B')

    def test_list_keys_reflects_additions(self):
        """Ensures list_keys count grows as entries are added."""
        with create_string_table() as string_table:
            StringTableTools.set_entry(string_table, 'Key1', 'Value 1')
            StringTableTools.set_entry(string_table, 'Key2', 'Value 2')
            keys = StringTableTools.list_keys(string_table)
            self.assertIn('Key1', keys)
            self.assertIn('Key2', keys)
            self.assertEqual(len(keys), 2)

    def test_import_file(self):
        """Ensures import_file populates a StringTable from a CSV's Key/SourceString rows."""
        csv_content = 'Key,SourceString\nGreeting,Hello\nFarewell,Goodbye\n'
        with create_temp_folder() as folder, tempfile.TemporaryDirectory() as tmp_dir:
            path = os.path.join(tmp_dir, 'strings.csv')
            with open(path, 'w') as f:
                f.write(csv_content)
            result = StringTableTools.import_file(folder, 'ImportedStrings', path)
            self.assertEqual(len(result), 1)
            table = result[0]
            self.assertIsInstance(table, unreal.StringTable)
            self.assertEqual(set(StringTableTools.list_keys(table)), {'Greeting', 'Farewell'})
            self.assertEqual(StringTableTools.get_entry(table, 'Greeting'), 'Hello')
            self.assertEqual(StringTableTools.get_entry(table, 'Farewell'), 'Goodbye')

    def test_import_file_unsupported_extension(self):
        """Ensures import_file rejects file extensions other than .csv."""
        with create_temp_folder() as folder, tempfile.TemporaryDirectory() as tmp_dir:
            path = os.path.join(tmp_dir, 'strings.json')
            with open(path, 'w') as f:
                f.write('{}')
            with self.assertToolRaisesRuntimeError():
                StringTableTools.import_file(folder, 'NotStrings', path)
