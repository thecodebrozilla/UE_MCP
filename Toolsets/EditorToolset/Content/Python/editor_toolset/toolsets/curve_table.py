# Copyright Epic Games, Inc. All Rights Reserved.

from __future__ import annotations

import unreal

import toolset_registry
from toolset_registry.helpers import asset_exists
from editor_toolset.toolsets.asset import import_asset

# [5.7 port] unreal.CurveTable *is* exposed on 5.7 (it is referenced by the
# reflected DataTableFunctionLibrary.evaluate_curve_table_row), so it is kept in
# the tool signatures. What is missing on 5.7 is:
#   * unreal.SimpleCurveKey - FSimpleCurveKey is USTRUCT() without BlueprintType and
#     is not referenced by any reflected signature, so it is not exposed. Key data
#     is therefore passed/returned as the CurveKey ustruct declared below (mirroring
#     5.8's Array-of-struct shape; an Array-of-Map / list[dict] is not a valid UE
#     reflected property type on 5.7).
#   * the 5.8 DataTableFunctionLibrary curve-editing helpers
#     (add_simple_curve_to_table, set_curve_table_row_default, remove_curve_table_row,
#      rename_curve_table_row, add_curve_table_key, get_curve_table_keys,
#      get_curve_table_row_names) - none exist on 5.7.
# All of the above are provided by the bundled BlueprintGraphEditorPort plugin's
# unreal.EditorToolsetCompatLibrary, which operates directly on the UCurveTable.
#
# Note: the shim is referenced inside method bodies (not at module scope) so this
# module still imports even if BlueprintGraphEditorPort is absent.


@unreal.ustruct()
class CurveKey(unreal.StructBase):
    """A single key (time/value pair) on a CurveTable row.

    [5.7 port] Stand-in for the 5.8-only unreal.SimpleCurveKey so the curve tools
    can take/return an Array-of-struct (which UE reflection supports on 5.7)
    instead of an Array-of-Map.
    """
    time = unreal.uproperty(float)
    value = unreal.uproperty(float)


@unreal.uclass()
class CurveTableTools(unreal.ToolsetDefinition):
    """Provides tools for creating and editing CurveTable assets."""

    @toolset_registry.tool_call
    @staticmethod
    def import_file(
            folder_path: str, asset_name: str, source_file: str,
            interp_mode: unreal.RichCurveInterpMode) -> list[unreal.Object]:
        """Imports a file from disk as a CurveTable asset.

        The file's first column is the row name; subsequent columns are sample
        times and values. interp_mode controls how the imported keys are
        interpolated between samples.

        Args:
            folder_path: The content-browser folder to create the asset in.
            asset_name: The name of the new asset.
            source_file: The absolute path to the source file on disk.
            interp_mode: Interpolation mode applied to every imported key.
                Must be RCIM_LINEAR or RCIM_CONSTANT.

        Returns:
            The assets produced by the import (typically a single CurveTable).
        """
        if interp_mode not in (
                unreal.RichCurveInterpMode.RCIM_LINEAR,
                unreal.RichCurveInterpMode.RCIM_CONSTANT):
            raise ValueError(
                f'interp_mode {interp_mode} is not supported. Use RCIM_LINEAR '
                f'or RCIM_CONSTANT; cubic interpolation produces a RichCurves '
                f'table that the rest of CurveTableTools cannot edit.')
        factory = unreal.CSVImportFactory()
        factory.automated_import_settings.import_type = unreal.CSVImportType.ECSV_CURVE_TABLE
        factory.automated_import_settings.import_curve_interp_mode = interp_mode
        return import_asset(folder_path, asset_name, source_file, factory=factory)

    @toolset_registry.tool_call
    @staticmethod
    def create(folder_path: str, asset_name: str) -> unreal.CurveTable:
        """Creates a new CurveTable asset.

        Args:
            folder_path: The path to the folder that will contain the asset.
            asset_name: The name of the asset.

        Returns:
            The created CurveTable.
        """
        # [5.7 port] unreal.CurveTableFactory is not exposed on 5.7; create the
        # asset natively (linear simple-curve mode) via the compat shim.
        if asset_exists(f'{folder_path}/{asset_name}'):
            raise RuntimeError(
                f'create_asset: {asset_name} at {folder_path} already exists')
        asset = unreal.EditorToolsetCompatLibrary.create_curve_table_asset(folder_path, asset_name)
        if not isinstance(asset, unreal.CurveTable):
            raise ValueError(f'Unable to create CurveTable in {folder_path}/{asset_name}')
        return asset

    @toolset_registry.tool_call
    @staticmethod
    def list_rows(curve_table: unreal.CurveTable) -> list[str]:
        """Lists the names of all rows in the curve table.

        Args:
            curve_table: The CurveTable to query.

        Returns:
            A list of row names.
        """
        return list(unreal.EditorToolsetCompatLibrary.curve_table_list_rows(curve_table))

    @toolset_registry.tool_call
    @staticmethod
    def add_row(curve_table: unreal.CurveTable, row_name: str, default_value: float | None = None) -> None:
        """Adds a new row to the curve table with an optional default value.

        Args:
            curve_table: The CurveTable to modify.
            row_name: The name for the new row.
            default_value: The default value returned when sampling outside the key range.
        """
        CurveTableTools._ensure_row_doesnt_exist(curve_table, row_name)
        if not unreal.EditorToolsetCompatLibrary.curve_table_add_row(curve_table, row_name):
            raise RuntimeError(f'Failed to add row "{row_name}" to the curve table.')
        if default_value is not None:
            unreal.EditorToolsetCompatLibrary.curve_table_set_row_default(curve_table, row_name, default_value)
        CurveTableTools._ensure_row_exists(curve_table, row_name)

    @toolset_registry.tool_call
    @staticmethod
    def remove_row(curve_table: unreal.CurveTable, row_name: str) -> None:
        """Removes a row from the curve table.

        Args:
            curve_table: The CurveTable to modify.
            row_name: The name of the row to remove.
        """
        CurveTableTools._ensure_row_exists(curve_table, row_name)
        unreal.EditorToolsetCompatLibrary.curve_table_remove_row(curve_table, row_name)
        CurveTableTools._ensure_row_doesnt_exist(curve_table, row_name)

    @toolset_registry.tool_call
    @staticmethod
    def rename_row(curve_table: unreal.CurveTable, row_name: str, new_row_name: str) -> None:
        """Renames a row in the curve table.

        Args:
            curve_table: The CurveTable to modify.
            row_name: The current name of the row.
            new_row_name: The new name for the row.
        """
        CurveTableTools._ensure_row_exists(curve_table, row_name)
        CurveTableTools._ensure_row_doesnt_exist(curve_table, new_row_name)
        unreal.EditorToolsetCompatLibrary.curve_table_rename_row(curve_table, row_name, new_row_name)
        CurveTableTools._ensure_row_doesnt_exist(curve_table, row_name)
        CurveTableTools._ensure_row_exists(curve_table, new_row_name)

    @toolset_registry.tool_call
    @staticmethod
    def add_key(curve_table: unreal.CurveTable, row_name: str, time: float, value: float) -> bool:
        """Adds a key to a row.

        Args:
            curve_table: The CurveTable to modify.
            row_name: The name of the row to modify.
            time: The time (X) of the key to add.
            value: The value (Y) of the key to add.

        Returns:
            True if the key was added successfully.
        """
        CurveTableTools._ensure_row_exists(curve_table, row_name)
        return unreal.EditorToolsetCompatLibrary.curve_table_add_key(curve_table, row_name, time, value)

    @toolset_registry.tool_call
    @staticmethod
    def set_keys(curve_table: unreal.CurveTable, row_name: str,
                 keys: list[CurveKey]) -> bool:
        """Replaces all keys in a row with the provided list.

        Args:
            curve_table: The CurveTable to modify.
            row_name: The name of the row to modify.
            keys: The keys to set in the row, each a CurveKey with `time` and
                `value` floats.

        Returns:
            True if all keys were set successfully.
        """
        CurveTableTools._ensure_row_exists(curve_table, row_name)
        times = [float(k.time) for k in keys]
        values = [float(k.value) for k in keys]
        return unreal.EditorToolsetCompatLibrary.curve_table_set_keys(curve_table, row_name, times, values)

    @toolset_registry.tool_call
    @staticmethod
    def get_keys(curve_table: unreal.CurveTable, row_name: str) -> list[CurveKey]:
        """Returns all keys for a row.

        Args:
            curve_table: The CurveTable to query.
            row_name: The name of the row to query.

        Returns:
            A list of CurveKey (time/value), one per key.
        """
        CurveTableTools._ensure_row_exists(curve_table, row_name)
        times = list(unreal.EditorToolsetCompatLibrary.curve_table_get_key_times(curve_table, row_name))
        values = list(unreal.EditorToolsetCompatLibrary.curve_table_get_key_values(curve_table, row_name))
        result = []
        for t, v in zip(times, values):
            key = CurveKey()
            key.time = t
            key.value = v
            result.append(key)
        return result

    @staticmethod
    def _ensure_row_exists(curve_table: unreal.CurveTable, row_name: str) -> None:
        if row_name not in CurveTableTools.list_rows(curve_table):
            raise ValueError(f'Row "{row_name}" does not exist in the curve table.')

    @staticmethod
    def _ensure_row_doesnt_exist(curve_table: unreal.CurveTable, row_name: str) -> None:
        if row_name in CurveTableTools.list_rows(curve_table):
            raise ValueError(f'Row "{row_name}" already exists in the curve table.')
