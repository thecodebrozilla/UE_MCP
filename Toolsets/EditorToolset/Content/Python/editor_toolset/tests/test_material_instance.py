# Copyright Epic Games, Inc. All Rights Reserved.

import contextlib
from contextlib import ExitStack
from typing import Iterator
import unittest

import unreal

from toolset_registry.tests.automation import create_temp_folder
from editor_toolset.tests.test_material import create_material_with_params
from editor_toolset.toolsets.material import MaterialTools
from editor_toolset.toolsets.material_instance import (
    MaterialInstanceTools, MaterialParameter, MaterialParameterType)


@contextlib.contextmanager
def create_test_instance() -> Iterator[unreal.MaterialInstance]:
    """Creates a temp folder, a material with parameters, and an instance of it."""
    with create_temp_folder() as folder:
        mat = create_material_with_params(folder, 'Mat')
        yield MaterialInstanceTools.create(folder, 'MatInst', mat)


@contextlib.contextmanager
def create_test_instance_with_all_params() -> Iterator[unreal.MaterialInstanceConstant]:
    """Creates an instance whose parent has Scalar, Vector, Texture, and StaticSwitch params."""
    with create_temp_folder() as folder:
        mat = create_material_with_params(folder, 'Mat')

        tex_param = MaterialTools.add_expression(
            mat, unreal.MaterialExpressionTextureObjectParameter.static_class(), x=-400, y=200)
        tex_param.set_editor_property('parameter_name', 'TestTexture')

        switch_param = MaterialTools.add_expression(
            mat, unreal.MaterialExpressionStaticSwitchParameter.static_class(), x=-400, y=300)
        switch_param.set_editor_property('parameter_name', 'TestSwitch')

        MaterialTools.recompile(mat)
        yield MaterialInstanceTools.create(folder, 'MatInst', mat)


class MaterialInstanceToolsTestCase(unittest.TestCase):
    """Test MaterialInstanceTools toolset."""

    # -------------------------------------------------------------------------
    # Asset creation
    # -------------------------------------------------------------------------

    def test_create(self):
        """Ensures that we can create a MaterialInstanceConstant with the correct parent."""
        with create_test_instance() as instance:
            self.assertIsInstance(instance, unreal.MaterialInstanceConstant)
            self.assertIsInstance(instance.get_base_material(), unreal.Material)

    # -------------------------------------------------------------------------
    # Parameter discovery
    # -------------------------------------------------------------------------

    def test_list_parameters(self):
        """Ensures that list_parameters returns all parameters with correct names and types."""
        with create_test_instance() as instance:
            params = MaterialInstanceTools.list_parameters(instance.get_base_material())
            self.assertTrue(all(isinstance(p, MaterialParameter) for p in params))
            by_name = {p.name: p.type for p in params}
            self.assertEqual(by_name.get('TestScalar'), MaterialParameterType.Scalar)
            self.assertEqual(by_name.get('TestVector'), MaterialParameterType.Vector)

    # -------------------------------------------------------------------------
    # Parameter access
    # -------------------------------------------------------------------------

    def test_get_parameter_wrong_type_raises(self):
        """Ensures that getting a parameter with the wrong type raises a ValueError."""
        with create_test_instance() as instance:
            with self.assertRaises(ValueError):
                MaterialInstanceTools._get_parameter(
                    instance, 'TestScalar', MaterialParameterType.Vector)

    def test_get_nonexistent_parameter_raises(self):
        """Ensures that getting a parameter that does not exist raises a ValueError."""
        with create_test_instance() as instance:
            with self.assertRaises(ValueError):
                MaterialInstanceTools._get_parameter(
                    instance, 'DoesNotExist', MaterialParameterType.Scalar)

    def test_set_parameter_wrong_type_raises(self):
        """Ensures that setting a parameter with the wrong type raises a ValueError."""
        with create_test_instance() as instance:
            with self.assertRaises(ValueError):
                MaterialInstanceTools._set_parameter(
                    instance, 'TestScalar', MaterialParameterType.Vector,
                    unreal.LinearColor(r=1, g=0, b=0, a=1))

    def test_set_nonexistent_parameter_raises(self):
        """Ensures that setting a parameter that does not exist raises a ValueError."""
        with create_test_instance() as instance:
            with self.assertRaises(ValueError):
                MaterialInstanceTools._set_parameter(
                    instance, 'DoesNotExist', MaterialParameterType.Scalar, 1.0)

    def test_set_and_get_scalar_parameter(self):
        """Ensures that a scalar parameter can be written to and read back."""
        with create_test_instance() as instance:
            MaterialInstanceTools.set_scalar_parameter(instance, 'TestScalar', 0.75)
            self.assertEqual(
                MaterialInstanceTools.get_scalar_parameter(instance, 'TestScalar'), 0.75)

    def test_set_and_get_vector_parameter(self):
        """Ensures that a vector parameter can be written to and read back."""
        with create_test_instance() as instance:
            color = unreal.LinearColor(r=0.1, g=0.2, b=0.3, a=1.0)
            MaterialInstanceTools.set_vector_parameter(instance, 'TestVector', color)
            result = MaterialInstanceTools.get_vector_parameter(instance, 'TestVector')
            self.assertAlmostEqual(result.r, 0.1, places=5)
            self.assertAlmostEqual(result.g, 0.2, places=5)
            self.assertAlmostEqual(result.b, 0.3, places=5)

    # -------------------------------------------------------------------------
    # Instance management
    # -------------------------------------------------------------------------

    def test_set_parent(self):
        """Ensures that the parent of a material instance can be changed."""
        with create_temp_folder() as folder:
            mat_a = create_material_with_params(folder, 'MatA')
            mat_b = create_material_with_params(folder, 'MatB')
            instance = MaterialInstanceTools.create(folder, 'Inst', mat_a)
            MaterialInstanceTools.set_parent(instance, mat_b)
            self.assertEqual(instance.parent, mat_b)

    def test_clear_parameters(self):
        """Ensures that clear_parameters removes all instance overrides."""
        with create_test_instance() as instance:
            MaterialInstanceTools.set_scalar_parameter(instance, 'TestScalar', 0.99)
            MaterialInstanceTools.clear_parameters(instance)
            scalar_overrides = instance.get_editor_property('scalar_parameter_values')
            self.assertEqual(len(scalar_overrides), 0)


class MaterialInstanceWithAllParamsTestCase(unittest.TestCase):
    """Tests requiring a material instance with Texture and StaticSwitch parameters."""

    def setUp(self):
        super().setUp()
        self._stack = ExitStack()
        folder = self._stack.enter_context(create_temp_folder())
        mat = create_material_with_params(folder, 'Mat')

        tex_param = MaterialTools.add_expression(
            mat, unreal.MaterialExpressionTextureObjectParameter.static_class(), x=-400, y=200)
        tex_param.set_editor_property('parameter_name', 'TestTexture')

        switch_param = MaterialTools.add_expression(
            mat, unreal.MaterialExpressionStaticSwitchParameter.static_class(), x=-400, y=300)
        switch_param.set_editor_property('parameter_name', 'TestSwitch')

        MaterialTools.recompile(mat)
        self.instance = MaterialInstanceTools.create(folder, 'MatInst', mat)

    def tearDown(self):
        # delete_directory triggers GC; an instance whose static permutation is
        # still compiling on a worker thread will assert in FMaterial::~FMaterial.
        # Block until every compile job and its render-thread followup has drained.
        unreal.AutomationUtilsBlueprintLibrary.finish_all_asset_compilation()
        self.instance = None
        self._stack.close()
        super().tearDown()

    def test_set_and_get_texture_parameter(self):
        """Ensures that a texture parameter can be written to and read back."""
        texture = unreal.load_asset('/Engine/EngineMaterials/DefaultDiffuse')
        MaterialInstanceTools.set_texture_parameter(self.instance, 'TestTexture', texture)
        result = MaterialInstanceTools.get_texture_parameter(self.instance, 'TestTexture')
        self.assertEqual(result, texture)

    def test_set_and_get_static_switch_parameter(self):
        """Ensures that a static switch parameter can be written to and read back."""
        MaterialInstanceTools.set_static_switch_parameter(self.instance, 'TestSwitch', True)
        result = MaterialInstanceTools.get_static_switch_parameter(self.instance, 'TestSwitch')
        self.assertTrue(result)
