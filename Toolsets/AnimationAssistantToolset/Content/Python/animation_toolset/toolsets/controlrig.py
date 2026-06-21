# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry
from toolset_registry.helpers import create_asset


# ============================================================================
# Enums
# ============================================================================

@unreal.uenum()
class EventType(unreal.EnumBase):
    """Types of execution events in a Control Rig graph."""
    FORWARD_SOLVE = unreal.uvalue(0)
    BACKWARD_SOLVE = unreal.uvalue(1)
    INTERACTION = unreal.uvalue(2)


# ============================================================================
# Constants
# ============================================================================

_RIGVM_MODEL = "RigVMModel"
_RIGVM_FUNCTION_LIBRARY = "RigVMFunctionLibrary"

_EVENT_STRUCT_NAMES = {
    EventType.FORWARD_SOLVE: "RigUnit_BeginExecution",
    EventType.BACKWARD_SOLVE: "RigUnit_InverseExecution",
    EventType.INTERACTION: "RigUnit_InteractionExecution",
}



# ============================================================================
# Toolset
# ============================================================================

@unreal.uclass()
class ControlRigTools(unreal.ToolsetDefinition):
    """Tools for creating and editing Control Rig assets, including hierarchy
    management, graph operations, and node/pin manipulation."""

    # ========================================================================
    # Asset Creation
    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def create(path: str) -> unreal.ControlRigBlueprint:
        """Creates a new Control Rig at the given location.

        Args:
            path: The content browser path for the new Control Rig.

        Returns:
            The newly created ControlRigBlueprint.
        """
        package_path = "/".join(path.split("/")[:-1])
        asset_name = path.split("/")[-1]

        control_rig = create_asset(
            package_path,
            asset_name,
            unreal.ControlRigBlueprint,
            unreal.ControlRigBlueprintFactory()
        )

        unreal.EditorAssetLibrary.save_asset(path, only_if_is_dirty=False)
        return control_rig

    # ========================================================================
    # Hierarchy Operations
    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def import_bones_from_asset(
        control_rig: unreal.ControlRigBlueprint,
        skeletal_mesh: unreal.SkeletalMesh
    ) -> list[unreal.RigElementKey]:
        """Import bones from the given skeletal mesh to the Control Rig hierarchy.

        Args:
            control_rig: The Control Rig to import bones into.
            skeletal_mesh: The skeletal mesh to import bones from.

        Returns:
            List of RigElementKeys for the imported bones.
        """
        hierarchy = ControlRigTools._get_hierarchy(control_rig)
        controller = hierarchy.get_controller()
        keys = controller.import_bones_from_asset(
            skeletal_mesh.get_path_name(), '', True, True, False
        )
        if not keys:
            raise ValueError(
                f"Failed to import bones from '{skeletal_mesh.get_path_name()}'. "
                "Ensure the skeletal mesh has a valid skeleton."
            )
        return list(keys)

    @toolset_registry.tool_call
    @staticmethod
    def get_elements(
        control_rig: unreal.ControlRigBlueprint,
        element_type: unreal.RigElementType = unreal.RigElementType.NONE
    ) -> list[unreal.RigElementKey]:
        """Get hierarchy elements of the specified type.

        Args:
            control_rig: The Control Rig to query.
            element_type: Type of elements to return; RigElementType.NONE (the
                default) returns all elements.

        Returns:
            List of RigElementKeys matching the specified type.
        """
        # [5.7 port] Was `unreal.RigElementType | None = None`; UE 5.7's Python
        # reflection cannot build an optional-enum property, so we use NONE
        # (the enum's zero value) as the "all elements" sentinel instead of None.
        hierarchy = ControlRigTools._get_hierarchy(control_rig)
        all_keys = hierarchy.get_all_keys()

        if element_type == unreal.RigElementType.NONE:
            return list(all_keys)

        return [key for key in all_keys if key.type == element_type]

    @toolset_registry.tool_call
    @staticmethod
    def get_all_bones(control_rig: unreal.ControlRigBlueprint) -> list[unreal.RigElementKey]:
        """Get all bones in the Control Rig hierarchy.

        Args:
            control_rig: The Control Rig to query.

        Returns:
            List of RigElementKeys for all bones.
        """
        return ControlRigTools.get_elements(control_rig, unreal.RigElementType.BONE)

    @toolset_registry.tool_call
    @staticmethod
    def get_all_nulls(control_rig: unreal.ControlRigBlueprint) -> list[unreal.RigElementKey]:
        """Get all nulls (locators) in the Control Rig hierarchy.

        Args:
            control_rig: The Control Rig to query.

        Returns:
            List of RigElementKeys for all nulls.
        """
        return ControlRigTools.get_elements(control_rig, unreal.RigElementType.NULL)

    @toolset_registry.tool_call
    @staticmethod
    def get_all_controls(control_rig: unreal.ControlRigBlueprint) -> list[unreal.RigElementKey]:
        """Get all controls in the Control Rig hierarchy.

        Args:
            control_rig: The Control Rig to query.

        Returns:
            List of RigElementKeys for all controls.
        """
        return ControlRigTools.get_elements(control_rig, unreal.RigElementType.CONTROL)

    @toolset_registry.tool_call
    @staticmethod
    def add_element(
        control_rig: unreal.ControlRigBlueprint,
        name: str,
        element_type: str,
        parent: unreal.RigElementKey | None = None,
        transform: unreal.Transform | None = None
    ) -> unreal.RigElementKey:
        """Add a bone or null element to the Control Rig hierarchy.

        Args:
            control_rig: The Control Rig to add the element to.
            name: Name for the new element.
            element_type: Type of element to create: "bone" or "null".
            parent: Parent element in the hierarchy. None creates at root level.
            transform: Initial world transform. Uses identity if None.
                Only specified fields are applied; unset fields use identity.

        Returns:
            The RigElementKey for the newly created element.
        """
        element_type_lower = element_type.lower()
        if element_type_lower not in ("bone", "null"):
            raise ValueError(
                f"add_element only supports 'bone' or 'null' types, got '{element_type}'. "
                "Use add_control() for controls."
            )

        hierarchy = ControlRigTools._get_hierarchy(control_rig)
        controller = hierarchy.get_controller()

        parent_key = parent if parent else unreal.RigElementKey()
        init_transform = transform or unreal.Transform()

        if element_type_lower == "bone":
            return controller.add_bone(
                name,
                parent_key,
                init_transform,
                True,  # bTransformInGlobal
                unreal.RigBoneType.USER
            )
        else:  # null
            return controller.add_null(
                name,
                parent_key,
                init_transform,
                True  # bTransformInGlobal
            )

    @toolset_registry.tool_call
    @staticmethod
    def add_bone(
        control_rig: unreal.ControlRigBlueprint,
        name: str,
        parent: unreal.RigElementKey | None = None,
        transform: unreal.Transform | None = None
    ) -> unreal.RigElementKey:
        """Add a bone to the Control Rig hierarchy.

        Args:
            control_rig: The Control Rig to add the bone to.
            name: Name for the new bone.
            parent: Parent element in the hierarchy. None creates at root level.
            transform: Initial world transform. Uses identity if None.
                Only specified fields are applied; unset fields use identity.

        Returns:
            The RigElementKey for the newly created bone.
        """
        return ControlRigTools.add_element(
            control_rig, name, "bone", parent, transform
        )

    @toolset_registry.tool_call
    @staticmethod
    def add_null(
        control_rig: unreal.ControlRigBlueprint,
        name: str,
        parent: unreal.RigElementKey | None = None,
        transform: unreal.Transform | None = None
    ) -> unreal.RigElementKey:
        """Add a null (locator) to the Control Rig hierarchy.

        Args:
            control_rig: The Control Rig to add the null to.
            name: Name for the new null.
            parent: Parent element in the hierarchy. None creates at root level.
            transform: Initial world transform. Uses identity if None.
                Only specified fields are applied; unset fields use identity.

        Returns:
            The RigElementKey for the newly created null.
        """
        return ControlRigTools.add_element(
            control_rig, name, "null", parent, transform
        )

    @toolset_registry.tool_call
    @staticmethod
    def add_control(
        control_rig: unreal.ControlRigBlueprint,
        name: str,
        parent: unreal.RigElementKey | None = None,
        settings: unreal.RigControlSettings | None = None
    ) -> unreal.RigElementKey:
        """Add a control to the hierarchy.

        Args:
            control_rig: The Control Rig to add the control to.
            name: Name for the new control.
            parent: Parent element in the hierarchy. None creates at root level.
            settings: Control settings (shape, color, limits). Uses defaults if None.

        Returns:
            The RigElementKey for the newly created control.
        """
        hierarchy = ControlRigTools._get_hierarchy(control_rig)
        controller = hierarchy.get_controller()

        parent_key = parent if parent else unreal.RigElementKey()
        ctrl_settings = settings if settings else unreal.RigControlSettings()
        control_value = unreal.RigControlValue()

        return controller.add_control(
            name,
            parent_key,
            ctrl_settings,
            control_value,
            True  # bSetupUndo
        )

    @toolset_registry.tool_call
    @staticmethod
    def get_global_transform(
        control_rig: unreal.ControlRigBlueprint,
        item: unreal.RigElementKey,
        initial: bool = False
    ) -> unreal.Transform:
        """Get global transform of a hierarchy element.

        Args:
            control_rig: The Control Rig to query.
            item: The element to get the transform for.
            initial: If True, returns the initial (setup) transform.

        Returns:
            The element's global transform with translation, rotation (euler), and scale.
        """
        hierarchy = ControlRigTools._get_hierarchy(control_rig)
        return hierarchy.get_global_transform(item, initial)

    @toolset_registry.tool_call
    @staticmethod
    def set_global_transform(
        control_rig: unreal.ControlRigBlueprint,
        item: unreal.RigElementKey,
        transform: unreal.Transform,
        initial: bool = False
    ) -> None:
        """Set global transform of a hierarchy element.

        Args:
            control_rig: The Control Rig to modify.
            item: The element to set the transform for.
            transform: The new global transform.
            initial: If True, sets the initial (setup) transform.
        """
        hierarchy = ControlRigTools._get_hierarchy(control_rig)
        hierarchy.set_global_transform(item, transform, initial)

    @toolset_registry.tool_call
    @staticmethod
    def get_local_transform(
        control_rig: unreal.ControlRigBlueprint,
        item: unreal.RigElementKey,
        initial: bool = False
    ) -> unreal.Transform:
        """Get local transform of a hierarchy element.

        Args:
            control_rig: The Control Rig to query.
            item: The element to get the transform for.
            initial: If True, returns the initial (setup) transform.

        Returns:
            The element's local transform relative to its parent,
            with translation, rotation (euler), and scale.
        """
        hierarchy = ControlRigTools._get_hierarchy(control_rig)
        return hierarchy.get_local_transform(item, initial)

    @toolset_registry.tool_call
    @staticmethod
    def set_local_transform(
        control_rig: unreal.ControlRigBlueprint,
        item: unreal.RigElementKey,
        transform: unreal.Transform,
        initial: bool = False
    ) -> None:
        """Set local transform of a hierarchy element.

        Args:
            control_rig: The Control Rig to modify.
            item: The element to set the transform for.
            transform: The new local transform.
            initial: If True, sets the initial (setup) transform.
        """
        hierarchy = ControlRigTools._get_hierarchy(control_rig)
        hierarchy.set_local_transform(item, transform, initial)

    @toolset_registry.tool_call
    @staticmethod
    def get_parent(
        control_rig: unreal.ControlRigBlueprint,
        item: unreal.RigElementKey
    ) -> unreal.RigElementKey:
        """Get the parent of a hierarchy element.

        Args:
            control_rig: The Control Rig to query.
            item: The element to get the parent of.

        Returns:
            The parent's RigElementKey, or an invalid key if item is at root.
        """
        hierarchy = ControlRigTools._get_hierarchy(control_rig)
        return hierarchy.get_first_parent(item)

    @toolset_registry.tool_call
    @staticmethod
    def get_children(
        control_rig: unreal.ControlRigBlueprint,
        item: unreal.RigElementKey,
        recursive: bool = False
    ) -> list[unreal.RigElementKey]:
        """Get children of a hierarchy element.

        Args:
            control_rig: The Control Rig to query.
            item: The element to get children of.
            recursive: If True, returns all descendants recursively.

        Returns:
            List of child RigElementKeys.
        """
        hierarchy = ControlRigTools._get_hierarchy(control_rig)
        return list(hierarchy.get_children(item, recursive))

    # ========================================================================
    # Graph Management
    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def get_graph(
        control_rig: unreal.ControlRigBlueprint,
        graph_name: str
    ) -> unreal.RigVMGraph:
        """Get a specific graph from the Control Rig by name.

        Args:
            control_rig: The Control Rig to query.
            graph_name: Name of the graph (e.g., "RigVMModel").

        Returns:
            The RigVMGraph object.
        """
        controller = control_rig.get_controller_by_name(graph_name)
        if not controller:
            raise ValueError(f"Cannot find graph '{graph_name}' in Control Rig")
        return controller.get_graph()

    @toolset_registry.tool_call
    @staticmethod
    def list_graphs(control_rig: unreal.ControlRigBlueprint) -> list[unreal.RigVMGraph]:
        """List all graphs in the Control Rig.

        Args:
            control_rig: The Control Rig to query.

        Returns:
            List of RigVMGraph objects (excludes function library).
        """
        models = control_rig.get_all_models()
        graphs = []
        for model in models:
            graph_name = model.get_name()
            if graph_name == _RIGVM_FUNCTION_LIBRARY:
                continue
            graphs.append(model)
        return graphs

    @toolset_registry.tool_call
    @staticmethod
    def add_graph(
        control_rig: unreal.ControlRigBlueprint,
        name: str
    ) -> unreal.RigVMGraph:
        """Create a new empty graph in the Control Rig.

        Args:
            control_rig: The Control Rig to add the graph to.
            name: Name for the new graph.

        Returns:
            The newly created RigVMGraph.
        """
        control_rig.add_model(name, False, False)

        # UE adds "RigVMModel " prefix to graph names
        if not name.startswith(_RIGVM_MODEL):
            full_name = f"{_RIGVM_MODEL} {name}"
        else:
            full_name = name

        controller = control_rig.get_controller_by_name(full_name)
        if not controller:
            raise ValueError(f"Failed to create graph '{name}'")
        return controller.get_graph()

    @toolset_registry.tool_call
    @staticmethod
    def get_forward_solve_graph(control_rig: unreal.ControlRigBlueprint) -> unreal.RigVMGraph:
        """Get the forward solve graph (main execution graph).

        This graph contains the BeginExecution event and runs during normal
        animation evaluation.

        Args:
            control_rig: The Control Rig to query.

        Returns:
            The forward solve RigVMGraph.
        """
        return ControlRigTools.get_graph(control_rig, _RIGVM_MODEL)

    @toolset_registry.tool_call
    @staticmethod
    def get_event_graph(
        control_rig: unreal.ControlRigBlueprint,
        event_type: EventType
    ) -> unreal.RigVMGraph:
        """Get a graph containing the specified event type.

        Args:
            control_rig: The Control Rig to query.
            event_type: The event type to search for.

        Returns:
            The RigVMGraph containing the specified event.
        """
        graph_name = ControlRigTools._find_graph_with_event(control_rig, event_type)
        if not graph_name:
            raise ValueError(
                f"No graph found containing '{event_type}' event in Control Rig"
            )
        return ControlRigTools.get_graph(control_rig, graph_name)

    @toolset_registry.tool_call
    @staticmethod
    def get_backward_solve_graph(control_rig: unreal.ControlRigBlueprint) -> unreal.RigVMGraph:
        """Get the backward solve graph.

        The backward solve graph contains the InverseExecution event and runs
        during IK operations.

        Args:
            control_rig: The Control Rig to query.

        Returns:
            The backward solve RigVMGraph.
        """
        return ControlRigTools.get_event_graph(control_rig, EventType.BACKWARD_SOLVE)

    @toolset_registry.tool_call
    @staticmethod
    def get_interaction_graph(control_rig: unreal.ControlRigBlueprint) -> unreal.RigVMGraph:
        """Get the interaction graph.

        The interaction graph contains the InteractionExecution event and runs
        during user interaction with controls.

        Args:
            control_rig: The Control Rig to query.

        Returns:
            The interaction RigVMGraph.
        """
        return ControlRigTools.get_event_graph(control_rig, EventType.INTERACTION)

    @toolset_registry.tool_call
    @staticmethod
    def add_event_graph(
        control_rig: unreal.ControlRigBlueprint,
        event_type: EventType,
        name: str | None = None
    ) -> unreal.RigVMGraph:
        """Create a new graph with the specified event type.

        Args:
            control_rig: The Control Rig to add the graph to.
            event_type: The event type to add (BACKWARD_SOLVE or INTERACTION).
            name: Optional custom name for the graph.

        Returns:
            The newly created RigVMGraph with the event node.
        """
        if event_type == EventType.FORWARD_SOLVE:
            raise ValueError(
                "Cannot create a new ForwardSolve graph. "
                "Use get_forward_solve_graph() for the main execution graph."
            )

        default_names = {
            EventType.BACKWARD_SOLVE: "Backward Solve",
            EventType.INTERACTION: "Interaction",
        }
        graph_name = name or default_names.get(event_type, str(event_type))
        graph = ControlRigTools.add_graph(control_rig, graph_name)

        # Add the event node
        ControlRigTools.add_event_node(
            control_rig,
            graph,
            event_type,
            unreal.Vector2D(200, 400)
        )

        return graph

    @toolset_registry.tool_call
    @staticmethod
    def add_backward_solve_graph(
        control_rig: unreal.ControlRigBlueprint,
        name: str | None = None
    ) -> unreal.RigVMGraph:
        """Create a backward solve graph with InverseExecution event.

        Args:
            control_rig: The Control Rig to add the graph to.
            name: Optional custom name (default: "Backward Solve").

        Returns:
            The newly created RigVMGraph with InverseExecution event.
        """
        return ControlRigTools.add_event_graph(control_rig, EventType.BACKWARD_SOLVE, name)

    @toolset_registry.tool_call
    @staticmethod
    def add_interaction_graph(
        control_rig: unreal.ControlRigBlueprint,
        name: str | None = None
    ) -> unreal.RigVMGraph:
        """Create an interaction graph with InteractionExecution event.

        Args:
            control_rig: The Control Rig to add the graph to.
            name: Optional custom name (default: "Interaction").

        Returns:
            The newly created RigVMGraph with InteractionExecution event.
        """
        return ControlRigTools.add_event_graph(control_rig, EventType.INTERACTION, name)

    # ========================================================================
    # Node Operations
    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def create_node(
        control_rig: unreal.ControlRigBlueprint,
        graph: unreal.RigVMGraph,
        node_type: str,
        position: unreal.Vector2D | None = None,
        node_name: str = ""
    ) -> unreal.RigVMNode:
        """Create a new RigUnit node in the graph.

        Args:
            control_rig: The Control Rig containing the graph.
            graph: The graph to add the node to.
            node_type: RigUnit struct name (e.g., "RigUnit_MathFloatAdd") or
                      full path (e.g., "/Script/ControlRig.RigUnit_MathFloatAdd").
            position: Position in the graph editor. Uses (0, 0) if None.
            node_name: Optional custom name for the node.

        Returns:
            The created RigVMNode.
        """
        graph_name = graph.get_name()
        controller = control_rig.get_controller_by_name(graph_name)
        if not controller:
            raise ValueError(f"Cannot get controller for graph '{graph_name}'")

        pos = position if position else unreal.Vector2D(0, 0)

        # Build full struct path if needed
        if not node_type.startswith('/Script/'):
            struct_path = f"/Script/ControlRig.{node_type}"
        else:
            struct_path = node_type

        node = controller.add_unit_node_from_struct_path(
            struct_path,
            'Execute',
            pos,
            node_name,
            False  # setup_undo_redo
        )

        if not node:
            raise ValueError(f"Failed to create node of type '{node_type}'")
        return node

    @toolset_registry.tool_call
    @staticmethod
    def list_nodes(
        control_rig: unreal.ControlRigBlueprint,
        graph: unreal.RigVMGraph
    ) -> list[unreal.RigVMNode]:
        """List all nodes in a graph.

        Args:
            control_rig: The Control Rig containing the graph.
            graph: The graph to query.

        Returns:
            List of RigVMNode objects in the graph.
        """
        return list(graph.get_nodes())

    @toolset_registry.tool_call
    @staticmethod
    def delete_node(
        control_rig: unreal.ControlRigBlueprint,
        graph: unreal.RigVMGraph,
        node: unreal.RigVMNode
    ) -> None:
        """Delete a node from the graph.

        Args:
            control_rig: The Control Rig containing the graph.
            graph: The graph containing the node.
            node: The node to delete.
        """
        graph_name = graph.get_name()
        controller = control_rig.get_controller_by_name(graph_name)
        if not controller:
            raise ValueError(f"Cannot get controller for graph '{graph_name}'")
        if not controller.remove_node(node, False):
            raise ValueError(f"Failed to delete node '{node.get_name()}'")

    @toolset_registry.tool_call
    @staticmethod
    def get_node_position(
        control_rig: unreal.ControlRigBlueprint,
        node: unreal.RigVMNode
    ) -> unreal.Vector2D:
        """Get the position of a node in the graph editor.

        Args:
            control_rig: The Control Rig containing the node.
            node: The node to query.

        Returns:
            The node's position as Vector2D.
        """
        return node.get_position()

    @toolset_registry.tool_call
    @staticmethod
    def set_node_position(
        control_rig: unreal.ControlRigBlueprint,
        graph: unreal.RigVMGraph,
        node: unreal.RigVMNode,
        position: unreal.Vector2D
    ) -> None:
        """Set the position of a node in the graph editor.

        Args:
            control_rig: The Control Rig containing the graph.
            graph: The graph containing the node.
            node: The node to move.
            position: The new position.
        """
        graph_name = graph.get_name()
        controller = control_rig.get_controller_by_name(graph_name)
        if not controller:
            raise ValueError(f"Cannot get controller for graph '{graph_name}'")
        if not controller.set_node_position(node, position, False, False):
            raise ValueError(f"Failed to set position for node '{node.get_name()}'")

    @toolset_registry.tool_call
    @staticmethod
    def add_event_node(
        control_rig: unreal.ControlRigBlueprint,
        graph: unreal.RigVMGraph,
        event_type: EventType,
        position: unreal.Vector2D | None = None
    ) -> unreal.RigVMNode:
        """Add an event node to the graph.

        Args:
            control_rig: The Control Rig containing the graph.
            graph: The graph to add the event to.
            event_type: The type of event node.
            position: Position in the graph. Uses (200, 200) if None.

        Returns:
            The created event RigVMNode.
        """
        pos = position if position else unreal.Vector2D(200, 200)
        struct_name = _EVENT_STRUCT_NAMES[event_type]
        return ControlRigTools.create_node(control_rig, graph, struct_name, pos)

    @toolset_registry.tool_call
    @staticmethod
    def add_variable_node(
        control_rig: unreal.ControlRigBlueprint,
        graph: unreal.RigVMGraph,
        variable_name: str,
        is_getter: bool = True,
        position: unreal.Vector2D | None = None
    ) -> unreal.RigVMNode:
        """Create a variable getter or setter node.

        The variable must already exist (created via add_variable first).

        Args:
            control_rig: The Control Rig containing the graph.
            graph: The graph to add the node to.
            variable_name: Name of the variable to reference.
            is_getter: True for getter node, False for setter node.
            position: Position in the graph. Uses (0, 0) if None.

        Returns:
            The created variable RigVMNode.
        """
        graph_name = graph.get_name()
        controller = control_rig.get_controller_by_name(graph_name)
        if not controller:
            raise ValueError(f"Cannot get controller for graph '{graph_name}'")

        pos = position if position else unreal.Vector2D(0, 0)

        # Query variable type
        variable_type = None
        variables = control_rig.get_member_variables()
        for var in variables:
            if var.get_editor_property('name') == variable_name:
                variable_type = var.get_editor_property('cpp_type')
                break

        if variable_type is None:
            raise ValueError(f"Variable '{variable_name}' not found")

        node = controller.add_variable_node(
            variable_name,
            variable_type,
            None,  # cpp_type object
            is_getter,
            '',  # default_value
            pos,
            ''  # node_name
        )

        if not node:
            raise ValueError(f"Failed to create variable node for '{variable_name}'")
        return node

    # ========================================================================
    # Pin/Connection Operations
    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def list_pins(
        control_rig: unreal.ControlRigBlueprint,
        node: unreal.RigVMNode
    ) -> list[unreal.RigVMPin]:
        """List all pins on a node.

        Args:
            control_rig: The Control Rig containing the node.
            node: The node to query.

        Returns:
            List of RigVMPin objects on the node.
        """
        return list(node.get_pins())

    @toolset_registry.tool_call
    @staticmethod
    def get_pin_value(
        control_rig: unreal.ControlRigBlueprint,
        pin: unreal.RigVMPin
    ) -> str:
        """Get the default value of a pin.

        Args:
            control_rig: The Control Rig containing the pin.
            pin: The pin to query.

        Returns:
            The pin's default value as a string.
        """
        return pin.get_default_value()

    @toolset_registry.tool_call
    @staticmethod
    def set_pin_value(
        control_rig: unreal.ControlRigBlueprint,
        graph: unreal.RigVMGraph,
        pin: unreal.RigVMPin,
        value: str
    ) -> None:
        """Set the default value of a pin.

        Args:
            control_rig: The Control Rig containing the graph.
            graph: The graph containing the pin's node.
            pin: The pin to modify.
            value: The new value as a string. Format depends on pin type:
                - float/double: "1.0"
                - int: "42"
                - bool: "true" or "false"
                - Vector: "(X=1.0,Y=2.0,Z=3.0)"
                - Rotator: "(Pitch=0.0,Yaw=90.0,Roll=0.0)"
                - Transform: "(Rotation=(X=0,Y=0,Z=0,W=1),Translation=(X=0,Y=0,Z=0),Scale3D=(X=1,Y=1,Z=1))"
                - Name/String: "MyValue"
                - Enum: "EnumValue" (without type prefix)
        """
        graph_name = graph.get_name()
        controller = control_rig.get_controller_by_name(graph_name)
        if not controller:
            raise ValueError(f"Cannot get controller for graph '{graph_name}'")
        if not controller.set_pin_default_value(pin.get_pin_path(), value, True, False, False):
            raise ValueError(
                f"Failed to set value '{value}' on pin '{pin.get_pin_path()}'"
            )

    @toolset_registry.tool_call
    @staticmethod
    def connect_pins(
        control_rig: unreal.ControlRigBlueprint,
        graph: unreal.RigVMGraph,
        source_pin: unreal.RigVMPin,
        target_pin: unreal.RigVMPin
    ) -> None:
        """Connect two pins together.

        Args:
            control_rig: The Control Rig containing the graph.
            graph: The graph containing the pins.
            source_pin: The source (output) pin.
            target_pin: The target (input) pin.
        """
        graph_name = graph.get_name()
        controller = control_rig.get_controller_by_name(graph_name)
        if not controller:
            raise ValueError(f"Cannot get controller for graph '{graph_name}'")
        if not controller.add_link(
            source_pin.get_pin_path(),
            target_pin.get_pin_path(),
            False  # setup_undo_redo
        ):
            raise ValueError(
                f"Failed to connect '{source_pin.get_pin_path()}' to "
                f"'{target_pin.get_pin_path()}'"
            )

    @toolset_registry.tool_call
    @staticmethod
    def disconnect_pins(
        control_rig: unreal.ControlRigBlueprint,
        graph: unreal.RigVMGraph,
        source_pin: unreal.RigVMPin,
        target_pin: unreal.RigVMPin
    ) -> None:
        """Disconnect two pins.

        Args:
            control_rig: The Control Rig containing the graph.
            graph: The graph containing the pins.
            source_pin: The source (output) pin.
            target_pin: The target (input) pin.
        """
        graph_name = graph.get_name()
        controller = control_rig.get_controller_by_name(graph_name)
        if not controller:
            raise ValueError(f"Cannot get controller for graph '{graph_name}'")
        if not controller.break_link(
            source_pin.get_pin_path(),
            target_pin.get_pin_path(),
            False  # setup_undo_redo
        ):
            raise ValueError(
                f"Failed to disconnect '{source_pin.get_pin_path()}' from "
                f"'{target_pin.get_pin_path()}'"
            )

    @toolset_registry.tool_call
    @staticmethod
    def get_connected_pins(
        control_rig: unreal.ControlRigBlueprint,
        pin: unreal.RigVMPin
    ) -> list[unreal.RigVMPin]:
        """Get all pins connected to this pin.

        Args:
            control_rig: The Control Rig containing the pin.
            pin: The pin to query.

        Returns:
            List of connected RigVMPin objects.
        """
        return list(pin.get_linked_source_pins()) + list(pin.get_linked_target_pins())

    # ========================================================================
    # Variable Operations
    # ========================================================================

    @toolset_registry.tool_call
    @staticmethod
    def add_variable(
        control_rig: unreal.ControlRigBlueprint,
        name: str,
        type_path: str,
        is_public: bool = True,
        is_read_only: bool = False,
        default_value: str = ''
    ) -> None:
        """Add a member variable to the Control Rig.

        Args:
            control_rig: The Control Rig to add the variable to.
            name: Variable name.
            type_path: UE type path (e.g., "double", "float",
                      "/Script/CoreUObject.Vector").
            is_public: Whether the variable is exposed publicly.
            is_read_only: Whether the variable is read-only.
            default_value: Default value as string.
        """
        try:
            control_rig.add_member_variable(
                name, type_path, is_public, is_read_only, default_value
            )
        except Exception as e:
            raise RuntimeError(f"Failed to add variable '{name}': {e}") from e

    @toolset_registry.tool_call
    @staticmethod
    def list_variables(
        control_rig: unreal.ControlRigBlueprint
    ) -> list[unreal.RigVMGraphVariableDescription]:
        """List all member variables in the Control Rig.

        Args:
            control_rig: The Control Rig to query.

        Returns:
            List of variable descriptions.
        """
        return list(control_rig.get_member_variables())

    @toolset_registry.tool_call
    @staticmethod
    def get_variable(
        control_rig: unreal.ControlRigBlueprint,
        name: str
    ) -> unreal.RigVMGraphVariableDescription:
        """Get a specific variable by name.

        Args:
            control_rig: The Control Rig to query.
            name: Variable name.

        Returns:
            The variable description.
        """
        variables = control_rig.get_member_variables()
        for var in variables:
            if var.get_editor_property('name') == name:
                return var
        raise ValueError(f"Variable '{name}' not found in Control Rig")

    @toolset_registry.tool_call
    @staticmethod
    def change_variable_type(
        control_rig: unreal.ControlRigBlueprint,
        name: str,
        new_type: str
    ) -> None:
        """Change the type of an existing variable.

        Args:
            control_rig: The Control Rig containing the variable.
            name: Variable name.
            new_type: New type path (e.g., "double", "float").
        """
        try:
            control_rig.change_member_variable_type(name, new_type)
        except Exception as e:
            raise RuntimeError(
                f"Failed to change type of variable '{name}' to '{new_type}': {e}"
            ) from e

    @toolset_registry.tool_call
    @staticmethod
    def remove_variable(
        control_rig: unreal.ControlRigBlueprint,
        name: str
    ) -> None:
        """Remove a member variable from the Control Rig.

        Args:
            control_rig: The Control Rig to modify.
            name: Variable name to remove.
        """
        try:
            control_rig.remove_member_variable(name)
        except Exception as e:
            raise RuntimeError(f"Failed to remove variable '{name}': {e}") from e

    # ========================================================================
    # Internal Helpers
    # ========================================================================

    @staticmethod
    def _get_hierarchy(control_rig: unreal.ControlRigBlueprint) -> unreal.RigHierarchy:
        """Get the RigHierarchy from a Control Rig blueprint."""
        if not control_rig:
            raise ValueError("Control Rig blueprint is None")
        return control_rig.hierarchy

    @staticmethod
    def _get_hierarchy_controller(
        control_rig: unreal.ControlRigBlueprint
    ) -> unreal.RigHierarchyController:
        """Get the RigHierarchyController from a Control Rig blueprint."""
        hierarchy = ControlRigTools._get_hierarchy(control_rig)
        controller = hierarchy.get_controller()
        if not controller:
            raise ValueError("Failed to get hierarchy controller")
        return controller

    @staticmethod
    def _find_graph_with_event(
        control_rig: unreal.ControlRigBlueprint,
        event_type: EventType
    ) -> str | None:
        """Find graph containing a specific event node."""
        models = control_rig.get_all_models()
        if not models:
            return None

        event_struct_name = _EVENT_STRUCT_NAMES[event_type]

        for model in models:
            graph_name = model.get_name()

            if graph_name == _RIGVM_FUNCTION_LIBRARY:
                continue

            try:
                controller = control_rig.get_controller_by_name(graph_name)
                if not controller:
                    continue

                graph = controller.get_graph()
                if not graph:
                    continue

                for node in graph.get_nodes():
                    node_obj = node.get_script_struct()
                    if node_obj and node_obj.get_name() == event_struct_name:
                        return graph_name
            except Exception:
                continue

        return None
