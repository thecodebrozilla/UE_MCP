# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry
from toolset_registry.helpers import create_asset
from editor_toolset.toolsets.asset import import_asset


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
        asset = create_asset(
            folder_path, asset_name, unreal.CurveTable.static_class(), unreal.CurveTableFactory())
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
        return unreal.DataTableFunctionLibrary.get_curve_table_row_names(curve_table)

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
        unreal.DataTableFunctionLibrary.add_simple_curve_to_table(curve_table, row_name)
        if default_value is not None:
            unreal.DataTableFunctionLibrary.set_curve_table_row_default(
                curve_table, row_name, default_value)
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
        unreal.DataTableFunctionLibrary.remove_curve_table_row(curve_table, row_name)
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
        unreal.DataTableFunctionLibrary.rename_curve_table_row(
            curve_table, row_name, new_row_name)
        CurveTableTools._ensure_row_doesnt_exist(curve_table, row_name)
        CurveTableTools._ensure_row_exists(curve_table, new_row_name)

    @toolset_registry.tool_call
    @staticmethod
    def add_key(curve_table: unreal.CurveTable, row_name: str, key: unreal.SimpleCurveKey) -> bool:
        """Adds a key to a row.

        Args:
            curve_table: The CurveTable to modify.
            row_name: The name of the row to modify.
            key: The key to add, containing the time and value.

        Returns:
            True if the key was added successfully.
        """
        CurveTableTools._ensure_row_exists(curve_table, row_name)
        return CurveTableTools._add_key(curve_table, row_name, key)

    @toolset_registry.tool_call
    @staticmethod
    def set_keys(curve_table: unreal.CurveTable, row_name: str,
                 keys: list[unreal.SimpleCurveKey]) -> bool:
        """Replaces all keys in a row with the provided list.

        Args:
            curve_table: The CurveTable to modify.
            row_name: The name of the row to modify.
            keys: The keys to set in the row.

        Returns:
            True if all keys were set successfully.
        """
        CurveTableTools._ensure_row_exists(curve_table, row_name)
        unreal.DataTableFunctionLibrary.remove_curve_table_row(curve_table, row_name)
        unreal.DataTableFunctionLibrary.add_simple_curve_to_table(curve_table, row_name)
        return all(CurveTableTools._add_key(curve_table, row_name, key) for key in keys)

    @toolset_registry.tool_call
    @staticmethod
    def get_keys(curve_table: unreal.CurveTable, row_name: str) -> list[unreal.SimpleCurveKey]:
        """Returns all keys for a row.

        Args:
            curve_table: The CurveTable to query.
            row_name: The name of the row to query.

        Returns:
            A list of SimpleCurveKey objects for the row.
        """
        CurveTableTools._ensure_row_exists(curve_table, row_name)
        return list(unreal.DataTableFunctionLibrary.get_curve_table_keys(curve_table, row_name))

    @staticmethod
    def _add_key(curve_table: unreal.CurveTable, row_name: str, key: unreal.SimpleCurveKey) -> bool:
        return unreal.DataTableFunctionLibrary.add_curve_table_key(
            curve_table, row_name,
            key.get_editor_property('time'), key.get_editor_property('value'))

    @staticmethod
    def _ensure_row_exists(curve_table: unreal.CurveTable, row_name: str) -> None:
        if row_name not in CurveTableTools.list_rows(curve_table):
            raise ValueError(f'Row "{row_name}" does not exist in the curve table.')

    @staticmethod
    def _ensure_row_doesnt_exist(curve_table: unreal.CurveTable, row_name: str) -> None:
        if row_name in CurveTableTools.list_rows(curve_table):
            raise ValueError(f'Row "{row_name}" already exists in the curve table.')
