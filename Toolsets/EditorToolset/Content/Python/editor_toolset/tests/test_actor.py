# Copyright Epic Games, Inc. All Rights Reserved.

import unittest
import unreal

from toolset_registry.tests.toolset_testcase import ToolCallTestCase
from editor_toolset.tests.test_scene import create_actor
from toolset_registry.tests.automation import create_temp_folder
from editor_toolset.toolsets.actor import ActorTools
from editor_toolset.toolsets.blueprint import BlueprintTools


class ActorToolsTestCase(ToolCallTestCase):
    """Test ActorTools toolset."""

    def test_get_label(self):
        """Ensures we can set and get actor labels"""
        with create_actor() as test_actor:
            self.assertEqual(ActorTools.get_label(test_actor), 'test_actor')

    def test_set_label(self):
        """Ensures we can set and get actor labels"""
        with create_actor() as test_actor:
            label = 'test_name'
            self.assertTrue(ActorTools.set_label(test_actor, label))
            self.assertEqual(label, test_actor.get_actor_label())

    def test_get_root_component(self):
        """Ensures we can get the root component of an actor."""
        with create_actor() as test_actor:
            root = ActorTools.get_root_component(test_actor)
            self.assertIsNotNone(root)
            self.assertIsInstance(root, unreal.SceneComponent)
            self.assertEqual(root, test_actor.root_component)

    def test_get_component_actor(self):
        """Ensures we can get the owning actor for a scene instance component."""
        with create_actor() as test_actor:
            component = ActorTools.add_component(
                test_actor, unreal.PointLightComponent.static_class(), 'TestLight')
            self.assertEqual(ActorTools.get_component_actor(component), test_actor)

    def test_get_component_actor_none(self):
        """Ensures attempt to get owning actor for un-owned component errors."""
        component = unreal.PointLightComponent()
        with self.assertToolRaisesRuntimeError():
            _ = ActorTools.get_component_actor(component)

    def test_get_component_actor_blueprint(self):
        """Ensures we can get the owning actor for a blueprint component."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            component = ActorTools.add_component(
                blueprint, unreal.PointLightComponent.static_class(), 'TestLight')
            actor = BlueprintTools.get_default_object(blueprint)
            self.assertEqual(ActorTools.get_component_actor(component), actor)

    def test_add_and_get_tags(self):
        """Ensures added tags are visible via get_tags and has_tag."""
        with create_actor() as test_actor:
            self.assertEqual(ActorTools.get_tags(test_actor), [])
            self.assertFalse(ActorTools.has_tag(test_actor, 'mytag'))
            ActorTools.add_tag(test_actor, 'mytag')
            self.assertIn('mytag', ActorTools.get_tags(test_actor))
            self.assertTrue(ActorTools.has_tag(test_actor, 'mytag'))

    def test_add_tag_duplicate_raises(self):
        """Ensures add_tag raises when the tag is already present."""
        with create_actor() as test_actor:
            ActorTools.add_tag(test_actor, 'mytag')
            with self.assertToolRaisesRuntimeError():
                ActorTools.add_tag(test_actor, 'mytag')

    def test_remove_tag(self):
        """Ensures remove_tag removes a tag and it is no longer visible."""
        with create_actor() as test_actor:
            ActorTools.add_tag(test_actor, 'mytag')
            ActorTools.remove_tag(test_actor, 'mytag')
            self.assertNotIn('mytag', ActorTools.get_tags(test_actor))
            self.assertFalse(ActorTools.has_tag(test_actor, 'mytag'))

    def test_remove_tag_not_found_raises(self):
        """Ensures remove_tag raises when the tag does not exist."""
        with create_actor() as test_actor:
            with self.assertToolRaisesRuntimeError():
                ActorTools.remove_tag(test_actor, 'missing')

    def test_get_tags_multiple(self):
        """Ensures get_tags returns all added tags."""
        with create_actor() as test_actor:
            ActorTools.add_tag(test_actor, 'alpha')
            ActorTools.add_tag(test_actor, 'beta')
            ActorTools.add_tag(test_actor, 'gamma')
            self.assertEqual(ActorTools.get_tags(test_actor), ['alpha', 'beta', 'gamma'])

    def test_get_transform(self):
        """Ensures we can set and get actor transforms."""
        with create_actor() as test_actor:
            translation = unreal.Vector(1, 2, 3)
            test_actor.set_actor_location(translation, False, True)
            new_transform = ActorTools.get_actor_transform(test_actor)
            self.assertEqual(new_transform.translation, translation)

    def test_set_transform(self):
        """Ensures we can set and get actor transforms."""
        with create_actor() as test_actor:
            new_transform = unreal.Transform(unreal.Vector(1, 2, 3))
            self.assertTrue(ActorTools.set_actor_transform(test_actor, new_transform))
            self.assertEqual(test_actor.get_actor_location(), new_transform.translation)

    def test_set_and_get_transform_blueprint(self):
        """Ensures set/get_actor_transform round-trips on a blueprint actor's default."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            cdo = BlueprintTools.get_default_object(blueprint)
            new_transform = unreal.Transform(unreal.Vector(11, 22, 33))
            self.assertTrue(ActorTools.set_actor_transform(cdo, new_transform))
            actual = ActorTools.get_actor_transform(cdo)
            self.assertEqual(actual.translation, new_transform.translation)

    def test_look_at_scene(self):
        """Ensures look_at produces correct yaw and pitch for a scene actor."""
        with create_actor(transform=unreal.Transform(unreal.Vector(0, 0, 400))) as actor:
            ActorTools.look_at(actor, unreal.Vector(100, 0, 100))
            rot = ActorTools.get_actor_transform(actor).rotation.rotator()
            self.assertAlmostEqual(rot.yaw, 0.0, delta=0.1)
            self.assertAlmostEqual(rot.pitch, -71.57, delta=0.1)

    def test_look_at_blueprint(self):
        """Ensures look_at updates a blueprint actor's default rotation."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            cdo = BlueprintTools.get_default_object(blueprint)
            ActorTools.look_at(cdo, unreal.Vector(0, 100, -100))
            rot = ActorTools.get_actor_transform(cdo).rotation.rotator()
            self.assertAlmostEqual(rot.yaw, 90.0, delta=0.1)
            self.assertAlmostEqual(rot.pitch, -45.0, delta=0.1)

    def test_get_parent_component(self):
        """Ensures we can get a component's parent component in a scene."""
        with create_actor() as test_actor, create_actor('parent') as parent_actor:
            test_actor.attach_to_component(
                parent_actor.root_component, unreal.Name(),
                unreal.AttachmentRule.KEEP_WORLD, unreal.AttachmentRule.KEEP_WORLD,
                unreal.AttachmentRule.KEEP_WORLD)
            self.assertEqual(
                ActorTools.get_parent_component(test_actor.root_component),
                parent_actor.root_component)

    def test_get_parent_component_no_parent(self):
        """Ensures get_parent_component returns None when the component has no parent."""
        with create_actor() as test_actor:
            self.assertIsNone(ActorTools.get_parent_component(test_actor.root_component))

    def test_set_parent_component(self):
        """Ensures we can attach an actor's root to another actor's component."""
        with create_actor() as test_actor, create_actor('parent') as parent_actor:
            self.assertTrue(
                ActorTools.set_parent_component(test_actor.root_component, parent_actor.root_component))
            self.assertEqual(test_actor.get_attach_parent_actor(), parent_actor)

    def test_set_parent_component_instance_root_raises(self):
        """Ensures set_parent_component raises when reparenting a root to a component in the same actor."""
        with create_actor() as test_actor:
            child = ActorTools.add_component(
                test_actor, unreal.SceneComponent.static_class(), 'Child')
            with self.assertToolRaisesRuntimeError():
                ActorTools.set_parent_component(test_actor.root_component, child)

    def test_set_parent_world(self):
        """Ensures we can detach a component from its parent."""
        with create_actor() as test_actor, create_actor('parent') as parent_actor:
            test_actor.attach_to_actor(
                parent_actor, unreal.Name(), unreal.AttachmentRule.KEEP_WORLD,
                unreal.AttachmentRule.KEEP_WORLD, unreal.AttachmentRule.KEEP_WORLD)
            self.assertTrue(ActorTools.set_parent_component(test_actor.root_component, None))
            self.assertEqual(test_actor.get_attach_parent_actor(), None)

    def test_get_bounds(self):
        """Ensures we can get actor bounds."""
        with create_actor() as test_actor:
            expected = unreal.Box(unreal.Vector(-128.0, -128.0, -128.0), unreal.Vector(128.0, 128.0, 128.0))
            bounds = ActorTools.get_actor_bounds(test_actor)
            self.assertEqual(bounds.min, expected.min)
            self.assertEqual(bounds.max, expected.max)

    def test_get_components(self):
        """Ensures we can get all components."""
        with create_actor() as test_actor:
            expected = test_actor.get_components_by_class()
            components = ActorTools.get_components(test_actor)
            self.assertEqual(len(expected), len(components))
            for i in range(len(expected)):
                self.assertEqual(components[i], expected[i])

    def test_get_components_filtered(self):
        """Ensures we can get components filtered by class."""
        with create_actor() as test_actor:
            filter_class = unreal.BillboardComponent.static_class()
            expected = test_actor.get_components_by_class(filter_class)
            components = ActorTools.get_components(test_actor, filter_class)
            self.assertEqual(len(expected), len(components))
            for i in range(len(expected)):
                self.assertEqual(components[i], expected[i])

    def test_get_components_blueprint_actor(self):
        """Ensures get_components returns components when the actor is a blueprint default object."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            ActorTools.add_component(
                blueprint, unreal.PointLightComponent.static_class(), 'TestLight')
            actor = BlueprintTools.get_default_object(blueprint)
            components = ActorTools.get_components(actor)
            self.assertTrue(any(isinstance(c, unreal.PointLightComponent) for c in components))

    def test_get_components_filtered_blueprint_actor(self):
        """Ensures get_components correctly filters by type for a blueprint default object."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            ActorTools.add_component(
                blueprint, unreal.PointLightComponent.static_class(), 'TestLight')
            ActorTools.add_component(
                blueprint, unreal.BrainComponent.static_class(), 'TestBrain')
            actor = BlueprintTools.get_default_object(blueprint)
            filter_class = unreal.PointLightComponent.static_class()
            components = ActorTools.get_components(actor, filter_class)
            self.assertEqual(len(components), 1)
            self.assertIsInstance(components[0], unreal.PointLightComponent)

    def test_add_scene_component_to_actor_instance(self):
        """Ensures we can add scene components to actor instances."""
        with create_actor() as test_actor:
            name = 'TestLight'
            new_component = ActorTools.add_component(
                test_actor, unreal.PointLightComponent.static_class(), name)
            self.assertIsInstance(new_component, unreal.PointLightComponent)
            self.assertEqual(new_component.get_name(), name)
            self.assertEqual(
                new_component.get_attach_parent(), test_actor.root_component)

    def test_add_non_scene_component_to_actor_instance(self):
        """Ensures we can add basic components to actor instances."""
        with create_actor() as test_actor:
            name = 'TestComponent'
            new_component = ActorTools.add_component(
                test_actor, unreal.BrainComponent.static_class(), name)
            self.assertIsInstance(new_component, unreal.BrainComponent)
            self.assertEqual(new_component.get_name(), name)

    def test_add_scene_component_to_component_instance(self):
        """Ensures we can add components to a component in the scene."""
        with create_actor() as test_actor:
            base_component = ActorTools.add_component(
                test_actor, unreal.SceneComponent.static_class(), 'Root')
            name = 'TestLight'
            new_component = ActorTools.add_component(
                base_component, unreal.PointLightComponent.static_class(), name)
            self.assertIsInstance(new_component, unreal.PointLightComponent)
            self.assertEqual(new_component.get_name(), name)
            self.assertEqual(
                new_component.get_attach_parent(), base_component)

    def test_remove_component_from_actor_instance(self):
        """Ensures we can remove a component from an actor instance."""
        with create_actor() as test_actor:
            new_component = ActorTools.add_component(
                test_actor, unreal.PointLightComponent.static_class(), 'TestLight')
            self.assertTrue(ActorTools.remove_component(new_component))
            self.assertNotIn(new_component, ActorTools.get_components(test_actor))

    def test_remove_component_from_blueprint(self):
        """Ensures we can remove a component from an actor blueprint."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            new_component = ActorTools.add_component(
                blueprint, unreal.PointLightComponent.static_class(), 'TestLight')
            actor = BlueprintTools.get_default_object(blueprint)
            self.assertTrue(ActorTools.remove_component(new_component))
            self.assertNotIn(new_component, ActorTools.get_components(actor))

    def test_add_scene_component_to_blueprint(self):
        """Ensures we can add scene components to actor blueprints."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            name = 'TestLight'
            new_component = ActorTools.add_component(
                blueprint, unreal.PointLightComponent.static_class(), name)
            self.assertIsInstance(new_component, unreal.PointLightComponent)
            self.assertIn(name, new_component.get_name())

    def test_add_non_scene_component_to_blueprint(self):
        """Ensures we can add non-scene components to actor blueprints."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            name = 'TestComponent'
            new_component = ActorTools.add_component(
                blueprint, unreal.BrainComponent.static_class(), name)
            self.assertIsInstance(new_component, unreal.BrainComponent)
            self.assertIn(name, new_component.get_name())

    def test_add_scene_component_to_blueprint_actor(self):
        """Ensures we can add scene components to actors in blueprints."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            actor = BlueprintTools.get_default_object(blueprint)
            name = 'TestLight'
            new_component = ActorTools.add_component(
                actor, unreal.PointLightComponent.static_class(), name)
            self.assertIsInstance(new_component, unreal.PointLightComponent)
            self.assertIn(name, new_component.get_name())

    def test_add_non_scene_component_to_blueprint_actor(self):
        """Ensures we can add scene components to actors in blueprints."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            actor = BlueprintTools.get_default_object(blueprint)
            name = 'TestComponent'
            new_component = ActorTools.add_component(
                actor, unreal.BrainComponent.static_class(), name)
            self.assertIsInstance(new_component, unreal.BrainComponent)
            self.assertIn(name, new_component.get_name())

    def test_add_scene_component_to_blueprint_component(self):
        """Ensures we can add scene components to actor blueprints."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            parent_component = ActorTools.add_component(
                blueprint, unreal.PointLightComponent.static_class(), 'ParentLight')
            self.assertIsInstance(parent_component, unreal.PointLightComponent)
            name = 'TestLight'
            child_component = ActorTools.add_component(
                parent_component, unreal.PointLightComponent.static_class(), name)
            self.assertIsInstance(child_component, unreal.PointLightComponent)
            self.assertIn(name, child_component.get_name())
            #self.assertEqual(child_component.get_attach_parent(), parent_component)

    def test_get_parent_component_blueprint_default(self):
        """Ensures get_parent_component returns None for the root component of a blueprint CDO."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            actor = BlueprintTools.get_default_object(blueprint)
            root = ActorTools.get_root_component(actor)
            self.assertIsNotNone(root)
            self.assertIsNone(ActorTools.get_parent_component(root))

    def test_set_parent_component_blueprint(self):
        """Ensures we can reparent a blueprint actor's root to another component."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            parent_comp = ActorTools.add_component(
                blueprint, unreal.SceneComponent.static_class(), 'ParentComp')
            actor = BlueprintTools.get_default_object(blueprint)
            self.assertTrue(ActorTools.set_parent_component(
                ActorTools.get_root_component(actor), parent_comp))
            actor = BlueprintTools.get_default_object(blueprint)
            self.assertIn('ParentComp', ActorTools.get_root_component(actor).get_name())

    def test_set_parent_component_blueprint_removes_default_scene_root(self):
        """Ensures promoting a component to root removes the DefaultSceneRoot automatically."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            new_root = ActorTools.add_component(
                blueprint, unreal.SceneComponent.static_class(), 'NewRoot')
            actor = BlueprintTools.get_default_object(blueprint)
            ActorTools.set_parent_component(ActorTools.get_root_component(actor), new_root)
            actor = BlueprintTools.get_default_object(blueprint)
            self.assertEqual(len(ActorTools.get_components(actor)), 1)
            self.assertIn('NewRoot', ActorTools.get_root_component(actor).get_name())

    def test_set_parent_component_blueprint_cross_actor_raises(self):
        """Ensures set_parent_component raises when the parent belongs to a different actor."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            other_blueprint = BlueprintTools.create(
                test_folder, 'other', unreal.Actor.static_class())
            other_component = ActorTools.add_component(
                other_blueprint, unreal.SceneComponent.static_class(), 'OtherComp')
            actor = BlueprintTools.get_default_object(blueprint)
            with self.assertToolRaisesRuntimeError():
                ActorTools.set_parent_component(ActorTools.get_root_component(actor), other_component)

    def test_set_parent_component_blueprint_reparent_to_existing_root(self):
        """Ensures a non-root component can be reparented under the current scene root.

        Regression: previously this routed through MakeNewSceneRoot, which self-parented
        the existing root when promoting it to itself and tripped an ensure in
        GetActorRootHandle.
        """
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            new_root = ActorTools.add_component(
                blueprint, unreal.SceneComponent.static_class(), 'NewRoot')
            actor = BlueprintTools.get_default_object(blueprint)
            ActorTools.set_parent_component(ActorTools.get_root_component(actor), new_root)
            child = ActorTools.add_component(
                blueprint, unreal.SceneComponent.static_class(), 'Child')
            actor = BlueprintTools.get_default_object(blueprint)
            new_root = next(
                c for c in ActorTools.get_components(actor) if 'NewRoot' in c.get_name())
            child = next(c for c in ActorTools.get_components(actor) if 'Child' in c.get_name())
            self.assertTrue(ActorTools.set_parent_component(child, new_root))
            actor = BlueprintTools.get_default_object(blueprint)
            child = next(c for c in ActorTools.get_components(actor) if 'Child' in c.get_name())
            new_root = next(
                c for c in ActorTools.get_components(actor) if 'NewRoot' in c.get_name())
            self.assertEqual(ActorTools.get_parent_component(child), new_root)
            self.assertIn('NewRoot', ActorTools.get_root_component(actor).get_name())

    def test_set_parent_component_blueprint_reparent_between_components(self):
        """Ensures a non-root component can be reparented under another non-root component."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            sibling_a = ActorTools.add_component(
                blueprint, unreal.SceneComponent.static_class(), 'SiblingA')
            sibling_b = ActorTools.add_component(
                blueprint, unreal.SceneComponent.static_class(), 'SiblingB')
            actor = BlueprintTools.get_default_object(blueprint)
            sibling_a = next(
                c for c in ActorTools.get_components(actor) if 'SiblingA' in c.get_name())
            sibling_b = next(
                c for c in ActorTools.get_components(actor) if 'SiblingB' in c.get_name())
            self.assertTrue(ActorTools.set_parent_component(sibling_b, sibling_a))
            actor = BlueprintTools.get_default_object(blueprint)
            sibling_a = next(
                c for c in ActorTools.get_components(actor) if 'SiblingA' in c.get_name())
            sibling_b = next(
                c for c in ActorTools.get_components(actor) if 'SiblingB' in c.get_name())
            self.assertEqual(ActorTools.get_parent_component(sibling_b), sibling_a)

    def test_set_parent_component_blueprint_self_raises(self):
        """Ensures set_parent_component raises when component and parent are the same."""
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(
                test_folder, 'test', unreal.Actor.static_class())
            component = ActorTools.add_component(
                blueprint, unreal.SceneComponent.static_class(), 'Comp')
            with self.assertToolRaisesRuntimeError():
                ActorTools.set_parent_component(component, component)
