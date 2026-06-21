# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

from toolset_registry.tests.toolset_testcase import ToolCallTestCase
from editor_toolset.tests.test_scene import create_actor
from editor_toolset.toolsets.primitive import PrimitiveTools


class PrimitiveToolsTestCase(ToolCallTestCase):
    """Test PrimitiveTools toolset."""

    def test_add_cube(self):
        """Ensures a cube is added with the correct name, type, transform, and bounds.

        The dimensions and transform scale are combined multiplicatively.
        """
        with create_actor() as test_actor:
            xform = unreal.Transform(unreal.Vector(10, 20, 30), unreal.Rotator(0, 0, 0),
                                     unreal.Vector(1, 1, 1))
            component = PrimitiveTools.add_cube(test_actor, 'TestCube',
                                                dimensions=unreal.Vector(200, 300, 400),
                                                local_transform=xform)
            self.assertIsInstance(component, unreal.StaticMeshComponent)
            self.assertEqual(component.get_name(), 'TestCube')
            self.assertIn(component, test_actor.get_components_by_class(
                unreal.StaticMeshComponent.static_class()))
            self._assert_transform(component, unreal.Vector(10, 20, 30),
                                   unreal.Rotator(0, 0, 0), unreal.Vector(2, 3, 4),
                                   unreal.Vector(100, 150, 200))  # (200/100)*1, (300/100)*1, (400/100)*1

    def test_add_sphere(self):
        """Ensures a sphere is added with the correct name, type, transform, and bounds.

        The radius and transform scale are combined multiplicatively.
        """
        with create_actor() as test_actor:
            xform = unreal.Transform(unreal.Vector(10, 20, 30), unreal.Rotator(0, 0, 0),
                                     unreal.Vector(3, 3, 3))
            component = PrimitiveTools.add_sphere(
                test_actor, 'TestSphere', radius=100, local_transform=xform)
            self.assertIsInstance(component, unreal.StaticMeshComponent)
            self.assertEqual(component.get_name(), 'TestSphere')
            self._assert_transform(component, unreal.Vector(10, 20, 30),
                                   unreal.Rotator(0, 0, 0), unreal.Vector(6, 6, 6),
                                   unreal.Vector(300, 300, 300))  # (100/50) * 3

    def test_add_cylinder(self):
        """Ensures a cylinder is added with the correct name, type, transform, and bounds.

        The radius and height are combined multiplicatively with the transform scale.
        """
        with create_actor() as test_actor:
            xform = unreal.Transform(unreal.Vector(10, 20, 30), unreal.Rotator(0, 0, 0),
                                     unreal.Vector(2, 2, 2))
            component = PrimitiveTools.add_cylinder(
                test_actor, 'TestCylinder', radius=25, height=200, local_transform=xform)
            self.assertIsInstance(component, unreal.StaticMeshComponent)
            self.assertEqual(component.get_name(), 'TestCylinder')
            self._assert_transform(component, unreal.Vector(10, 20, 30),
                                   unreal.Rotator(0, 0, 0), unreal.Vector(1, 1, 4),
                                   unreal.Vector(50, 50, 200))  # (25/50)*2, (200/100)*2

    def test_add_cone(self):
        """Ensures a cone is added with the correct name, type, transform, and bounds.

        The radius and height are combined multiplicatively with the transform scale.
        """
        with create_actor() as test_actor:
            xform = unreal.Transform(unreal.Vector(10, 20, 30), unreal.Rotator(0, 0, 0),
                                     unreal.Vector(1, 2, 1))
            component = PrimitiveTools.add_cone(
                test_actor, 'TestCone', radius=100, height=50, local_transform=xform)
            self.assertIsInstance(component, unreal.StaticMeshComponent)
            self.assertEqual(component.get_name(), 'TestCone')
            self._assert_transform(component, unreal.Vector(10, 20, 30),
                                   unreal.Rotator(0, 0, 0), unreal.Vector(2, 4, 0.5),
                                   unreal.Vector(100, 200, 25))  # (100/50)*1, (100/50)*2, (50/100)*1

    def test_rotation_preserved(self):
        """Ensures rotation from local_transform is correctly applied to each primitive type."""
        with create_actor() as test_actor:
            rotation = unreal.Rotator(15, 30, 45)
            xform = unreal.Transform(unreal.Vector(0, 0, 0), rotation, unreal.Vector(1, 1, 1))
            for add_fn, name in [
                (PrimitiveTools.add_cube, 'Cube'),
                (PrimitiveTools.add_sphere, 'Sphere'),
                (PrimitiveTools.add_cylinder, 'Cylinder'),
                (PrimitiveTools.add_cone, 'Cone'),
            ]:
                component = add_fn(test_actor, name, local_transform=xform)
                r = component.relative_rotation
                self.assertAlmostEqual(r.roll, rotation.roll, delta=0.01, msg=name)
                self.assertAlmostEqual(r.pitch, rotation.pitch, delta=0.01, msg=name)
                self.assertAlmostEqual(r.yaw, rotation.yaw, delta=0.01, msg=name)

    def test_invalid_transform_scale(self):
        """Ensures a zero or negative transform scale raises."""
        with create_actor() as test_actor:
            for scale in [unreal.Vector(-1, 1, 1), unreal.Vector(1, -1, 1), unreal.Vector(1, 1, -1),
                          unreal.Vector(0, 1, 1), unreal.Vector(1, 0, 1), unreal.Vector(1, 1, 0)]:
                xform = unreal.Transform(unreal.Vector(0, 0, 0), unreal.Rotator(0, 0, 0), scale)
                with self.assertToolRaisesRuntimeError():
                    PrimitiveTools.add_cube(test_actor, 'Cube', local_transform=xform)

    def test_add_cube_invalid_dimensions(self):
        """Ensures add_cube raises on non-positive dimension values."""
        with create_actor() as test_actor:
            for dims in [
                unreal.Vector(-1, 100, 100), unreal.Vector(100, -1, 100), unreal.Vector(100, 100, -1),
                unreal.Vector(0, 100, 100), unreal.Vector(100, 0, 100), unreal.Vector(100, 100, 0)]:
                with self.assertToolRaisesRuntimeError():
                    PrimitiveTools.add_cube(test_actor, 'Cube', dimensions=dims)

    def test_add_sphere_invalid_radius(self):
        """Ensures add_sphere raises on non-positive radius values."""
        with create_actor() as test_actor:
            with self.assertToolRaisesRuntimeError():
                PrimitiveTools.add_sphere(test_actor, 'Sphere', radius=0)
            with self.assertToolRaisesRuntimeError():
                PrimitiveTools.add_sphere(test_actor, 'Sphere', radius=-1)

    def test_add_cylinder_invalid_params(self):
        """Ensures add_cylinder raises on non-positive radius or height values."""
        with create_actor() as test_actor:
            with self.assertToolRaisesRuntimeError():
                PrimitiveTools.add_cylinder(test_actor, 'Cylinder', radius=0)
            with self.assertToolRaisesRuntimeError():
                PrimitiveTools.add_cylinder(test_actor, 'Cylinder', radius=-1)
            with self.assertToolRaisesRuntimeError():
                PrimitiveTools.add_cylinder(test_actor, 'Cylinder', height=0)
            with self.assertToolRaisesRuntimeError():
                PrimitiveTools.add_cylinder(test_actor, 'Cylinder', height=-1)

    def test_add_cone_invalid_params(self):
        """Ensures add_cone raises on non-positive radius or height values."""
        with create_actor() as test_actor:
            with self.assertToolRaisesRuntimeError():
                PrimitiveTools.add_cone(test_actor, 'Cone', radius=0)
            with self.assertToolRaisesRuntimeError():
                PrimitiveTools.add_cone(test_actor, 'Cone', radius=-1)
            with self.assertToolRaisesRuntimeError():
                PrimitiveTools.add_cone(test_actor, 'Cone', height=0)
            with self.assertToolRaisesRuntimeError():
                PrimitiveTools.add_cone(test_actor, 'Cone', height=-1)

    def test_add_multiple_primitives(self):
        """Ensures multiple primitive components can be added to a single actor."""
        with create_actor() as test_actor:
            cube = PrimitiveTools.add_cube(test_actor, 'Cube')
            sphere = PrimitiveTools.add_sphere(test_actor, 'Sphere')
            cylinder = PrimitiveTools.add_cylinder(test_actor, 'Cylinder')
            cone = PrimitiveTools.add_cone(test_actor, 'Cone')
            components = test_actor.get_components_by_class(
                unreal.StaticMeshComponent.static_class())
            self.assertIn(cube, components)
            self.assertIn(sphere, components)
            self.assertIn(cylinder, components)
            self.assertIn(cone, components)

    def _assert_transform(
            self, component: unreal.StaticMeshComponent,
            expected_translation: unreal.Vector, expected_rotation: unreal.Rotator,
            expected_scale: unreal.Vector, expected_extent: unreal.Vector,
            delta: float = 0.01, bounds_delta: float = 1.0):
        xform = component.get_relative_transform()
        t, r, s = xform.translation, component.relative_rotation, xform.scale3d
        _, extent, _ = unreal.SystemLibrary.get_component_bounds(component)
        self.assertAlmostEqual(t.x, expected_translation.x, delta=delta)
        self.assertAlmostEqual(t.y, expected_translation.y, delta=delta)
        self.assertAlmostEqual(t.z, expected_translation.z, delta=delta)
        self.assertAlmostEqual(r.roll, expected_rotation.roll, delta=delta)
        self.assertAlmostEqual(r.pitch, expected_rotation.pitch, delta=delta)
        self.assertAlmostEqual(r.yaw, expected_rotation.yaw, delta=delta)
        self.assertAlmostEqual(s.x, expected_scale.x, delta=delta)
        self.assertAlmostEqual(s.y, expected_scale.y, delta=delta)
        self.assertAlmostEqual(s.z, expected_scale.z, delta=delta)
        self.assertAlmostEqual(extent.x, expected_extent.x, delta=bounds_delta)
        self.assertAlmostEqual(extent.y, expected_extent.y, delta=bounds_delta)
        self.assertAlmostEqual(extent.z, expected_extent.z, delta=bounds_delta)
