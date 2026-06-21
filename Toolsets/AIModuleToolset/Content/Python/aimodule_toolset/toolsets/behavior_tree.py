# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry


@unreal.uclass()
class BehaviorTreeTools(unreal.ToolsetDefinition):
    """Inspect BehaviorTree (BT) assets."""

    @staticmethod
    def _collect_all_nodes(composite: unreal.BTNode, depth: int, nodes: list, depths: list) -> None:
        """Recursively collects all node UObjects and their depths."""
        # [5.7 port] unreal.BTCompositeNode is not Python-exposed in UE 5.7
        # (UBTCompositeNode is UCLASS(Abstract, MinimalAPI), not reflected as
        # an attribute on the `unreal` module in 5.7). Annotation remapped to
        # unreal.BTNode (its exposed base, used elsewhere in this file).
        nodes.append(composite)
        depths.append(depth)
        for service in composite.services:
            nodes.append(service)
            depths.append(depth + 1)
        for child in composite.children:
            for decorator in child.decorators:
                nodes.append(decorator)
                depths.append(depth + 1)
            node = child.child_composite or child.child_task
            if node is None:
                continue
            # [5.7 port] unreal.BTCompositeNode is not Python-exposed in 5.7; a
            # composite node is identified by duck-typing on its `children` member
            # (only UBTCompositeNode exposes a `children` array) instead of isinstance.
            if hasattr(node, 'children'):
                BehaviorTreeTools._collect_all_nodes(node, depth + 1, nodes, depths)
            else:
                nodes.append(node)
                depths.append(depth + 1)

    @staticmethod
    def _build_node_list(behavior_tree: unreal.BehaviorTree) -> list:
        """Returns (nodes, depths) for a BT."""
        nodes = []
        depths = []
        root = behavior_tree.root_node
        if root is None:
            return nodes, depths
        for dec in behavior_tree.root_decorators:
            nodes.append(dec)
            depths.append(0)
        BehaviorTreeTools._collect_all_nodes(root, 0, nodes, depths)
        return nodes, depths

    @toolset_registry.tool_call
    @staticmethod
    def get_blackboard(behavior_tree: unreal.BehaviorTree) -> unreal.BlackboardData:
        """Returns the blackboard asset for this behavior tree.

        Args:
            behavior_tree: The BehaviorTree asset to query.
        Returns:
            The BlackboardData asset.
        """
        return behavior_tree.get_blackboard_asset()

    @toolset_registry.tool_call
    @staticmethod
    def get_root_decorators(behavior_tree: unreal.BehaviorTree) -> list[unreal.BTDecorator]:
        """Returns root-level decorators on this tree.

        Args:
            behavior_tree: The BehaviorTree asset to query.
        Returns:
            A list of BTDecorator UObjects.
        """
        return list(behavior_tree.root_decorators)

    @toolset_registry.tool_call
    @staticmethod
    def list_nodes(behavior_tree: unreal.BehaviorTree) -> list[unreal.BTNode]:
        """Returns a flat list of all node UObjects in tree order.

        Order: root decorators, then DFS (composite, services,
        per-child decorators, child node).

        Args:
            behavior_tree: The BehaviorTree asset to inspect.
        Returns:
            A list of BTNode UObjects.
        """
        nodes, _ = BehaviorTreeTools._build_node_list(behavior_tree)
        return nodes

    @toolset_registry.tool_call
    @staticmethod
    def get_node_depth(behavior_tree: unreal.BehaviorTree, node_index: int) -> int:
        """Returns the tree depth of a node by its list_nodes index.

        Args:
            behavior_tree: The BehaviorTree asset.
            node_index: Zero-based index into list_nodes output.
        Returns:
            The tree depth (0 = root level).
        """
        _, depths = BehaviorTreeTools._build_node_list(behavior_tree)
        if not (0 <= node_index < len(depths)):
            raise IndexError(
                f'node_index {node_index} out of range [0, {len(depths)}).')
        return depths[node_index]

    @toolset_registry.tool_call
    @staticmethod
    def get_node_depths(behavior_tree: unreal.BehaviorTree) -> list[int]:
        """Returns tree depths for all nodes, matching list_nodes order.

        Args:
            behavior_tree: The BehaviorTree asset.
        Returns:
            A list of depth integers.
        """
        _, depths = BehaviorTreeTools._build_node_list(behavior_tree)
        return depths

    @toolset_registry.tool_call
    @staticmethod
    def get_children(composite: unreal.BTNode) -> list[unreal.BTNode]:
        """Returns direct child nodes of a composite node.

        Note: [5.7 port] annotated as unreal.BTNode because unreal.BTCompositeNode
        is not Python-exposed in UE 5.7; callers should still pass a composite node.

        Args:
            composite: A BTCompositeNode (Selector, Sequence, etc.).
        Returns:
            A list of child BTNode UObjects.
        """
        result = []
        for child in composite.children:
            node = child.child_composite or child.child_task
            if node is not None:
                result.append(node)
        return result

    @toolset_registry.tool_call
    @staticmethod
    def get_subtree(node: unreal.BTNode) -> unreal.BehaviorTree:
        """Returns the sub-BT asset referenced by a RunBehavior task.

        Args:
            node: Any BTNode. Only RunBehavior tasks have a subtree.
        Returns:
            The referenced BehaviorTree asset.
        Raises:
            ValueError: If the node does not reference a subtree.
        """
        if hasattr(node, 'behavior_asset') and node.behavior_asset is not None:
            return node.behavior_asset
        if hasattr(node, 'default_behavior_asset') and node.default_behavior_asset is not None:
            return node.default_behavior_asset
        raise ValueError(f'{node.get_name()} does not reference a subtree.')
