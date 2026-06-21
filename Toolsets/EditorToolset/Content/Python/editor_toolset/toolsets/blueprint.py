# Copyright Epic Games, Inc. All Rights Reserved.

# [5.7 port] Defer annotation evaluation (PEP 563) so tool methods/params that
# reference 5.8-only `unreal.*` types (e.g. K2Node_CreateDelegate,
# BlueprintFunctionInfo, BlueprintVariableReplication) don't raise AttributeError
# at class-definition time. tool_call() then skips just those tools on engines
# where the type is missing, letting the rest of the toolset register.
from __future__ import annotations

import collections
import dataclasses
import unreal

import toolset_registry
from toolset_registry.helpers import compile_blueprint, create_asset
from editor_toolset.toolsets import blueprint_dsl
from editor_toolset.toolsets.blueprint_layout import GraphFormatter
from editor_toolset.toolsets.blueprint_node import NodeInfo, PinID, PinInfo

_ENGINE_MACROS_PATH = '/Engine/EditorBlueprintResources/StandardMacros'
_ENGINE_MACROS_OBJECT = 'StandardMacros'
_DISPATCHER_PREFIX = 'Default|EventDispatcher'
_CUSTOM_EVENT_PREFIX = 'AddEvent|Custom|'


def _set_node_pos(node: unreal.EdGraphNode, x: int, y: int) -> None:
    # [5.7 port] EdGraphNode.set_node_pos() is 5.8-only, and node_pos_x/_y are not
    # reliably exposed as Python properties on 5.7. Node position is purely
    # cosmetic (graph layout) and create_node_from_name already places nodes at
    # the requested position, so try the available APIs and no-op if none work.
    x, y = int(x), int(y)
    try:
        node.set_node_pos(unreal.IntPoint(x, y))  # 5.8 API
        return
    except Exception:  # pylint: disable=broad-exception-caught
        pass
    for attr_x, attr_y in (('node_pos_x', 'node_pos_y'), ('NodePosX', 'NodePosY')):
        try:
            node.set_editor_property(attr_x, x)
            node.set_editor_property(attr_y, y)
            return
        except Exception:  # pylint: disable=broad-exception-caught
            pass


def _list_macro_graph_names(macro_blueprint: unreal.Blueprint) -> list[str]:
    # [5.7 port] unreal.BlueprintEditorLibrary.list_graph_names() is 5.8-only.
    # Read the macro library's macro graphs directly via reflection; fall back to
    # the 5.8 API if present, else degrade to no macros (non-macro nodes still work).
    try:
        return list(unreal.BlueprintEditorLibrary.list_graph_names(macro_blueprint))
    except Exception:  # pylint: disable=broad-exception-caught
        pass
    names: list[str] = []
    for prop in ('macro_graphs', 'MacroGraphs'):
        try:
            graphs = macro_blueprint.get_editor_property(prop)
        except Exception:  # pylint: disable=broad-exception-caught
            continue
        for g in graphs or []:
            try:
                names.append(g.get_name())
            except Exception:  # pylint: disable=broad-exception-caught
                pass
        if names:
            break
    return names


def _list_event_dispatcher_names(blueprint: unreal.Blueprint) -> list[str]:
    # [5.7 port] unreal.BlueprintEditorLibrary.list_event_dispatchers() is 5.8-only.
    # Degrade to none if unavailable (event-dispatcher nodes won't be offered).
    try:
        return list(unreal.BlueprintEditorLibrary.list_event_dispatchers(blueprint))
    except Exception:  # pylint: disable=broad-exception-caught
        return []


def _list_member_variable_names_compat(blueprint: unreal.Blueprint) -> list[str]:
    # [5.7 port] unreal.BlueprintEditorLibrary.list_member_variable_names() is
    # 5.8-only and UBlueprint.NewVariables is protected from Python reflection on
    # 5.7. The bundled BlueprintGraphEditorPort plugin provides a C++ UFUNCTION
    # that reads NewVariables directly; prefer it, then fall back to the 5.8 API.
    try:
        return [str(n) for n in unreal.BlueprintGraphEditor.list_member_variable_names(blueprint)]
    except Exception:  # pylint: disable=broad-exception-caught
        pass
    try:
        return [str(v) for v in unreal.BlueprintEditorLibrary.list_member_variable_names(blueprint, False)]
    except Exception:  # pylint: disable=broad-exception-caught
        pass
    names: list[str] = []
    for prop in ('new_variables', 'NewVariables'):
        try:
            variables = blueprint.get_editor_property(prop)
        except Exception:  # pylint: disable=broad-exception-caught
            continue
        for v in variables or []:
            try:
                names.append(str(v.get_editor_property('var_name')))
            except Exception:  # pylint: disable=broad-exception-caught
                pass
        if names:
            break
    return names


def _list_graph_objects_compat(blueprint: unreal.Blueprint) -> list:
    # [5.7 port] unreal.BlueprintEditorLibrary.list_graphs() is 5.8-only.
    # In 5.7, UBlueprint properties UbergraphPages / FunctionGraphs / MacroGraphs /
    # DelegateSignatureGraphs are all marked protected in the Python reflection layer
    # and cannot be read via get_editor_property().  The only reliable 5.7 fallback is
    # find_event_graph() which returns the single ubergraph (EventGraph).  Function
    # graphs, macro graphs, and delegate graphs are NOT enumerable from Python on 5.7
    # without a C++ UFUNCTION that calls UBlueprint::GetAllGraphs() -- which the
    # bundled BlueprintGraphEditorPort plugin now provides (preferred path below).
    try:
        graphs = list(unreal.BlueprintGraphEditor.list_all_graphs(blueprint))
        if graphs:
            return graphs
    except Exception:  # pylint: disable=broad-exception-caught
        pass
    try:
        return list(unreal.BlueprintEditorLibrary.list_graphs(blueprint))
    except Exception:  # pylint: disable=broad-exception-caught
        pass
    graphs: list = []
    # Attempt property access (works on 5.8 if the 5.8 API path above missed for
    # some reason; on 5.7 these silently fail and are skipped).
    for prop in ('ubergraph_pages', 'function_graphs', 'macro_graphs', 'delegate_signature_graphs'):
        try:
            for g in blueprint.get_editor_property(prop) or []:
                graphs.append(g)
        except Exception:  # pylint: disable=broad-exception-caught
            pass
    if graphs:
        return graphs
    # [5.7 port] Last resort: return at least the EventGraph so callers that only
    # need "some graph to introspect" can proceed.  find_event_graph() is available
    # in both 5.7 and 5.8.
    try:
        event_graph = unreal.BlueprintEditorLibrary.find_event_graph(blueprint)
        if event_graph is not None:
            graphs.append(event_graph)
    except Exception:  # pylint: disable=broad-exception-caught
        pass
    return graphs


def _node_title(node: unreal.EdGraphNode) -> str:
    # [5.7 port] EdGraphNode.get_node_title() is 5.8-only. Fall back to the node's
    # class name (minus the K2Node_ prefix) so introspection degrades instead of
    # crashing.
    try:
        return ''.join(node.get_node_title().split())
    except Exception:  # pylint: disable=broad-exception-caught
        return type(node).__name__.replace('K2Node_', '')


def _node_category(node: unreal.EdGraphNode) -> str:
    # [5.7 port] EdGraphNode.get_node_category() is 5.8-only.
    try:
        return ''.join(node.get_node_category().split())
    except Exception:  # pylint: disable=broad-exception-caught
        return ''


def _get_node_pos(node: unreal.EdGraphNode) -> unreal.IntPoint:
    # [5.7 port] EdGraphNode.get_node_pos() is 5.8-only; read node_pos_x/_y if
    # available, else default to the origin (position is cosmetic).
    try:
        return node.get_node_pos()
    except Exception:  # pylint: disable=broad-exception-caught
        pass
    for attr_x, attr_y in (('node_pos_x', 'node_pos_y'), ('NodePosX', 'NodePosY')):
        try:
            return unreal.IntPoint(
                int(node.get_editor_property(attr_x)), int(node.get_editor_property(attr_y)))
        except Exception:  # pylint: disable=broad-exception-caught
            pass
    return unreal.IntPoint(0, 0)


def _get_node_type_id(node: unreal.EdGraphNode) -> str:
    node_title = _node_title(node)
    if isinstance(node, unreal.K2Node_CustomEvent):
        return f'{_CUSTOM_EVENT_PREFIX}{node_title}'
    node_category = _node_category(node)
    return f'{node_category}|{node_title}'


@dataclasses.dataclass
class _CacheEntry:
    fingerprint: str
    type_ids_by_category: dict[str, list[str]] = dataclasses.field(
        default_factory=lambda: collections.defaultdict(list))


class _BlueprintCache:
    """Caches for blueprint node type lookups.

    Class Attributes:
        _macros: a global mapping of type_id -> asset path for engine macro nodes.
            Built once on first use; macros never change at runtime.
        _graph_node_types: A per-graph mapping keyed by graph path name (string) to
            avoid holding strong references to UObjects. Each entry stores a
            fingerprint of the blueprint's structural state so that UI-side changes
            (adding/removing variables or graphs) are detected automatically on the
            next lookup.
    """

    _macros: dict[str, str] | None = None
    _graph_node_types: dict[str, _CacheEntry] = {}

    @classmethod
    def get_macros(cls, graph: unreal.EdGraph) -> dict[str, str]:
        """Returns a mapping of type_id -> asset path for all engine macro nodes.

        Built once on first use by temporarily spawning and removing each macro
        node. The graph argument is only needed to obtain a BlueprintGraphEditor.
        """
        if cls._macros is not None:
            return cls._macros
        cls._macros = {}
        bp = unreal.load_asset(_ENGINE_MACROS_PATH, unreal.Blueprint)
        if not isinstance(bp, unreal.Blueprint):
            return cls._macros
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        for name in _list_macro_graph_names(bp):
            path = f'{_ENGINE_MACROS_PATH}.{_ENGINE_MACROS_OBJECT}.{name}'
            node = bp_editor.add_macro_node(path)  # type: ignore
            if isinstance(node, unreal.EdGraphNode):
                cls._macros[_get_node_type_id(node)] = path
                bp_editor.remove_nodes([node])
        return cls._macros

    @classmethod
    def list_nodes(cls, graph: unreal.EdGraph, resolved_pins: list = []) -> list[str]:
        """Returns all available node type_ids for the graph, including engine macros.

        resolved_pins should be a list of unreal.BlueprintGraphPin objects already
        resolved via _resolve_pin. Pass an empty list (the default) for the
        unconstrained case.
        """
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        nodes = list(bp_editor.list_available_nodes(resolved_pins))  # type: ignore
        nodes += list(cls.get_macros(graph).keys())
        return nodes

    @classmethod
    def get(cls, graph: unreal.EdGraph) -> dict[str, list[str]]:
        """Returns a dict mapping category -> list[type_id] for the graph.

        Validates the fingerprint on every call. Rebuilds from the UE API when
        the fingerprint differs (UI edit) or no entry exists yet.
        """
        graph_key = graph.get_path_name()
        fingerprint = cls._fingerprint(graph)
        entry = cls._graph_node_types.get(graph_key)
        if entry is not None:
            if entry.fingerprint == fingerprint:
                return entry.type_ids_by_category
            # Stale fingerprint - invalidate all graphs for this blueprint since
            # the structural change affects every graph (e.g. a new variable adds
            # getter/setter nodes to all of them).
            blueprint = unreal.Blueprint.cast(graph.get_outer())
            if blueprint:
                cls.invalidate(blueprint)
        entry = _CacheEntry(fingerprint=fingerprint)
        for node in cls.list_nodes(graph):
            entry.type_ids_by_category['|'.join(node.split('|')[:-1])].append(node)
        # Event dispatchers don't appear in list_available_nodes, so we inject them manually
        # under Default|EventDispatcher{name} type_id.
        blueprint = unreal.Blueprint.cast(graph.get_outer())
        if blueprint:
            for name in _list_event_dispatcher_names(blueprint):
                entry.type_ids_by_category['Default'].append(f'{_DISPATCHER_PREFIX}{name}')
        cls._graph_node_types[graph_key] = entry
        return entry.type_ids_by_category

    @classmethod
    def invalidate(cls, blueprint: unreal.Blueprint) -> None:
        """Removes all node-type cache entries for graphs belonging to the blueprint.

        Graph path names are in the form '<blueprint_path>:<graph_name>', so a
        prefix match covers all of a blueprint's graphs at once.
        """
        bp_path = blueprint.get_path_name()
        for key in list(cls._graph_node_types.keys()):
            if key.startswith(bp_path):
                del cls._graph_node_types[key]

    @classmethod
    def canonicalize(cls, graph: unreal.EdGraph, type_id: str) -> str:
        """Returns the correctly-cased type_id via case-insensitive lookup, or the original if not found."""
        lower = type_id.lower()
        for k in cls.get_macros(graph):
            if k.lower() == lower:
                return k
        cache = cls.get(graph)
        if '|' in lower:
            cat_hint = lower.rsplit('|', 1)[0]
            buckets = [nodes for cat, nodes in cache.items() if cat_hint in cat.lower()]
        else:
            buckets = list(cache.values())
        for nodes in buckets:
            for n in nodes:
                if n.lower() == lower:
                    return n
        return type_id

    @staticmethod
    def _fingerprint(graph: unreal.EdGraph) -> str:
        """Returns a string capturing the structural state of the owning blueprint.

        Includes sorted variable names and graph names. Cheap to compute (no node
        enumeration), and changes whenever the user adds/removes variables or graphs
        in the UI - the two operations that affect the available-nodes list.
        """
        blueprint = unreal.Blueprint.cast(graph.get_outer())
        if not blueprint:
            return ''
        var_names = sorted(_list_member_variable_names_compat(blueprint))
        graph_names = sorted(g.get_name() for g in _list_graph_objects_compat(blueprint))
        return f'{var_names}|{graph_names}'


@unreal.uenum()
class ContainerType(unreal.EnumBase):
    """Container type for Blueprint variables and function parameters."""
    ARRAY = unreal.uvalue(1)
    SET = unreal.uvalue(2)
    MAP = unreal.uvalue(3)


@unreal.uclass()
class BlueprintTools(unreal.ToolsetDefinition):
    """Provides tools for working with Blueprints."""

    @toolset_registry.tool_call
    @staticmethod
    def create(folder_path: str, asset_name: str, asset_type: unreal.Class) -> unreal.Blueprint:
        """Creates a new Blueprint asset in the project.

        Args:
            folder_path: The path to the folder that will contain the asset.
            asset_name: The name of the asset in the folder.
            asset_type: The specific kind of Blueprint to make.

        Returns:
            The Blueprint that was created.
        """
        assert unreal.MathLibrary.class_is_child_of(asset_type, unreal.Object.static_class()), (
            f'{asset_type} cannot be stored in a Blueprint.')
        factory = unreal.BlueprintFactory()
        factory.set_editor_property('parent_class', asset_type)
        blueprint = create_asset(
            folder_path, asset_name, unreal.Blueprint.static_class(), factory)
        assert isinstance(blueprint, unreal.Blueprint), f'Could not create Blueprint {asset_name}'
        return blueprint

    @toolset_registry.tool_call
    @staticmethod
    def compile_blueprint(blueprint: unreal.Blueprint, warnings_as_errors: bool = False) -> None:
        """
        Compiles the given Blueprint.

        Blueprints should be compiled after all graph modifications are complete.

        Args:
            blueprint: The Blueprint to compile.
            warnings_as_errors: If True, raise on compile warnings as well as errors.
                Defaults to False.
        """
        compile_blueprint(blueprint, warnings_as_errors)

    @toolset_registry.tool_call
    @staticmethod
    def get_default_object(blueprint: unreal.Blueprint) -> unreal.Object:
        """Returns the Class Default Object (CDO) for a Blueprint's.

        ObjectTools list/set/get property will get the CDO automatically, so this
        should primarily be used before calling tools that want to operate on the
        object inside the blueprint (like ActorTools).

        Note: The Blueprint must be compiled for the CDO to reflect the latest state.

        Args:
            blueprint: The Blueprint whose CDO to retrieve.

        Returns:
            The Class Default Object for the Blueprint's generated class.
        """
        return unreal.get_default_object(blueprint.generated_class())

    @toolset_registry.tool_call
    @staticmethod
    def list_graphs(blueprint: unreal.Blueprint) -> list[unreal.EdGraph]:
        """
        Lists all graphs in the Blueprint.

        Args:
            blueprint: The Blueprint asset with the graphs to list.

        Returns:
            list of graphs in the Blueprint.
        """
        # [5.7 port] unreal.BlueprintEditorLibrary.list_graphs() is 5.8-only; use compat helper.
        return _list_graph_objects_compat(blueprint)

    @toolset_registry.tool_call
    @staticmethod
    def get_graph(blueprint: unreal.Blueprint, graph_name: str) -> unreal.EdGraph:
        """
         Retrieves a specific graph from a Blueprint asset by name.

        Args:
            blueprint: The Blueprint asset to search within.
            graph_name: The name of the graph to retrieve (e.g., "EventGraph", "MyFunction")

        Returns:
            The graph object matching the specified name.
        """
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor_by_name(
            blueprint, unreal.Name(graph_name))
        assert bp_editor, f'Cannot find graph {graph_name} in Blueprint {blueprint}'
        return bp_editor.get_graph()

    # [5.7 port] unreal.BlueprintFunctionInfo is 5.8-only
    # (and BlueprintEditorLibrary.list_functions/list_events do not exist in 5.7).
    # @toolset_registry.tool_call
    # @staticmethod
    # def list_functions(blueprint: unreal.Blueprint) -> list[unreal.BlueprintFunctionInfo]:
    #     """Lists all functions visible on the Blueprint — locally defined plus
    #     inheritable ones from the parent class chain and implemented interfaces.
    #
    #     Args:
    #         blueprint: The Blueprint asset to query.
    #     """
    #     return list(unreal.BlueprintEditorLibrary.list_functions(blueprint))

    # [5.7 port] unreal.BlueprintFunctionInfo is 5.8-only
    # @toolset_registry.tool_call
    # @staticmethod
    # def list_events(blueprint: unreal.Blueprint) -> list[unreal.BlueprintFunctionInfo]:
    #     """Lists all events visible on the Blueprint — locally defined custom events
    #     plus inheritable events from the parent class chain and implemented interfaces.
    #
    #     Args:
    #         blueprint: The Blueprint asset to query.
    #     """
    #     return list(unreal.BlueprintEditorLibrary.list_events(blueprint))

    @toolset_registry.tool_call
    @staticmethod
    def add_function_graph(blueprint: unreal.Blueprint, graph_name: str) -> unreal.EdGraph:
        """Adds a function graph to the Blueprint.

        If graph_name matches an inherited overridable function, the new graph is a
        function-graph override of that function. Idempotent — if a graph with that
        name already exists, that graph is returned.

        Args:
            blueprint: The Blueprint asset to add the function to.
            graph_name: The name of the new function graph.
        """
        # [5.7 port] list_events/list_functions and add_function_override are
        # 5.8-only; inherited-override detection is unavailable in 5.7, so we
        # fall through to creating a plain new function graph.
        for g in BlueprintTools.list_graphs(blueprint):
            if g.get_name() == graph_name:
                return g
        graph = unreal.BlueprintEditorLibrary.add_function_graph(blueprint, graph_name)
        _BlueprintCache.invalidate(blueprint)
        return graph

    @toolset_registry.tool_call
    @staticmethod
    def add_event(blueprint: unreal.Blueprint, event_name: str,
                  position: unreal.IntPoint = unreal.IntPoint(0, 0)) -> unreal.EdGraphNode:
        """Adds an event node to the Blueprint's event graph.

        If event_name matches an inherited overridable event, the new node is an
        override of that event. Otherwise a new custom event with the given name is
        created. Idempotent — if an event node with that name already exists,
        that node is returned.

        Args:
            blueprint: The Blueprint asset to add the event to.
            event_name: The name of an inherited event to override (e.g.
                'ReceiveAnyDamage') or a name for a new custom event.
            position: Position of the new node in the event graph.

        Returns:
            The event node.
        """
        # [5.7 port] list_events/list_functions and add_event_override are
        # 5.8-only; inherited-event override detection is unavailable in 5.7.
        # Detect an already-placed event node by name, otherwise create a new
        # custom event.
        event_graph = unreal.BlueprintEditorLibrary.find_event_graph(blueprint)
        if not event_graph:
            raise RuntimeError(f'Blueprint {blueprint} has no event graph.')
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(event_graph)
        existing = bp_editor.find_event_node(unreal.Name(event_name))  # type: ignore
        if existing:
            return existing
        node = BlueprintTools.create_node(
            event_graph, f'{_CUSTOM_EVENT_PREFIX}{event_name}', position)
        _BlueprintCache.invalidate(blueprint)
        return node

    @toolset_registry.tool_call
    @staticmethod
    def remove_function_graph(blueprint: unreal.Blueprint, graph_name: str) -> None:
        """
        Removes a function graph or event dispatcher from the Blueprint.

        Note: This will close the Blueprint editor window if it is currently open.

        Args:
            blueprint: The Blueprint asset to remove the function graph from.
            graph_name: The name of the function or dispatcher to remove.
        """
        graphs = BlueprintTools.list_graphs(blueprint)
        if not (graph_name in [g.get_name() for g in graphs]):
            raise RuntimeError(f'Graph {graph_name} does not exist')
        dispatcher_names = _list_event_dispatcher_names(blueprint)  # [5.7 port] list_event_dispatchers is 5.8-only
        if graph_name in dispatcher_names:
            if not unreal.BlueprintEditorLibrary.remove_event_dispatcher(blueprint, unreal.Name(graph_name)):
                raise RuntimeError(f'Event dispatcher "{graph_name}" not found in {blueprint}.')
            _BlueprintCache.invalidate(blueprint)
            return
        unreal.BlueprintEditorLibrary.remove_function_graph(blueprint, graph_name)
        _BlueprintCache.invalidate(blueprint)

    @toolset_registry.tool_call
    @staticmethod
    def add_function_param(
            graph: unreal.EdGraph,
            param_name: str,
            param_type: str,
            input_param: bool,
            container_type: ContainerType | None = None) -> PinID:
        """
        Adds an input or output to a function or event dispatcher

        Note: output params are not supported on event dispatchers.

        Supported parameter types:
          Primitives: 'bool', 'int', 'float', 'byte', 'string', 'name', 'text'
          Structs:    'Vector', 'Rotator', 'Transform', 'Vector2D', 'LinearColor'

        Args:
            graph: The function or event dispatcher graph to add the parameter to.
            param_name: The name of the new parameter.
            param_type: The parameter type as a string (see above).
            input_param: True to add an input param, false to add an output.
            container_type: Container type for the parameter. MAP uses string as the key type.

        Returns:
            The PinID of the newly created parameter.
        """
        pin_type = BlueprintTools._make_variable_type(param_type)
        pin_type = BlueprintTools._apply_container(pin_type, container_type)
        if BlueprintTools._is_dispatcher_graph(graph):
            BlueprintTools._assert_dispatcher_input_only(graph, input_param)
            if BlueprintTools._param_name_exists(graph, param_name, True):
                raise RuntimeError(f'Param {param_name} already exists!')
            return BlueprintTools._add_dispatcher_param(graph, param_name, pin_type)
        if BlueprintTools._param_name_exists(graph, param_name, input_param):
            raise RuntimeError(f'Param {param_name} already exists!')
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        if input_param:
            pin = bp_editor.add_graph_input_parameter(param_name, pin_type)
        else:
            result_node = bp_editor.add_graph_output_parameter(param_name, pin_type)
            node_info = BlueprintTools._get_node_info(result_node)
            pin_info = next((p for p in node_info.input_pins if p.name == param_name), None)
            pin = BlueprintTools._resolve_pin(pin_info.pin_id)
        return BlueprintTools._pin_to_id(pin)

    @toolset_registry.tool_call
    @staticmethod
    def remove_function_param(graph: unreal.EdGraph, param_name: str, input_param: bool) -> None:
        """
        Removes an input or output from a function or event dispatcher.

        Note: output params are not supported on event dispatchers.

        Args:
            graph: The function or event dispatcher graph to remove the param from.
            param_name: The name of the param to remove.
            input_param: True to remove an input param, False to remove an output.
        """
        if BlueprintTools._is_dispatcher_graph(graph):
            BlueprintTools._assert_dispatcher_input_only(graph, input_param)
            if not BlueprintTools._param_name_exists(graph, param_name, True):
                raise RuntimeError(f'Param {param_name} does not exist!')
            blueprint = unreal.Blueprint.cast(graph.get_outer())
            if not unreal.BlueprintEditorLibrary.remove_event_dispatcher_parameter(
                    blueprint, unreal.Name(graph.get_name()), unreal.Name(param_name)):
                raise RuntimeError(
                    f'Failed to remove parameter "{param_name}" from dispatcher "{graph.get_name()}".')
            return
        if not BlueprintTools._param_name_exists(graph, param_name, input_param):
            raise RuntimeError(f'Param {param_name} does not exist!')
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        if input_param:
            if not bp_editor.remove_graph_input_parameter(param_name):
                raise RuntimeError(f'Failed to remove input param "{param_name}".')
        else:
            if not bp_editor.remove_graph_output_parameter(param_name):
                raise RuntimeError(f'Failed to remove output param "{param_name}".')

    @toolset_registry.tool_call
    @staticmethod
    def add_struct_function_param(
            graph: unreal.EdGraph,
            param_name: str,
            struct_type: unreal.ScriptStruct,
            input_param: bool,
            container_type: ContainerType | None = None) -> PinID:
        """Adds a struct input or output to a function or event dispatcher.

        Note: output params are not supported on event dispatchers.

        Use this to add parameters of any UStruct type, including custom structs and engine
        structs not in the basic list supported by add_function_param (e.g. HitResult, GameplayTag).

        Args:
            graph: The function or event dispatcher graph to add the parameter to.
            param_name: The name of the new parameter.
            struct_type: The struct type for this parameter.
            input_param: True to add an input param, false to add an output.
            container_type: Container type for the parameter. MAP uses string as the key type.

        Returns:
            The PinID of the newly created parameter.
        """
        pin_type = unreal.BlueprintEditorLibrary.get_struct_type(struct_type)
        pin_type = BlueprintTools._apply_container(pin_type, container_type)
        if BlueprintTools._is_dispatcher_graph(graph):
            BlueprintTools._assert_dispatcher_input_only(graph, input_param)
            if BlueprintTools._param_name_exists(graph, param_name, True):
                raise RuntimeError(f'Param {param_name} already exists!')
            return BlueprintTools._add_dispatcher_param(graph, param_name, pin_type)
        if BlueprintTools._param_name_exists(graph, param_name, input_param):
            raise RuntimeError(f'Param {param_name} already exists!')
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        if input_param:
            pin = bp_editor.add_graph_input_parameter(param_name, pin_type)
        else:
            result_node = bp_editor.add_graph_output_parameter(param_name, pin_type)
            node_info = BlueprintTools._get_node_info(result_node)
            pin_info = next((p for p in node_info.input_pins if p.name == param_name), None)
            pin = BlueprintTools._resolve_pin(pin_info.pin_id)
        return BlueprintTools._pin_to_id(pin)

    @toolset_registry.tool_call
    @staticmethod
    def add_object_function_param(
            graph: unreal.EdGraph,
            param_name: str,
            object_class: unreal.Class,
            input_param: bool,
            container_type: ContainerType | None = None) -> PinID:
        """Adds an object reference input or output to a function or event dispatcher.

        Note: output params are not supported on event dispatchers.

        Args:
            graph: The function or event dispatcher graph to add the param to.
            param_name: The name of the new param.
            object_class: The class of object this param will reference.
            input_param: True to add an input param, false to add an output.
            container_type: Container type for the param. MAP uses string as the key type.
        Returns:
            The PinID of the newly created param.
        """
        pin_type = unreal.BlueprintEditorLibrary.get_object_reference_type(object_class)
        pin_type = BlueprintTools._apply_container(pin_type, container_type)
        if BlueprintTools._is_dispatcher_graph(graph):
            BlueprintTools._assert_dispatcher_input_only(graph, input_param)
            if BlueprintTools._param_name_exists(graph, param_name, True):
                raise RuntimeError(f'Param {param_name} already exists!')
            return BlueprintTools._add_dispatcher_param(graph, param_name, pin_type)
        if BlueprintTools._param_name_exists(graph, param_name, input_param):
            raise RuntimeError(f'Param {param_name} already exists!')
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        if input_param:
            pin = bp_editor.add_graph_input_parameter(param_name, pin_type)
        else:
            result_node = bp_editor.add_graph_output_parameter(param_name, pin_type)
            node_info = BlueprintTools._get_node_info(result_node)
            pin_info = next((p for p in node_info.input_pins if p.name == param_name), None)
            pin = BlueprintTools._resolve_pin(pin_info.pin_id)
        return BlueprintTools._pin_to_id(pin)

    @staticmethod
    def _list_all_pins_compat(node: unreal.EdGraphNode) -> list[unreal.BlueprintGraphPin]:
        # [5.7 port] EdGraphNode.list_all_pins() is 5.8-only. The bundled
        # BlueprintGraphEditorPort plugin provides UBlueprintGraphPinLibrary.list_node_pins(),
        # which wraps the node's native pins (Node->Pins is public C++) as
        # FBlueprintGraphPin proxies — restoring full pin enumeration on 5.7.
        try:
            return list(node.list_all_pins())  # 5.8 native method, if present
        except AttributeError:
            pass
        except Exception:  # pylint: disable=broad-exception-caught
            pass
        try:
            return list(unreal.BlueprintGraphPinLibrary.list_node_pins(node))
        except Exception:  # pylint: disable=broad-exception-caught
            pass
        return []

    @staticmethod
    def _list_pins(node: unreal.EdGraphNode, direction: unreal.EdGraphPinDirection) -> list[unreal.BlueprintGraphPin]:
        # [5.7 port] node.list_all_pins() is 5.8-only; route through compat helper.
        return [p for p in BlueprintTools._list_all_pins_compat(node) if p.get_pin_direction() == direction]

    @staticmethod
    def _resolve_pin(pin_id: PinID) -> unreal.BlueprintGraphPin:
        # [5.7 port] On 5.7 the FBlueprintGraphPin struct fields cannot be set from Python,
        # so we cannot reconstruct a pin from a PinID without list_all_pins.
        # Fall back to enumerating pins; this works on 5.8 and degrades on 5.7 for nodes
        # where list_all_pins is unavailable (raises RuntimeError so the caller can catch).
        pins = BlueprintTools._list_pins(pin_id.node, pin_id.direction)
        if pin_id.index_id >= len(pins):
            raise RuntimeError(
                f'PinID index_id {pin_id.index_id} out of range for node {pin_id.node} '
                f'(found {len(pins)} pins; on UE 5.7 pin enumeration requires a ListAllPins '
                f'UFUNCTION in the BlueprintGraphEditorPort plugin)')
        return pins[pin_id.index_id]

    @staticmethod
    def _pin_to_id(pin: unreal.BlueprintGraphPin) -> PinID:
        # [5.7 port] FBlueprintGraphPin.pin_index is not accessible from Python.
        # Fall back to scanning _list_pins to find the index by pin name.
        # On 5.7 this also fails for nodes where list_all_pins is unavailable,
        # causing StopIteration; tools that return PinIDs will surface this error.
        node = pin.get_owning_node()
        direction = pin.get_pin_direction()
        pin_id = PinID()
        pin_id.node = node
        pin_id.direction = direction
        # Cache pin_name for potential future use by _resolve_pin (if C++ support added)
        try:
            pin_id.pin_name = str(pin.get_pin_name())
        except Exception:  # pylint: disable=broad-exception-caught
            pin_id.pin_name = ''
        pin_id.index_id = next(
            i for i, p in enumerate(BlueprintTools._list_pins(node, direction))
            if p.get_pin_name() == pin.get_pin_name()
        )
        return pin_id

    @staticmethod
    def _param_name_exists(function_graph: unreal.EdGraph, param_name: str, input_param: bool) -> bool:
        node_infos = BlueprintTools.get_node_infos(BlueprintTools.find_nodes(function_graph))
        if input_param:
            type_id = '|' + function_graph.get_name()
            input_node = next((node for node in node_infos if node.type_id == type_id), None)
            if input_node:
                return param_name in [pin.name for pin in input_node.output_pins]
        else:
            type_id = '|ReturnNode'
            result_node = next((node for node in node_infos if node.type_id == type_id), None)
            if result_node:
                return param_name in [pin.name for pin in result_node.input_pins]
        return False

    @toolset_registry.tool_call
    @staticmethod
    def get_node_infos(nodes: list[unreal.EdGraphNode]) -> list[NodeInfo]:
        """Retrieves detailed information for a list of Blueprint graph nodes.

        Args:
            nodes: The graph nodes to retrieve information from.

        Returns:
            Information about each node, including type, pins, connections, and position.
        """
        return [BlueprintTools._get_node_info(node) for node in nodes]

    @staticmethod
    def _get_node_info(node: unreal.EdGraphNode) -> NodeInfo:
        """Returns type_id, position, and pin info for a single node."""
        node_info = NodeInfo()
        node_info.type_id = _get_node_type_id(node)
        node_info.node = node
        node_info.position = _get_node_pos(node)
        for direction, bucket in (
            (unreal.EdGraphPinDirection.EGPD_INPUT, node_info.input_pins),
            (unreal.EdGraphPinDirection.EGPD_OUTPUT, node_info.output_pins),
        ):
            for pin in BlueprintTools._list_pins(node, direction):
                pin_info = PinInfo()
                pin_info.name = pin.get_pin_name()
                pin_info.type_id = str(pin.get_pin_type_display_string())
                pin_info.pin_id = BlueprintTools._pin_to_id(pin)
                for connected_pin in pin.list_connected_pins():
                    pin_info.connected_pins.append(BlueprintTools._pin_to_id(connected_pin)) # type: ignore
                pin_info.value = pin.get_pin_value()
                bucket.append(pin_info) # type: ignore
        return node_info

    @toolset_registry.tool_call
    @staticmethod
    def get_create_event_function(node: unreal.EdGraphNode) -> str:
        """Returns the function currently bound to a Create Event node.

        Args:
            node: The Create Event node (a K2Node_CreateDelegate).

        Returns:
            The bound function name, or empty string if none is set.
        """
        # [5.7 port] unreal.K2Node_CreateDelegate and the 5.8
        # BlueprintEditorLibrary.get_create_delegate_function are not exposed on 5.7;
        # the bundled BlueprintGraphEditorPort plugin provides the operation as a
        # compat shim that Cast<UK2Node_CreateDelegate>s the node internally.
        BlueprintTools._ensure_create_delegate_node(node)
        return str(unreal.EditorToolsetCompatLibrary.get_create_delegate_function(node))

    @toolset_registry.tool_call
    @staticmethod
    def set_create_event_function(node: unreal.EdGraphNode, function_name: str) -> None:
        """Binds a function to a Create Event node.

        Use list_compatible_event_functions to find valid function names.

        Args:
            node: The Create Event node (a K2Node_CreateDelegate).
            function_name: The name of the function to bind.
        """
        BlueprintTools._ensure_create_delegate_node(node)
        compatible = BlueprintTools.list_compatible_event_functions(node)
        if function_name not in compatible:
            raise RuntimeError(
                f'"{function_name}" is not a compatible function. '
                f'Valid functions: {compatible}')
        if not unreal.EditorToolsetCompatLibrary.set_create_delegate_function(node, function_name):
            raise RuntimeError(f'Failed to bind "{function_name}" to the Create Event node.')

    @toolset_registry.tool_call
    @staticmethod
    def list_compatible_event_functions(node: unreal.EdGraphNode) -> list[str]:
        """Lists functions that can be bound to a Create Event node.

        Args:
            node: The Create Event node (a K2Node_CreateDelegate).

        Returns:
            A list of function names valid for binding.
        """
        BlueprintTools._ensure_create_delegate_node(node)
        BlueprintTools._ensure_delegate_connected(node)
        return [str(n) for n in
                unreal.EditorToolsetCompatLibrary.list_compatible_functions_for_delegate(node)]

    @toolset_registry.tool_call
    @staticmethod
    def find_nodes(
            graph: unreal.EdGraph,
            title: str = '',
            node_class: unreal.Class | None = None,
            entry_points_only: bool = False) -> list[unreal.EdGraphNode]:
        """Finds nodes in a graph by title, class, and/or execution role.

        All filters are optional and ANDed together. Useful for locating specific
        event chains in large graphs like EventGraph before reading them with
        get_connected_subgraph.

        Args:
            graph: The graph to search.
            title: Case-insensitive substring to match against the node's displayed
                title. Pass an empty string to match any title.
            node_class: If provided, only returns nodes that are instances of this
                class or its subclasses.
            entry_points_only: If True, only returns entry point nodes - nodes with
                an exec output but no exec input (event nodes, function entry nodes,
                macro input tunnels, etc.). Nothing can drive these nodes; they
                start execution themselves.

        Returns:
            All nodes in the graph matching the given filters.
        """
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        title_lower = title.lower()
        results = []
        for node in bp_editor.list_all_nodes():
            if title_lower and title_lower not in node.get_node_title().lower():
                continue
            if node_class and not unreal.MathLibrary.class_is_child_of(node.get_class(), node_class):
                continue
            if entry_points_only:
                # [5.7 port] find_then_pin()/find_execute_pin() are 5.8-only methods.
                # Probe via _list_all_pins_compat: an entry point has a 'then' output
                # but no 'execute' input.
                try:
                    has_then = node.find_then_pin().is_valid()
                    has_execute = node.find_execute_pin().is_valid()
                except AttributeError:
                    out_names = {str(p.get_pin_name()) for p in BlueprintTools._list_pins(node, unreal.EdGraphPinDirection.EGPD_OUTPUT)}
                    in_names = {str(p.get_pin_name()) for p in BlueprintTools._list_pins(node, unreal.EdGraphPinDirection.EGPD_INPUT)}
                    has_then = 'then' in out_names
                    has_execute = 'execute' in in_names
                if not (has_then and not has_execute):
                    continue
            results.append(node)
        return results

    @toolset_registry.tool_call
    @staticmethod
    def get_connected_subgraph(node: unreal.EdGraphNode) -> list[NodeInfo]:
        """Returns detailed information for all nodes connected to the given node.

        Use this alongside find_nodes to read a single event chain from a large graph
        (like Event Graph) without reading the entire graph.

        Args:
            node: The starting node.

        Returns:
            Every node reachable from the given node via any connection, including
            the starting node itself.
        """
        visited: dict[str, unreal.EdGraphNode] = {}
        queue = [node]
        while queue:
            current = queue.pop()
            key = current.get_path_name()
            if key in visited:
                continue
            visited[key] = current
            for pin in BlueprintTools._list_all_pins_compat(current):  # [5.7 port] list_all_pins() is 5.8-only
                for connected_pin in pin.list_connected_pins():
                    neighbour = connected_pin.get_owning_node()
                    if neighbour.get_path_name() not in visited:
                        queue.append(neighbour)
        return [BlueprintTools._get_node_info(n) for n in visited.values()]

    @toolset_registry.tool_call
    @staticmethod
    def find_node_types(graph: unreal.EdGraph, type_id_filter: str, context_pins: list[PinID] = []) -> list[str]:
        """Finds node types that can be created in a particular graph meeting the search criteria.

        Note: there can be thousands of valid node types in a graph, so type_id_filter should be
        reasonably specific even if that requires multiple searches.

        To list all nodes within a category, use a trailing pipe: e.g. 'Utilities|FlowControl|'
        returns every node under that category. Without the trailing pipe, 'Utilities|FlowControl'
        also matches any node whose type_id contains that substring (such as a node with category
        'Utilities' and title 'FlowControl').

        Args:
            graph: the graph to make the search for
            type_id_filter: Substring to match against the node type_id (case-insensitive)
            context_pins: If set, only returns nodes whose pin types match those specified in this list

        Returns:
            Returns nodes that match the input criteria
        """
        filter_lower = type_id_filter.lower()
        if context_pins:
            resolved = [BlueprintTools._resolve_pin(p) for p in context_pins]
            all_nodes = _BlueprintCache.list_nodes(graph, resolved)
            return [n for n in all_nodes if filter_lower in n.lower()]
        cache = _BlueprintCache.get(graph)
        if '|' in filter_lower:
            cat_hint = filter_lower.rsplit('|', 1)[0]
            buckets = [nodes for cat, nodes in cache.items() if cat_hint in cat.lower()]
        else:
            buckets = list(cache.values())
        return [n for nodes in buckets for n in nodes if filter_lower in n.lower()]

    @toolset_registry.tool_call
    @staticmethod
    def get_node_type_pins(graph: unreal.EdGraph, type_id: str) -> NodeInfo:
        """Returns the pin names and types for a node type.

        Args:
            graph: The graph context used to resolve the node type.
            type_id: A node type_id as returned by find_node_types.

        Returns:
            NodeInfo with input_pins and output_pins listing each pin's name and type.
        """
        # TODO: We should replace this with a query of the action database for nodes.
        node = BlueprintTools.create_node(graph, type_id, unreal.IntPoint(0, 0))
        try:
            return BlueprintTools._get_node_info(node)
        finally:
            bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
            bp_editor.remove_nodes([node])

    @toolset_registry.tool_call
    @staticmethod
    def find_node_categories(graph: unreal.EdGraph, category_filter: str = '', context_pins: list[PinID] = []) -> list[str]:
        """Retrieves a list of available node categories in a Blueprint graph, optionally filtered by compatible input and/or output pin types

        Note: Categories are everything before the last | character in a node type id (eg 'Utilities|Operators' in the 'Utilities|Operators|Add' type id)

        Args:
            graph: the graph to make the search for
            category_filter: Substring to match against the node categories (case-insensitive). Pass an empty string to return all categories.
            context_pins: If set, only returns categories with nodes whose pin types match those specified in this list

        Returns:
            Returns node categories that match the input criteria
        """
        filter_lower = category_filter.lower()
        if context_pins:
            resolved = [BlueprintTools._resolve_pin(p) for p in context_pins]
            all_nodes = _BlueprintCache.list_nodes(graph, resolved)
            seen: set[str] = set()
            categories: list[str] = []
            for node in all_nodes:
                category = '|'.join(node.split('|')[:-1])
                if category not in seen:
                    seen.add(category)
                    if filter_lower in category.lower():
                        categories.append(category)
            return categories
        cache = _BlueprintCache.get(graph)
        return [c for c in cache if filter_lower in c.lower()]

    @toolset_registry.tool_call
    @staticmethod
    def list_component_events(component: unreal.ActorComponent) -> list[str]:
        """Lists the bindable delegate events available on a component.

        Args:
            component: The component to query. Must be a component on a Blueprint actor.

        Returns:
            The names of all bindable events on the component, e.g. OnComponentBeginOverlap.
        """
        blueprint = unreal.BlueprintEditorLibrary.get_blueprint_asset(component.get_outer())
        if not blueprint:
            raise RuntimeError(f'{component} is not owned by a Blueprint.')
        event_graph = unreal.BlueprintEditorLibrary.find_event_graph(blueprint)
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(event_graph)
        return list(bp_editor.list_component_events(component))

    @toolset_registry.tool_call
    @staticmethod
    def add_component_bound_event(
            component: unreal.ActorComponent,
            event_name: str,
            graph: unreal.EdGraph) -> unreal.EdGraphNode:
        """Creates a component bound event node in the event graph.

        Args:
            component: The component to bind the event to. Must be a component on a Blueprint actor.
            event_name: The name of the delegate event to bind, e.g. 'OnComponentBeginOverlap'.
            graph: The event graph to add the node to.

        Returns:
            The created or pre-existing component bound event node.
        """
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        node = bp_editor.add_component_bound_event_node(component, unreal.Name(event_name))
        if not node:
            raise RuntimeError(f'Failed to create bound event {event_name} for {component}.')
        return node

    @toolset_registry.tool_call
    @staticmethod
    def create_node(
            graph: unreal.EdGraph,
            type_id: str,
            pos: unreal.IntPoint,
            declaring_class: unreal.Class | None = None) -> unreal.EdGraphNode:
        """Adds a new node to the graph.

        Args:
            graph: The graph to add a node to
            type_id: The type of the node to add. Eg 'Development|PrintString',
                'Utilities|Operators|Add', a macro like 'Utilities|FlowControl|ForLoop', a
                dispatcher event handler like 'Default|EventDispatcherOnDamaged', an event
                like 'AddEvent|EventBeginPlay', or a named custom event with
                'AddEvent|Custom|MyEventName'.
            pos: The x, y position of the created node
            declaring_class: The class that should own the created node. Only set this when you need
                to disambiguate nodes that share the same type_id to ensure the correct one is used.

        Returns:
            Returns the new node
        """
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        assert isinstance(bp_editor, unreal.BlueprintGraphEditor), 'Could not create graph editor'
        if type_id.startswith(_DISPATCHER_PREFIX):
            dispatcher_name = type_id[len(_DISPATCHER_PREFIX):]
            node = bp_editor.add_dispatcher_event_node(unreal.Name(dispatcher_name), declaring_class) # type: ignore
        elif type_id.startswith(_CUSTOM_EVENT_PREFIX):
            event_name = type_id[len(_CUSTOM_EVENT_PREFIX):]
            node = bp_editor.add_custom_event_node(event_name) # type: ignore
        else:
            type_id = _BlueprintCache.canonicalize(graph, type_id)
            macro_path = _BlueprintCache.get_macros(graph).get(type_id)
            if macro_path:
                node = bp_editor.add_macro_node(macro_path) # type: ignore
            else:
                node = bp_editor.create_node_from_name(type_id, unreal.Vector2D(pos.x, pos.y), [], declaring_class) # type: ignore
        assert isinstance(node, unreal.EdGraphNode), f'The node could not be created / {type_id} does not exist'
        _set_node_pos(node, pos.x, pos.y)
        return node

    @toolset_registry.tool_call
    @staticmethod
    def delete_node(node: unreal.EdGraphNode) -> None:
        """
        Deletes the node from its graph.

        Args:
            node: The node to be deleted
        """
        if not  isinstance(node, unreal.EdGraphNode):
            raise RuntimeError(f'Node {node}: is not a valid node')
        graph = node.get_outer() #gets the EdGraph
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        if not isinstance(bp_editor, unreal.BlueprintGraphEditor):
            raise RuntimeError(f'Could not create graph editor for graph: {graph}')
        bp_editor.remove_nodes([node])

    @toolset_registry.tool_call
    @staticmethod
    def add_node_pin(node: unreal.EdGraphNode) -> PinID:
        """Adds a pin to a node that supports dynamic pin addition.

        Works for Switch nodes (adds one case pin), Sequence nodes (adds one Then output),
        commutative binary operators like Add/Multiply (adds one input), Make Array nodes, etc.

        Args:
            node: The node to add a pin to. Must support dynamic pin addition.

        Returns:
            The PinID of the newly added pin.
        """
        graph = node.get_outer()
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        if not isinstance(bp_editor, unreal.BlueprintGraphEditor):
            raise RuntimeError(f'Could not get graph editor for node: {node}')
        pins_before = set(p.get_pin_name() for p in BlueprintTools._list_all_pins_compat(node))  # [5.7 port] list_all_pins() is 5.8-only
        if not bp_editor.add_node_pin(node):  # type: ignore
            raise RuntimeError(
                f'Node "{node.get_node_title()}" does not support adding pins.')
        new_pins = [p for p in BlueprintTools._list_all_pins_compat(node) if p.get_pin_name() not in pins_before]  # [5.7 port]
        if not new_pins:
            raise RuntimeError(f'add_node_pin succeeded but no new pin found on node "{node.get_node_title()}"')
        return BlueprintTools._pin_to_id(new_pins[0])

    @toolset_registry.tool_call
    @staticmethod
    def remove_node_pin(node: unreal.EdGraphNode, pin: PinID) -> None:
        """Removes a specific pin from a node that supports dynamic pin removal.

        Works for Switch nodes (removes one case pin), Sequence nodes (removes one Then output),
        commutative binary operators like Add/Multiply (removes one input), Make Array nodes, etc.

        Args:
            node: The node to remove a pin from. Must support dynamic pin removal.
            pin: The PinID of the pin to remove.
        """
        graph = node.get_outer()
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        if not isinstance(bp_editor, unreal.BlueprintGraphEditor):
            raise RuntimeError(f'Could not get graph editor for node: {node}')
        resolved_pin = BlueprintTools._resolve_pin(pin)
        if not bp_editor.remove_node_pin(node, resolved_pin):  # type: ignore
            raise RuntimeError(
                f'Could not remove pin from node "{node.get_node_title()}" -- '
                f'node type may not support removal, or minimum pin count reached.')

    @toolset_registry.tool_call
    @staticmethod
    def retarget_node_class(
            node: unreal.EdGraphNode,
            old_class: unreal.Class,
            new_class: unreal.Class) -> None:
        """Replaces a node's baked-in class reference from old_class to new_class in place.

        If the node's current class reference matches old_class it is replaced with
        new_class and the node is reconstructed so its pins reflect the new type.
        If the node already references new_class the call is a no-op.

        When a Blueprint is duplicated, nodes in the copied graph retain class references
        pointing to the original Blueprint. Calling this on each node with the original
        and duplicate classes retargets them without manual delete-recreate-rewire cycles.

        Handles cast, function call, event, and multicast delegate nodes. The Blueprint
        must be compiled after all retargeting is complete.

        Args:
            node: The node to retarget.
            old_class: The class currently baked into the node.
            new_class: The replacement class.
        """
        graph = node.get_outer()
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        assert isinstance(bp_editor, unreal.BlueprintGraphEditor), 'Could not get graph editor'
        if not bp_editor.retarget_node_class(node, old_class, new_class):  # type: ignore
            raise RuntimeError(
                f'Could not retarget {type(node).__name__}: node type is unsupported or '
                f'does not reference old_class.')

    @toolset_registry.tool_call
    @staticmethod
    def set_node_position(node: unreal.EdGraphNode,  pos: unreal.IntPoint) -> None:
        """Sets a new position for the node.

        Args:
            node: Node to be moved
            pos: New x, y position of the node in the graph
        """
        _set_node_pos(node, pos.x, pos.y)
        if node.get_node_pos() != pos:
            raise RuntimeError(f'Failed to set position of node {node} to {pos}.')

    @toolset_registry.tool_call
    @staticmethod
    def arrange_nodes(nodes: list[unreal.EdGraphNode]) -> None:
        """Arranges a list of nodes in a readable left-to-right layout.

        Organizes nodes into columns based on data/execution flow, with producer nodes to
        the left of the nodes they feed into. Call this after building a graph
        to avoid nodes overlapping. Connections to nodes outside the list are used as anchors
        so the arranged nodes integrate cleanly with the rest of the graph.

        Args:
            nodes: The nodes to arrange.
        """
        if len(nodes) <= 1:
            return
        all_nodes = BlueprintTools.find_nodes(nodes[0].get_outer())
        input_set = set(nodes)
        to_arrange = {n for n in all_nodes if n in input_set}
        GraphFormatter(
            get_out_pins=lambda n: BlueprintTools._list_pins(
                n, unreal.EdGraphPinDirection.EGPD_OUTPUT),
            get_connected_pins=lambda pin: pin.list_connected_pins(),
            get_pin_owner=lambda pin: pin.get_owning_node(),
            get_node_pos=lambda n: (n.get_node_pos().x, n.get_node_pos().y),
            set_node_pos=lambda n, x, y: _set_node_pos(n, x, y),
            get_node_size=lambda n: (int(n.get_node_size().x), int(n.get_node_size().y)),
        ).arrange(all_nodes, to_arrange)

    @toolset_registry.tool_call
    @staticmethod
    def connect_pins(output_pin: PinID, input_pin: PinID) -> None:
        """Makes a connection between source (output) and dest (input) pins.

            Args:
                output_pin: The PinID of the output pin to connect from.
                input_pin: The PinID of the input pin to connect to.
        """
        out = BlueprintTools._resolve_pin(output_pin)
        inp = BlueprintTools._resolve_pin(input_pin)
        if not out.try_create_connection(inp):
            raise RuntimeError(
                f'Could not connect pin {out.get_pin_name()} to {inp.get_pin_name()}. '
                f'The pins may be incompatible types.')

    @toolset_registry.tool_call
    @staticmethod
    def break_pins(output_pin: PinID, input_pin: PinID) -> None:
        """Breaks the connection between two pins.

            Args:
                output_pin: The PinID of the output pin to disconnect from.
                input_pin: The PinID of the input pin to disconnect from.
        """
        out = BlueprintTools._resolve_pin(output_pin)
        inp = BlueprintTools._resolve_pin(input_pin)
        if inp not in out.list_connected_pins():
            raise RuntimeError(
                f'Pins {out.get_pin_name()} and {inp.get_pin_name()} are not connected.'
            )
        out.break_single_pin_link(inp)

    @toolset_registry.tool_call
    @staticmethod
    def set_pin_value(pin: PinID, value: str) -> None:
        """Sets the value of a Blueprint graph pin.

        Args:
            pin: The PinID of the pin to modify. Must be an input pin that supports default values.
            value: The value to assign as a string. Format depends on the pin's data type:
                - Numeric pins (int/float): "42" or "3.14"
                - Boolean pins: "true" or "false"
                - String/Name/Text pins: "Hello World"
                - Object reference pins: "/Game/Path/To/Asset.Asset"
        """
        p = BlueprintTools._resolve_pin(pin)
        if not p.set_pin_value(value):
            raise RuntimeError(f'Could not set value "{value}" on pin {p.get_pin_name()}.')

    @toolset_registry.tool_call
    @staticmethod
    def get_pin_value(pin: PinID) -> str:
        """Gets the value of a Blueprint graph pin.

        Args:
            pin: The PinID of the pin to read. Must be an input pin that supports default values.

        Returns:
            The value of the pin as a string.
        """
        return BlueprintTools._resolve_pin(pin).get_pin_value()

    @toolset_registry.tool_call
    @staticmethod
    def get_parent(blueprint: unreal.Blueprint) -> unreal.Class:
        """Returns the parent class of a Blueprint.

        Args:
            blueprint: The Blueprint whose parent class to retrieve.

        Returns:
            The parent class of the Blueprint's generated class.
        """
        return blueprint.get_blueprint_parent_class()

    @toolset_registry.tool_call
    @staticmethod
    def set_parent(blueprint: unreal.Blueprint, parent_class: unreal.Class) -> None:
        """Reparents a Blueprint to a new parent class.

        The Blueprint must be recompiled after reparenting.

        Args:
            blueprint: The Blueprint to reparent.
            parent_class: The new parent class. Must be a UObject subclass.
        """
        assert unreal.MathLibrary.class_is_child_of(parent_class, unreal.Object.static_class()), (
            f'{parent_class} is not a valid Blueprint parent class.')
        unreal.BlueprintEditorLibrary.reparent_blueprint(blueprint, parent_class)
        _BlueprintCache.invalidate(blueprint)

    # -------------------------------------------------------------------------
    # Member variables
    # -------------------------------------------------------------------------

    @toolset_registry.tool_call
    @staticmethod
    def add_variable(
            blueprint: unreal.Blueprint,
            name: str,
            type_name: str,
            graph: unreal.EdGraph | None = None,
            container_type: ContainerType | None = None) -> None:
        """Adds a member or local variable to a Blueprint.

        Supported type names:
          Primitives: 'bool', 'int', 'float', 'byte', 'string', 'name', 'text'
          Structs:    'Vector', 'Rotator', 'Transform', 'Vector2D', 'LinearColor'

        Args:
            blueprint: The Blueprint to add the variable to.
            name: The variable name.
            type_name: The variable type as a string (see above).
            graph: If provided, adds a local variable to this function graph instead of a
                member variable.
            container_type: Container type for the variable. MAP uses string as the key type.
        """
        var_type = BlueprintTools._make_variable_type(type_name)
        var_type = BlueprintTools._apply_container(var_type, container_type)
        if graph is not None:
            bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
            if not bp_editor.add_local_variable(name, var_type):
                raise RuntimeError(
                    f'Failed to add local variable "{name}" of type "{type_name}" '
                    f'to graph "{graph.get_name()}"')
        elif not unreal.BlueprintEditorLibrary.add_member_variable(blueprint, name, var_type):
            raise RuntimeError(
                f'Failed to add variable "{name}" of type "{type_name}" to {blueprint}')
        _BlueprintCache.invalidate(blueprint)

    @toolset_registry.tool_call
    @staticmethod
    def add_struct_variable(
            blueprint: unreal.Blueprint,
            name: str,
            struct_type: unreal.ScriptStruct,
            graph: unreal.EdGraph | None = None,
            container_type: ContainerType | None = None) -> None:
        """Adds a member or local variable of a struct type to a Blueprint.

        Use this to add variables of any UStruct type, including custom structs and engine
        structs not in the basic list supported by add_variable (e.g. HitResult, GameplayTag).

        Args:
            blueprint: The Blueprint to add the variable to.
            name: The variable name.
            struct_type: The struct type for this variable.
            graph: If provided, adds a local variable to this function graph instead of a
                member variable.
            container_type: Container type for the variable. MAP uses string as the key type.
        """
        if name in BlueprintTools.list_variables(blueprint, graph):
            raise RuntimeError(f'Variable "{name}" already exists.')
        var_type = unreal.BlueprintEditorLibrary.get_struct_type(struct_type)
        var_type = BlueprintTools._apply_container(var_type, container_type)
        if graph is not None:
            bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
            if not bp_editor.add_local_variable(name, var_type):
                raise RuntimeError(
                    f'Failed to add local struct variable "{name}" to graph "{graph.get_name()}".')
        elif not unreal.BlueprintEditorLibrary.add_member_variable(blueprint, name, var_type):
            raise RuntimeError(
                f'Failed to add struct variable "{name}" to {blueprint}.')
        _BlueprintCache.invalidate(blueprint)

    @toolset_registry.tool_call
    @staticmethod
    def add_object_variable(
            blueprint: unreal.Blueprint,
            name: str,
            object_class: unreal.Class,
            graph: unreal.EdGraph | None = None,
            container_type: ContainerType | None = None) -> None:
        """Adds a member or local variable that holds an object reference to a Blueprint.

        Args:
            blueprint: The Blueprint to add the variable to.
            name: The variable name.
            object_class: The class of object this variable will reference.
            graph: If provided, adds a local variable to this function graph instead of a
                member variable.
            container_type: Container type for the variable. MAP uses string as the key type.
        """
        var_type = unreal.BlueprintEditorLibrary.get_object_reference_type(object_class)
        var_type = BlueprintTools._apply_container(var_type, container_type)
        if graph is not None:
            bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
            if not bp_editor.add_local_variable(name, var_type):
                raise RuntimeError(
                    f'Failed to add local object variable "{name}" to graph "{graph}".')
        else:
            if not unreal.BlueprintEditorLibrary.add_member_variable(blueprint, name, var_type):
                raise RuntimeError(
                    f'Failed to add object variable "{name}" to {blueprint}.')
        _BlueprintCache.invalidate(blueprint)

    @toolset_registry.tool_call
    @staticmethod
    def list_variables(
        blueprint: unreal.Blueprint, graph: unreal.EdGraph | None = None) -> list[str]:
        """Lists member or local variables defined on a Blueprint.

        Args:
            blueprint: The Blueprint to list variables for.
            graph: If provided, lists local variables in this function graph instead of
                member variables.

        Returns:
            A list of variable names.
        """
        if graph is not None:
            bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
            return list(bp_editor.list_local_variable_names())
        # [5.7 port] list_member_variable_names is 5.8-only; use compat helper.
        return _list_member_variable_names_compat(blueprint)

    @toolset_registry.tool_call
    @staticmethod
    def set_variable_instance_editable(
            blueprint: unreal.Blueprint, variable_name: str, instance_editable: bool) -> None:
        """Sets whether a member variable is editable per-instance on actors placed in the level.

        Args:
            blueprint: The Blueprint containing the variable.
            variable_name: The name of the member variable to modify.
            instance_editable: True to make the variable editable on instances, False to hide it.
        """
        if variable_name not in BlueprintTools.list_variables(blueprint):
            raise RuntimeError(f'Variable "{variable_name}" not found in {blueprint}.')
        unreal.BlueprintEditorLibrary.set_blueprint_variable_instance_editable(
            blueprint, unreal.Name(variable_name), instance_editable)

    # [5.7 port] unreal.BlueprintVariableReplication is 5.8-only
    # (and BlueprintEditorLibrary.get/set_blueprint_variable_replication do not exist in 5.7).
    # @toolset_registry.tool_call
    # @staticmethod
    # def get_variable_replication(
    #         blueprint: unreal.Blueprint,
    #         variable_name: str) -> unreal.BlueprintVariableReplication:
    #     """Gets the replication mode of a Blueprint member variable.
    #
    #     Args:
    #         blueprint: The Blueprint containing the variable.
    #         variable_name: The name of the member variable to query.
    #
    #     Returns:
    #         The replication mode (NONE, REPLICATED, or REP_NOTIFY).
    #     """
    #     if variable_name not in BlueprintTools.list_variables(blueprint):
    #         raise RuntimeError(f'Variable "{variable_name}" not found in {blueprint}.')
    #     return unreal.BlueprintEditorLibrary.get_blueprint_variable_replication(
    #         blueprint, unreal.Name(variable_name))

    # [5.7 port] unreal.BlueprintVariableReplication is 5.8-only
    # @toolset_registry.tool_call
    # @staticmethod
    # def set_variable_replication(
    #         blueprint: unreal.Blueprint,
    #         variable_name: str,
    #         replication: unreal.BlueprintVariableReplication) -> None:
    #     """Sets the replication mode on a Blueprint member variable.
    #
    #     RepNotify will automatically create an OnRep_ function on the Blueprint if one does not
    #     already exist.
    #
    #     Args:
    #         blueprint: The Blueprint containing the variable.
    #         variable_name: The name of the member variable to modify.
    #         replication: Replication mode (NONE, REPLICATED, or REP_NOTIFY).
    #     """
    #     if variable_name not in BlueprintTools.list_variables(blueprint):
    #         raise RuntimeError(f'Variable "{variable_name}" not found in {blueprint}.')
    #     unreal.BlueprintEditorLibrary.set_blueprint_variable_replication(
    #         blueprint, unreal.Name(variable_name), replication)
    #     if replication == unreal.BlueprintVariableReplication.REP_NOTIFY:
    #         _BlueprintCache.invalidate(blueprint)

    @toolset_registry.tool_call
    @staticmethod
    def get_variable_category(blueprint: unreal.Blueprint, variable_name: str) -> str:
        """Gets the user-defined category of a Blueprint member variable.

        Categories group variables in the My Blueprint panel. Variables with no
        explicit category default to the Blueprint's name in the UI.

        Args:
            blueprint: The Blueprint containing the variable.
            variable_name: The name of the member variable to query.

        Returns:
            The category as a string. Empty string if the variable has no custom
            category override.
        """
        if variable_name not in BlueprintTools.list_variables(blueprint):
            raise RuntimeError(f'Variable "{variable_name}" not found in {blueprint}.')
        return str(unreal.BlueprintEditorLibrary.get_blueprint_variable_category(
            blueprint, unreal.Name(variable_name)))

    @toolset_registry.tool_call
    @staticmethod
    def set_variable_category(
            blueprint: unreal.Blueprint, variable_name: str, category: str) -> None:
        """Sets the user-defined category on a Blueprint member variable.

        Categories group variables in the My Blueprint panel. Pass an empty string
        to reset to the default (the Blueprint's name).

        Args:
            blueprint: The Blueprint containing the variable.
            variable_name: The name of the member variable to modify.
            category: The new category text.
        """
        if variable_name not in BlueprintTools.list_variables(blueprint):
            raise RuntimeError(f'Variable "{variable_name}" not found in {blueprint}.')
        unreal.BlueprintEditorLibrary.set_blueprint_variable_category(
            blueprint, unreal.Name(variable_name), unreal.Text(category))

    @toolset_registry.tool_call
    @staticmethod
    def remove_variable(
        blueprint: unreal.Blueprint, name: str, graph: unreal.EdGraph | None = None) -> None:
        """Removes a member or local variable from a Blueprint.

        Args:
            blueprint: The Blueprint to remove the variable from.
            name: The name of the variable to remove.
            graph: If provided, removes a local variable from this function graph instead of a
                member variable.
        """
        if graph is not None:
            bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
            if not bp_editor.remove_local_variable(name):
                raise RuntimeError(f'Local variable "{name}" not found in {graph}.')
            _BlueprintCache.invalidate(blueprint)
            return
        event_graph = unreal.BlueprintEditorLibrary.find_event_graph(blueprint)
        if not event_graph:
            raise ValueError(
                f'Could not find a graph in "{blueprint}" to remove the variable from.')
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(event_graph)
        if not bp_editor.remove_member_variable(name):
            raise RuntimeError(f'Member variable "{name}" not found in {blueprint}.')
        _BlueprintCache.invalidate(blueprint)

    # -------------------------------------------------------------------------
    # Event dispatchers
    # -------------------------------------------------------------------------

    @toolset_registry.tool_call
    @staticmethod
    def add_event_dispatcher(blueprint: unreal.Blueprint, name: str) -> unreal.EdGraph:
        """Adds an event dispatcher to a Blueprint.

        Args:
            blueprint: The Blueprint to add the dispatcher to.
            name: The name of the new event dispatcher.

        Returns:
            The event dispatcher graph.
        """
        if not unreal.BlueprintEditorLibrary.add_event_dispatcher(blueprint, unreal.Name(name)):
            raise RuntimeError(f'Failed to add event dispatcher "{name}" to {blueprint}. '
                               f'It may already exist.')
        _BlueprintCache.invalidate(blueprint)
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor_by_name(blueprint, unreal.Name(name))
        assert bp_editor, f'Dispatcher "{name}" was created but its signature graph could not be found.'
        return bp_editor.get_graph()

    @toolset_registry.tool_call
    @staticmethod
    def list_event_dispatchers(blueprint: unreal.Blueprint) -> list[unreal.EdGraph]:
        """Lists all event dispatchers defined on a Blueprint.

        Args:
            blueprint: The Blueprint to list event dispatchers for.

        Returns:
            A list of event dispatcher graphs, one per dispatcher.
        """
        names = _list_event_dispatcher_names(blueprint)  # [5.7 port] list_event_dispatchers is 5.8-only
        return [
            unreal.BlueprintGraphEditor.get_graph_editor_by_name(blueprint, n).get_graph()
            for n in names
        ]

    @toolset_registry.tool_call
    @staticmethod
    def get_graph_dsl_docs() -> str:
        """Returns the full syntax reference for write_graph_dsl.

        Call this before using write_graph_dsl for the first time.
        """
        return (
            blueprint_dsl.USAGE
            + '\nBefore writing a graph:'
            + '\n * Use find_node_types() to discover the relevant node type_ids.'
            + '\n * Use get_node_type_pins() to discover the exact pin names for a node type_id.'
        )

    @toolset_registry.tool_call
    @staticmethod
    def write_graph_dsl(graph: unreal.EdGraph, code: str) -> None:
        """Populates a Blueprint graph with nodes from a DSL script and compiles the Blueprint.

        Call get_graph_dsl_docs() for the full syntax reference and examples.

        Args:
            graph: The graph to populate with nodes.
            code: The S-expression DSL script to convert into Blueprint nodes.
        """
        with toolset_registry.tool_raising_exceptions():
            blueprint_dsl.Transpiler(
                graph,
                BlueprintTools.create_node,
                BlueprintTools.connect_pins,
                BlueprintTools._get_node_info,
                BlueprintTools.set_pin_value,
                lambda g: BlueprintTools.find_nodes(g),
                delete_node_fn=BlueprintTools.delete_node,
                find_node_types_fn=lambda f: BlueprintTools.find_node_types(graph, f),
            ).transpile(code)

        blueprint = unreal.Blueprint.cast(graph.get_outer())
        if blueprint:
            BlueprintTools.compile_blueprint(blueprint)

    @toolset_registry.tool_call
    @staticmethod
    def read_graph_dsl(graph: unreal.EdGraph) -> str:
        """Reads a Blueprint graph and returns a DSL script.

        The returned code uses the same syntax that write_graph_dsl accepts and can
        be edited and passed back to write_graph_dsl to modify the graph.
        Call get_graph_dsl_docs() for the full syntax reference.

        Args:
            graph: The graph to read.

        Returns:
            An S-expression DSL script representing the graph's logic.
        """
        decompiler = blueprint_dsl.Decompiler(
            graph,
            BlueprintTools._get_node_info,
            lambda g: BlueprintTools.find_nodes(g),
            get_node_type_pins_fn=BlueprintTools.get_node_type_pins,
            find_node_types_fn=BlueprintTools.find_node_types,
        )
        with toolset_registry.tool_raising_exceptions():
            return decompiler.decompile()

    @staticmethod
    def _ensure_create_delegate_node(node: unreal.EdGraphNode) -> None:
        """Raises RuntimeError if node is not a K2Node_CreateDelegate (Create Event) node.

        [5.7 port] unreal.K2Node_CreateDelegate is not exposed to Python on 5.7, so we
        cannot isinstance-check it; the compat shim performs the real Cast in C++.
        """
        if not unreal.EditorToolsetCompatLibrary.is_create_delegate_node(node):
            raise RuntimeError('Node is not a Create Event (K2Node_CreateDelegate) node.')

    @staticmethod
    def _ensure_delegate_connected(node: unreal.EdGraphNode) -> None:
        """Raises RuntimeError if the node's OutputDelegate pin is not connected."""
        output_pins = BlueprintTools._list_pins(node, unreal.EdGraphPinDirection.EGPD_OUTPUT)
        delegate_pin = next((p for p in output_pins if p.get_pin_name() == 'OutputDelegate'), None)
        if not delegate_pin or not delegate_pin.list_connected_pins():
            raise RuntimeError(
                'Connect the OutputDelegate pin to a delegate input pin first.')

    @staticmethod
    def _is_dispatcher_graph(graph: unreal.EdGraph) -> bool:
        """Returns True if graph is an event dispatcher graph."""
        blueprint = unreal.Blueprint.cast(graph.get_outer())
        if not blueprint:
            return False
        dispatcher_names = _list_event_dispatcher_names(blueprint)  # [5.7 port] list_event_dispatchers is 5.8-only
        return graph.get_name() in dispatcher_names

    @staticmethod
    def _assert_dispatcher_input_only(graph: unreal.EdGraph, input_param: bool) -> None:
        if not input_param:
            raise RuntimeError(
                f'Event dispatcher "{graph.get_name()}" only supports input parameters.')

    @staticmethod
    def _add_dispatcher_param(
            graph: unreal.EdGraph,
            param_name: str,
            pin_type: unreal.EdGraphPinType) -> PinID:
        """Adds a parameter to an event dispatcher graph and returns its PinID."""
        blueprint = unreal.Blueprint.cast(graph.get_outer())
        dispatcher_name = graph.get_name()
        if not unreal.BlueprintEditorLibrary.add_event_dispatcher_parameter(
                blueprint, unreal.Name(dispatcher_name), unreal.Name(param_name), pin_type):
            raise RuntimeError(
                f'Failed to add parameter "{param_name}" to dispatcher "{dispatcher_name}".')
        _BlueprintCache.invalidate(blueprint)
        bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(graph)
        nodes = bp_editor.list_all_nodes()
        pins = BlueprintTools._list_pins(nodes[0], unreal.EdGraphPinDirection.EGPD_OUTPUT)
        pin = next((p for p in pins if p.get_pin_name() == param_name), None)
        if pin is None:
            raise RuntimeError(f'Could not find newly added pin "{param_name}".')
        return BlueprintTools._pin_to_id(pin)

    @staticmethod
    def _apply_container(
            pin_type: unreal.EdGraphPinType,
            container_type: 'ContainerType | None') -> unreal.EdGraphPinType:
        if container_type == ContainerType.ARRAY:
            return unreal.BlueprintEditorLibrary.get_array_type(pin_type)
        if container_type == ContainerType.SET:
            return unreal.BlueprintEditorLibrary.get_set_type(pin_type)
        if container_type == ContainerType.MAP:
            key_type = unreal.BlueprintEditorLibrary.get_basic_type_by_name('string')
            return unreal.BlueprintEditorLibrary.get_map_type(key_type, pin_type)
        return pin_type

    @staticmethod
    def _make_variable_type(type_name: str) -> unreal.EdGraphPinType:
        """Converts a type name string to an EdGraphPinType for use in add_variable."""
        normalized = type_name.lower()
        if normalized == 'float':
            normalized = 'real'

        basic_types = {'bool', 'int', 'byte', 'real', 'name', 'string', 'text'}
        if normalized in basic_types:
            return unreal.BlueprintEditorLibrary.get_basic_type_by_name(normalized)

        struct_map = {
            'vector':      unreal.Vector.static_struct(),
            'rotator':     unreal.Rotator.static_struct(),
            'transform':   unreal.Transform.static_struct(),
            'vector2d':    unreal.Vector2D.static_struct(),
            'linearcolor': unreal.LinearColor.static_struct(),
        }
        if normalized in struct_map:
            return unreal.BlueprintEditorLibrary.get_struct_type(struct_map[normalized])

        raise ValueError(
            f'Unknown type "{type_name}". Supported: bool, int, float, byte, name, string, '
            f'text, Vector, Rotator, Transform, Vector2D, LinearColor.')
