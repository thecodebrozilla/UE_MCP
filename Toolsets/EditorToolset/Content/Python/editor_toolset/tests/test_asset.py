# Copyright Epic Games, Inc. All Rights Reserved.

from contextlib import ExitStack
import os
import tempfile
import unittest
from unittest import mock
import unreal

import toolset_registry
from toolset_registry.tests.automation import AUTOMATION_MOUNT_POINT, create_temp_folder
from editor_toolset.toolsets.asset import AssetTools
from editor_toolset.toolsets.data_asset import DataAssetTools


class AssetToolsTestCase(unittest.TestCase):
    """Test AssetTools toolset."""

    def test_create_folder(self):
        """Ensures we can create and delete a folder"""
        with create_temp_folder() as test_folder:
            folder_name = f'{test_folder}test/'
            self.assertTrue(AssetTools.create_folder(folder_name))
            self.assertTrue(AssetTools.exists(folder_name))

    def test_list_folders(self):
        """Ensures that we can list folders"""
        with create_temp_folder() as test_folder:
            folder_name = f'{test_folder}test/'
            AssetTools.create_folder(folder_name)
            subfolder_name = f'{folder_name}sub/'
            AssetTools.create_folder(subfolder_name)
            folders = AssetTools.list_folders(test_folder)
            self.assertSequenceEqual(folders, [folder_name, subfolder_name])

    def test_duplicate_folder(self):
        """Ensures that we can duplicate folders"""
        with create_temp_folder() as test_folder:
            folder_name = f'{test_folder}test/'
            AssetTools.create_folder(folder_name)
            subfolder_name = f'{folder_name}sub/'
            AssetTools.create_folder(subfolder_name)
            DataAssetTools.create(subfolder_name, 'test', unreal.InputAction.static_class())

            dupe_name = f'{test_folder}dupe/'
            self.assertTrue(AssetTools.duplicate(folder_name, dupe_name))
            folders = AssetTools.list_folders(dupe_name)
            self.assertEqual(list(folders), [f'{dupe_name}sub/'])
            self.assertTrue(AssetTools.exists(f'{dupe_name}sub/test'))

    def test_duplicate_asset(self):
        """Ensures that we can duplicate assets"""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(test_folder, 'test', unreal.InputAction.static_class())
            self.assertTrue(AssetTools.duplicate(f'{test_folder}test', f'{test_folder}dupe'))
            self.assertTrue(AssetTools.exists(f'{test_folder}dupe'))

    def test_move_folder(self):
        """Ensures that we can move folders"""
        with create_temp_folder() as test_folder:
            folder_name = f'{test_folder}test/'
            AssetTools.create_folder(folder_name)
            new_name = f'{test_folder}new_test/'
            self.assertTrue(AssetTools.move(folder_name, new_name))

            folders = AssetTools.list_folders(test_folder)
            self.assertEqual(list(folders), [new_name])

    def test_move_asset(self):
        """Ensures that we can move assets"""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(test_folder, 'test', unreal.InputAction.static_class())
            new_name = f'{test_folder}new_test'
            self.assertTrue(AssetTools.move(f'{test_folder}test', new_name))
            self.assertTrue(AssetTools.exists(new_name))

    def test_delete_folder(self):
        """Ensures we can create and delete a folder"""
        with create_temp_folder() as test_folder:
            folder_name = f'{test_folder}test/'
            self.assertTrue(AssetTools.create_folder(folder_name))
            self.assertTrue(AssetTools.exists(folder_name))
            self.assertTrue(AssetTools.delete(folder_name))
            eas = unreal.get_editor_subsystem(unreal.EditorAssetSubsystem)
            assert eas
            self.assertFalse(eas.does_directory_exist(folder_name))

    def test_delete_asset(self):
        """Ensures that we can delete assets"""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            self.assertTrue(AssetTools.exists(asset_path))
            self.assertTrue(AssetTools.delete(asset_path))
            self.assertFalse(AssetTools.exists(asset_path))

    def test_load_asset(self):
        """Ensures that we can load assets"""
        with create_temp_folder() as test_folder:
            asset = DataAssetTools.create(test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            loaded_asset = AssetTools.load_asset(asset_path)
            self.assertEqual(asset, loaded_asset)

    def test_save_assets(self):
        """Ensures that we can save an asset"""
        with create_temp_folder() as test_folder:
            asset = DataAssetTools.create(test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            eas = unreal.get_editor_subsystem(unreal.EditorAssetSubsystem)
            assert eas
            eas.set_dirty_flag(asset, True)
            self.assertTrue(AssetTools.save_assets([asset_path]))
            self.assertFalse(AssetTools.is_dirty(asset_path))
            automation_dir = unreal.Paths.convert_relative_path_to_full(
                unreal.Paths.automation_transient_dir())
            relative_path = asset_path.removeprefix(AUTOMATION_MOUNT_POINT)
            self.assertTrue(os.path.exists(os.path.join(automation_dir, f'{relative_path}.uasset')))

    def test_save_assets_empty_saves_all_dirty(self):
        """Ensures that passing an empty list saves all dirty assets"""
        with create_temp_folder() as test_folder:
            asset = DataAssetTools.create(test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            eas = unreal.get_editor_subsystem(unreal.EditorAssetSubsystem)
            assert eas
            eas.set_dirty_flag(asset, True)
            self.assertTrue(AssetTools.is_dirty(asset_path))
            self.assertTrue(AssetTools.save_assets([]))
            self.assertFalse(AssetTools.is_dirty(asset_path))

    def test_is_dirty(self):
        """Ensures that we can check if an asset has unsaved changes"""
        with create_temp_folder() as test_folder:
            asset = DataAssetTools.create(test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            eas = unreal.get_editor_subsystem(unreal.EditorAssetSubsystem)
            assert eas
            AssetTools.save_assets([asset_path])
            self.assertFalse(AssetTools.is_dirty(asset_path))
            eas.set_dirty_flag(asset, True)
            self.assertTrue(AssetTools.is_dirty(asset_path))
            AssetTools.save_assets([asset_path])   # save again to make sure the dirty flag is cleared
            self.assertFalse(AssetTools.is_dirty(asset_path))  # ensure the dirty flag has been cleared

    def test_is_dirty_never_saved(self):
        """Ensures that is_dirty returns True for an asset that exists only in memory."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(test_folder, 'original', unreal.InputAction.static_class())
            original_path = f'{test_folder}original'
            AssetTools.save_assets([original_path])
            # Duplicate produces an in-memory asset with no backing file on disk.
            dupe_path = f'{test_folder}dupe'
            self.assertTrue(AssetTools.duplicate(original_path, dupe_path))
            # Original is clean, but dupe is dirty (never saved).
            self.assertFalse(AssetTools.is_dirty(original_path))
            self.assertTrue(AssetTools.is_dirty(dupe_path))
            # Dupe is clean after saving.
            AssetTools.save_assets([dupe_path])
            self.assertFalse(AssetTools.is_dirty(dupe_path))

    def test_find_assets_empty_folder_searches_whole_project(self):
        """Ensures find_assets('') returns the union of /Game/ and all plugin
        content folders, including engine plugins."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            expected = set(AssetTools.find_assets('/Game/'))
            for plugin_path in AssetTools.get_plugin_content_paths(include_engine=True):
                expected.update(AssetTools.find_assets(plugin_path))
            results = set(AssetTools.find_assets(''))
            self.assertEqual(results, expected)

    def test_get_plugin_content_paths_include_engine_is_strict_superset(self):
        """include_engine=True must add engine plugin paths on top of the
        default project-plugin set."""
        project = set(AssetTools.get_plugin_content_paths())
        all_plugins = set(AssetTools.get_plugin_content_paths(include_engine=True))
        self.assertTrue(project.issubset(all_plugins))
        self.assertGreater(len(all_plugins), len(project),
                           f'expected engine plugins to add at least one path; '
                           f'project={project}, all={all_plugins}')

    def test_find_assets_native_type_filter(self):
        """Ensures find_assets returns native (non-Blueprint) assets when asset_type is set."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(test_folder, 'MyAction', unreal.InputAction.static_class())
            asset_path = f'{test_folder}MyAction'
            results = AssetTools.find_assets(test_folder, asset_type=unreal.InputAction.static_class())
            self.assertIn(asset_path, results)

    def test_find_assets_name_filter(self):
        """Ensures find_assets filters by case-insensitive name substring when name is set."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(test_folder, 'MyAction', unreal.InputAction.static_class())
            DataAssetTools.create(test_folder, 'OtherAsset', unreal.InputAction.static_class())
            results = AssetTools.find_assets(test_folder, name='action')
            self.assertIn(f'{test_folder}MyAction', results)
            self.assertNotIn(f'{test_folder}OtherAsset', results)

    def test_find_assets_returns_package_paths(self):
        """Ensures find_assets returns clean package paths without a .ObjectName suffix."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(test_folder, 'test', unreal.InputAction.static_class())
            results = AssetTools.find_assets(test_folder)
            self.assertEqual(results, [f'{test_folder}test'])

    def test_to_package_path(self):
        """_to_package_path normalizes full object paths to package paths."""
        cases = [
            ('/Game/Foo/Bar.Bar', '/Game/Foo/Bar'),
            ('/Game/Foo/Bar', '/Game/Foo/Bar'),
            ('/Script/Engine.InputAction', '/Script/Engine'),
        ]
        for input_path, expected in cases:
            with self.subTest(input_path=input_path):
                self.assertEqual(
                    AssetTools._to_package_path(input_path), expected)

    def test_can_edit_asset(self):
        """A locally created asset should be editable."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(
                test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            self.assertTrue(AssetTools.can_edit_asset(asset_path))

    def test_can_edit_asset_accepts_full_object_path(self):
        """can_edit_asset normalizes full object paths via _to_package_path."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(
                test_folder, 'test', unreal.InputAction.static_class())
            full_object_path = f'{test_folder}test.test'
            self.assertTrue(AssetTools.can_edit_asset(full_object_path))

    def test_can_edit_asset_nonexistent_raises(self):
        """can_edit_asset raises for a non-existent asset."""
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaises(RuntimeError):
                AssetTools.can_edit_asset('/Game/DoesNotExist/Fake')

    def test_is_checked_out_false_for_new_asset(self):
        """A locally created asset should not be checked out when source control is not enabled."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(
                test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            self.assertFalse(AssetTools.is_checked_out(asset_path))

    def test_is_checked_out_true_when_checked_out_by_me(self):
        """is_checked_out returns True when the asset is checked out by the current user."""
        mock_state = mock.MagicMock()
        mock_state.is_checked_out = True
        with create_temp_folder() as test_folder:
            DataAssetTools.create(
                test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            with mock.patch.object(AssetTools, '_sc_state', return_value=mock_state):
                self.assertTrue(AssetTools.is_checked_out(asset_path))

    def test_can_edit_asset_false_when_checked_out_by_other(self):
        """can_edit_asset returns False when the asset is checked out by another user."""
        mock_state = mock.MagicMock()
        mock_state.is_checked_out_other = True
        with create_temp_folder() as test_folder:
            DataAssetTools.create(
                test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            with mock.patch.object(AssetTools, '_sc_state', return_value=mock_state):
                self.assertFalse(AssetTools.can_edit_asset(asset_path))

    def test_is_checked_out_nonexistent_raises(self):
        """is_checked_out raises for a non-existent asset."""
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaises(RuntimeError):
                AssetTools.is_checked_out('/Game/DoesNotExist/Fake')

    def test_get_referencers_empty_for_new_asset(self):
        """A freshly created asset (full object path) should have no referencers."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(
                test_folder, 'test', unreal.InputAction.static_class())
            full_object_path = f'{test_folder}test.test'
            referencers = AssetTools.get_referencers(full_object_path)
            self.assertEqual(len(referencers), 0)

    def test_get_dependencies_empty_for_new_asset(self):
        """A freshly created unsaved asset (full object path) should have no dependencies."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(
                test_folder, 'test', unreal.InputAction.static_class())
            full_object_path = f'{test_folder}test.test'
            dependencies = AssetTools.get_dependencies(full_object_path)
            self.assertEqual(len(dependencies), 0)

    def test_get_referencers_nonexistent_asset_raises(self):
        """get_referencers raises for a non-existent asset."""
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaises(RuntimeError):
                AssetTools.get_referencers('/Game/DoesNotExist/Fake')

    def test_get_dependencies_nonexistent_asset_raises(self):
        """get_dependencies raises for a non-existent asset."""
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaises(RuntimeError):
                AssetTools.get_dependencies('/Game/DoesNotExist/Fake')

    def test_find_assets_tag_filter(self):
        """find_assets tags includes DataTable (has RowStruct) and excludes plain DataAssets."""
        with create_temp_folder() as test_folder:
            factory = unreal.DataTableFactory()
            factory.set_editor_property('struct', unreal.TableRowBase.static_struct())
            dt = unreal.AssetToolsHelpers.get_asset_tools().create_asset(
                'TestTable', test_folder, unreal.DataTable, factory)
            assert dt
            DataAssetTools.create(test_folder, 'TestAction', unreal.InputAction.static_class())
            dt_path = f'{test_folder}TestTable'
            action_path = f'{test_folder}TestAction'
            AssetTools.save_assets([dt_path, action_path])
            ar = unreal.AssetRegistryHelpers.get_asset_registry()
            ar.scan_paths_synchronous([test_folder], True)
            dt_tags = AssetTools.get_asset_tags(dt_path)
            action_tags = AssetTools.get_asset_tags(action_path)
            exclusive_tag = next(k for k in dt_tags if k not in action_tags)
            tag_value = dt_tags[exclusive_tag]
            self.assertIn(dt_path, AssetTools.find_assets(
                test_folder, tags={exclusive_tag: tag_value}))
            self.assertNotIn(action_path, AssetTools.find_assets(
                test_folder, tags={exclusive_tag: tag_value}))
            self.assertNotIn(dt_path, AssetTools.find_assets(
                test_folder, tags={exclusive_tag: tag_value + '_wrong'}))

    def test_get_asset_tags(self):
        """get_asset_tags returns RowStruct registry tag for a DataTable without loading it."""
        with create_temp_folder() as test_folder:
            factory = unreal.DataTableFactory()
            factory.set_editor_property('struct', unreal.TableRowBase.static_struct())
            dt = unreal.AssetToolsHelpers.get_asset_tools().create_asset(
                'TestTable', test_folder, unreal.DataTable, factory)
            assert dt
            dt_path = f'{test_folder}TestTable'
            AssetTools.save_assets([dt_path])
            unreal.AssetRegistryHelpers.get_asset_registry().scan_paths_synchronous(
                [test_folder], True)
            tags = AssetTools.get_asset_tags(dt_path)
            self.assertIn('RowStructure', tags)

    def test_get_asset_tags_nonexistent_raises(self):
        """get_asset_tags raises for a non-existent asset."""
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaises(RuntimeError):
                AssetTools.get_asset_tags('/Game/DoesNotExist/Fake')

    def test_get_asset_class_native_asset(self):
        """get_asset_class returns the native class name for non-Blueprint assets."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            self.assertEqual(AssetTools.get_asset_class(asset_path), 'InputAction')

    def test_get_asset_class_blueprint(self):
        """get_asset_class returns the generated class name (asset_name + '_C') for Blueprint assets."""
        with create_temp_folder() as test_folder:
            factory = unreal.BlueprintFactory()
            factory.set_editor_property('parent_class', unreal.Actor.static_class())
            bp = unreal.AssetToolsHelpers.get_asset_tools().create_asset(
                'TestBP', test_folder, unreal.Blueprint, factory)
            assert bp
            bp_path = f'{test_folder}TestBP'
            AssetTools.save_assets([bp_path])
            unreal.AssetRegistryHelpers.get_asset_registry().scan_paths_synchronous(
                [test_folder], True)
            self.assertEqual(AssetTools.get_asset_class(bp_path), 'TestBP_C')

    def test_get_asset_class_nonexistent_raises(self):
        """get_asset_class raises for a non-existent asset."""
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaises(RuntimeError):
                AssetTools.get_asset_class('/Game/DoesNotExist/Fake')

    def test_update_metadata_tags_set_and_get(self):
        """update_metadata_tags sets tags that get_metadata_tags returns."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            AssetTools.update_metadata_tags(asset_path, set_tags={'TagA': 'value_a', 'TagB': 'value_b'})
            tags = AssetTools.get_metadata_tags(asset_path)
            self.assertEqual(tags['TagA'], 'value_a')
            self.assertEqual(tags['TagB'], 'value_b')

    def test_update_metadata_tags_remove(self):
        """update_metadata_tags removes specified tags; removing a missing tag is a no-op."""
        with create_temp_folder() as test_folder:
            DataAssetTools.create(test_folder, 'test', unreal.InputAction.static_class())
            asset_path = f'{test_folder}test'
            AssetTools.update_metadata_tags(asset_path, set_tags={'TagA': 'value_a', 'TagB': 'value_b'})
            AssetTools.update_metadata_tags(asset_path, remove_tags=['TagA', 'TagC'])
            tags = AssetTools.get_metadata_tags(asset_path)
            self.assertNotIn('TagA', tags)
            self.assertIn('TagB', tags)

    def test_get_metadata_tags_nonexistent_raises(self):
        """get_metadata_tags raises for a non-existent asset."""
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaises(RuntimeError):
                AssetTools.get_metadata_tags('/Game/DoesNotExist/Fake')

    def test_update_metadata_tags_nonexistent_raises(self):
        """update_metadata_tags raises for a non-existent asset."""
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaises(RuntimeError):
                AssetTools.update_metadata_tags('/Game/DoesNotExist/Fake', set_tags={'MyTag': 'value'})

    def test_referencers_and_dependencies_are_consistent(self):
        """Verify both directions of an InputMappingContext -> InputAction relationship."""
        with create_temp_folder() as test_folder:
            action = DataAssetTools.create(
                test_folder, 'TestAction', unreal.InputAction.static_class())
            ctx = DataAssetTools.create(
                test_folder, 'TestCtx', unreal.InputMappingContext.static_class())

            mapping = unreal.EnhancedActionKeyMapping()
            mapping.set_editor_property('action', action)
            mapping_data = unreal.InputMappingContextMappingData()
            mapping_data.set_editor_property('mappings', [mapping])
            ctx.set_editor_property('default_key_mappings', mapping_data)

            action_path = f'{test_folder}TestAction'
            ctx_path = f'{test_folder}TestCtx'
            AssetTools.save_assets([action_path, ctx_path])
            registry = unreal.AssetRegistryHelpers.get_asset_registry()
            registry.scan_paths_synchronous([test_folder], True)

            referencers = AssetTools.get_referencers(action_path)
            self.assertIn(
                ctx_path, referencers,
                f'{ctx_path} not in referencers: {referencers}')

            dependencies = AssetTools.get_dependencies(ctx_path)
            self.assertIn(
                action_path, dependencies,
                f'{action_path} not in dependencies: {dependencies}')


class FileToolsTestCase(unittest.TestCase):
    """Test file read/write methods on AssetTools."""

    def setUp(self):
        self._exit_stack = ExitStack()
        self.addCleanup(self._exit_stack.close)
        project_saved_dir = unreal.Paths.convert_relative_path_to_full(
            unreal.Paths.project_saved_dir())
        self._tmpdir = self._exit_stack.enter_context(
            tempfile.TemporaryDirectory(dir=project_saved_dir))

    def test_read_file(self):
        """Ensures we can read text content from a file within the project directory."""
        path = os.path.join(self._tmpdir, 'hello.txt')
        with open(path, 'w', encoding='utf-8') as f:
            f.write('hello world')
        self.assertEqual(AssetTools.read_file(path), 'hello world')

    def test_read_file_not_found(self):
        """Ensures read_file raises when the file does not exist."""
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaisesRegex(RuntimeError, 'FileNotFoundError'):
                AssetTools.read_file(os.path.join(self._tmpdir, 'missing.txt'))

    def test_read_file_outside_project(self):
        """Ensures read_file raises for paths outside the project directory."""
        outside_path = os.path.join(tempfile.gettempdir(), 'outside.txt')
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaisesRegex(RuntimeError, 'ValueError'):
                AssetTools.read_file(outside_path)

    def test_write_file_txt(self):
        """Ensures we can write a plain text file within the project directory."""
        path = os.path.join(self._tmpdir, 'out.txt')
        AssetTools.write_file(path, 'some text')
        with open(path, encoding='utf-8') as f:
            self.assertEqual(f.read(), 'some text')

    def test_write_file_json(self):
        """Ensures we can write a JSON file."""
        path = os.path.join(self._tmpdir, 'data.json')
        content = '{"key": "value"}'
        AssetTools.write_file(path, content)
        with open(path, encoding='utf-8') as f:
            self.assertEqual(f.read(), content)

    def test_write_file_csv(self):
        """Ensures we can write a CSV file."""
        path = os.path.join(self._tmpdir, 'data.csv')
        content = 'a,b,c\n1,2,3\n'
        AssetTools.write_file(path, content)
        with open(path, encoding='utf-8') as f:
            self.assertEqual(f.read(), content)

    def test_write_file_html(self):
        """Ensures we can write an HTML file."""
        path = os.path.join(self._tmpdir, 'page.html')
        content = '<html><body>hello</body></html>'
        AssetTools.write_file(path, content)
        with open(path, encoding='utf-8') as f:
            self.assertEqual(f.read(), content)

    def test_write_file_py(self):
        """Ensures we can write a Python file."""
        path = os.path.join(self._tmpdir, 'script.py')
        content = 'print("hello")\n'
        AssetTools.write_file(path, content)
        with open(path, encoding='utf-8') as f:
            self.assertEqual(f.read(), content)

    def test_write_file_unsupported_extension(self):
        """Ensures write_file raises for disallowed extensions."""
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaisesRegex(RuntimeError, 'ValueError'):
                AssetTools.write_file(os.path.join(self._tmpdir, 'binary.exe'), 'data')

    def test_write_file_creates_directories(self):
        """Ensures write_file creates intermediate directories as needed."""
        path = os.path.join(self._tmpdir, 'subdir', 'nested', 'out.txt')
        AssetTools.write_file(path, 'text')
        self.assertTrue(os.path.exists(path))

    def test_write_file_outside_project(self):
        """Ensures write_file raises for paths outside the project directory."""
        outside_path = os.path.join(tempfile.gettempdir(), 'outside.txt')
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaisesRegex(RuntimeError, 'ValueError'):
                AssetTools.write_file(outside_path, 'data')

    def test_read_file_unsupported_extension(self):
        """Ensures read_file raises for disallowed extensions."""
        path = os.path.join(self._tmpdir, 'binary.exe')
        with open(path, 'w', encoding='utf-8') as f:
            f.write('data')
        with toolset_registry.tool_raising_exceptions():
            with self.assertRaisesRegex(RuntimeError, 'ValueError'):
                AssetTools.read_file(path)

    def test_write_file_read_only_checkout_fails(self):
        """Ensures write_file raises when file is read-only and checkout fails."""
        path = os.path.join(self._tmpdir, 'locked.txt')
        with open(path, 'w', encoding='utf-8') as f:
            f.write('original')
        os.chmod(path, 0o444)
        self.addCleanup(os.chmod, path, 0o644)
        with (mock.patch.object(AssetTools, '_check_out_file', return_value=False),
              toolset_registry.tool_raising_exceptions(),
              self.assertRaisesRegex(RuntimeError, 'could not be checked out')):
            AssetTools.write_file(path, 'new content')

    def test_read_file_too_large(self):
        """Ensures read_file raises when the file exceeds _MAX_READ_FILE_BYTES."""
        path = os.path.join(self._tmpdir, 'large.txt')
        with open(path, 'w', encoding='utf-8') as f:
            f.write('x' * 20)
        with toolset_registry.tool_raising_exceptions():
            with mock.patch.object(AssetTools, '_MAX_READ_FILE_BYTES', 10):
                with self.assertRaisesRegex(RuntimeError, 'ValueError'):
                    AssetTools.read_file(path)

    def test_round_trip_file_in_project_content(self):
        """Confirms write then read works under the project Content/ directory (/Game/)."""
        parent = unreal.Paths.convert_relative_path_to_full(unreal.Paths.project_content_dir())
        tmpdir = self._exit_stack.enter_context(tempfile.TemporaryDirectory(dir=parent))
        path = os.path.join(tmpdir, 'roundtrip.txt')
        AssetTools.write_file(path, 'game content')
        self.assertEqual(AssetTools.read_file(path), 'game content')

    def test_round_trip_file_in_engine_plugin(self):
        """Confirms write then read works under an engine plugin's Content/ directory."""
        engine_plugins_dir = os.path.normcase(unreal.Paths.normalize_directory_name(
            unreal.Paths.convert_relative_path_to_full(unreal.Paths.engine_plugins_dir())))
        engine_plugin_content = None
        for full_base, _ in AssetTools._iter_content_plugin_base_dirs(include_engine=True):
            if not os.path.normcase(full_base).startswith(engine_plugins_dir):
                continue
            candidate = os.path.join(full_base, 'Content')
            if os.path.isdir(candidate):
                engine_plugin_content = candidate
                break
        if not engine_plugin_content:
            self.skipTest('No enabled engine plugin with a Content/ directory was found.')
        tmpdir = self._exit_stack.enter_context(
            tempfile.TemporaryDirectory(dir=engine_plugin_content))
        path = os.path.join(tmpdir, 'roundtrip.txt')
        AssetTools.write_file(path, 'engine plugin content')
        self.assertEqual(AssetTools.read_file(path), 'engine plugin content')

    def test_round_trip_file_in_saved(self):
        """Confirms write then read works under the project Saved/ directory."""
        path = os.path.join(self._tmpdir, 'roundtrip.txt')
        AssetTools.write_file(path, 'saved data')
        self.assertEqual(AssetTools.read_file(path), 'saved data')

    def test_reject_sensitive_paths(self):
        """Ensures read_file and write_file reject paths in sensitive non-content
        directories (project Source/, Config/, Intermediate/, and the engine tree)."""
        project_dir = unreal.Paths.convert_relative_path_to_full(unreal.Paths.project_dir())
        engine_dir = unreal.Paths.convert_relative_path_to_full(unreal.Paths.engine_dir())
        forbidden = [
            os.path.join(project_dir, 'Source', 'leak.txt'),
            os.path.join(project_dir, 'Config', 'leak.txt'),
            os.path.join(project_dir, 'Intermediate', 'leak.txt'),
            os.path.join(engine_dir, 'Source', 'leak.txt'),
        ]
        for path in forbidden:
            with self.subTest(path=path):
                with toolset_registry.tool_raising_exceptions():
                    with self.assertRaisesRegex(RuntimeError, 'ValueError'):
                        AssetTools.read_file(path)
                    with self.assertRaisesRegex(RuntimeError, 'ValueError'):
                        AssetTools.write_file(path, 'data')
