# Copyright Epic Games, Inc. All Rights Reserved.

import unittest

from editor_toolset.toolsets.blueprint_layout import (
    GraphFormatter, _BBox, _NodeAdjacencyMap, _NodeDepthMap, _VirtualGraph, _ColumnLayout,
)


class FakeNode:
    def __init__(self, name: str, x: int = 0, y: int = 0):
        self.name = name
        self.x = x
        self.y = y


class FakeGraph:
    """Minimal directed graph for testing GraphFormatter without UE."""

    def __init__(self):
        self.nodes: list[FakeNode] = []
        self._out_edges: dict = {}   # id(node) -> {pin_idx: [dst_node, ...]}
        self._pin_counts: dict = {}  # id(node) -> number of output pins

    def add_node(self, name: str, x: int = 0, y: int = 0) -> FakeNode:
        node = FakeNode(name, x, y)
        self.nodes.append(node)
        self._out_edges[id(node)] = {}
        self._pin_counts[id(node)] = 0
        return node

    def add_edge(self, src: FakeNode, dst: FakeNode, pin_idx: int = 0) -> None:
        self._pin_counts[id(src)] = max(self._pin_counts[id(src)], pin_idx + 1)
        self._out_edges[id(src)].setdefault(pin_idx, []).append(dst)

    def make_formatter(self) -> GraphFormatter:
        out_edges = self._out_edges
        pin_counts = self._pin_counts

        def set_pos(n, x, y):
            n.x = x
            n.y = y

        return GraphFormatter(
            get_out_pins=lambda n: [(n, i) for i in range(pin_counts.get(id(n), 0))],
            get_connected_pins=lambda pin: [
                (dst,) for dst in out_edges.get(id(pin[0]), {}).get(pin[1], [])
            ],
            get_pin_owner=lambda pin: pin[0],
            get_node_pos=lambda n: (n.x, n.y),
            set_node_pos=set_pos,
        )


class GraphFormatterTestCase(unittest.TestCase):

    def test_single_node_no_op(self):
        """A single node is not moved."""
        g = FakeGraph()
        a = g.add_node('a', x=100, y=200)
        g.make_formatter().arrange(g.nodes, set(g.nodes))
        self.assertEqual((a.x, a.y), (100, 200))

    def test_separates_overlapping(self):
        """Nodes stacked at the same position are separated by at least ROW_HEIGHT."""
        g = FakeGraph()
        nodes = [g.add_node(name) for name in ('a', 'b', 'c')]
        g.make_formatter().arrange(g.nodes, set(g.nodes))
        for i, node_i in enumerate(nodes):
            for node_j in nodes[i + 1:]:
                self.assertTrue(
                    abs(node_i.x - node_j.x) >= GraphFormatter.COL_PADDING or
                    abs(node_i.y - node_j.y) >= GraphFormatter.ROW_PADDING
                )

    def test_producer_left_of_consumer(self):
        """A connected producer is placed at least COL_WIDTH to the left of its consumer."""
        g = FakeGraph()
        a = g.add_node('a')
        b = g.add_node('b')
        g.add_edge(a, b)
        g.make_formatter().arrange(g.nodes, set(g.nodes))
        self.assertGreaterEqual(b.x - a.x, GraphFormatter.COL_PADDING)

    def test_chain_ordering(self):
        """Nodes in a chain a->b->c are each at least COL_WIDTH apart left-to-right."""
        g = FakeGraph()
        a = g.add_node('a')
        b = g.add_node('b')
        c = g.add_node('c')
        g.add_edge(a, b)
        g.add_edge(b, c)
        g.make_formatter().arrange(g.nodes, set(g.nodes))
        self.assertGreaterEqual(b.x - a.x, GraphFormatter.COL_PADDING)
        self.assertGreaterEqual(c.x - b.x, GraphFormatter.COL_PADDING)

    def test_respects_anchors(self):
        """Nodes outside to_arrange are not moved."""
        g = FakeGraph()
        anchor = g.add_node('anchor', x=999, y=999)
        mover = g.add_node('mover')
        g.make_formatter().arrange(g.nodes, {mover})
        self.assertEqual((anchor.x, anchor.y), (999, 999))

    def test_long_edge_places_nodes_in_separate_columns(self):
        """A four-node chain results in four distinct x positions."""
        g = FakeGraph()
        a, b, c, d = [g.add_node(n) for n in ('a', 'b', 'c', 'd')]
        g.add_edge(a, b)
        g.add_edge(b, c)
        g.add_edge(c, d)
        g.make_formatter().arrange(g.nodes, set(g.nodes))
        xs = [n.x for n in (a, b, c, d)]
        self.assertEqual(xs, sorted(xs))
        self.assertEqual(len(set(xs)), 4)

    # -------------------------------------------------------
    # _build_adjacency Tests
    # -------------------------------------------------------

    def test_build_adjacency_single_edge(self):
        """downstream, incoming, and pin_frac are populated for a single connection."""
        g = FakeGraph()
        a = g.add_node('a')
        b = g.add_node('b')
        g.add_edge(a, b)
        formatter = g.make_formatter()
        adj = formatter._build_adjacency([a, b], {id(a), id(b)})
        self.assertIn(id(b), adj.downstream[id(a)])
        self.assertEqual(adj.incoming[id(a)], 0)
        self.assertEqual(adj.incoming[id(b)], 1)

    def test_build_adjacency_duplicate_connections_counted_once(self):
        """Multiple pins between the same pair increment incoming only once."""
        g = FakeGraph()
        a = g.add_node('a')
        b = g.add_node('b')
        g.add_edge(a, b, pin_idx=0)
        g.add_edge(a, b, pin_idx=1)
        formatter = g.make_formatter()
        adj = formatter._build_adjacency([a, b], {id(a), id(b)})
        self.assertEqual(adj.incoming[id(b)], 1)

    def test_build_adjacency_pin_fraction_uses_lowest_index(self):
        """When two pins connect the same pair, pin_frac stores the lower fraction."""
        g = FakeGraph()
        a = g.add_node('a')
        b = g.add_node('b')
        g.add_edge(a, b, pin_idx=0)
        g.add_edge(a, b, pin_idx=1)
        formatter = g.make_formatter()
        adj = formatter._build_adjacency([a, b], {id(a), id(b)})
        self.assertEqual(adj.pin_frac[(id(a), id(b))], 0.0)

    # -------------------------------------------------------
    # _assign_layers Tests
    # -------------------------------------------------------

    def test_assign_layers_chain_depth(self):
        """A three-node chain a->b->c receives depths 0, 1, 2."""
        a, b, c = 1, 2, 3
        adj = _NodeAdjacencyMap(
            downstream={a: {b}, b: {c}, c: set()},
            incoming={a: 0, b: 1, c: 1},
            pin_frac={},
        )
        layers = GraphFormatter._assign_layers({a, b, c}, adj)
        self.assertEqual(layers.depth[a], 0)
        self.assertEqual(layers.depth[b], 1)
        self.assertEqual(layers.depth[c], 2)

    def test_assign_layers_upstream_is_inverse_of_downstream(self):
        """upstream[n] contains exactly the nodes that list n in their downstream."""
        a, b, c = 1, 2, 3
        adj = _NodeAdjacencyMap(
            downstream={a: {b}, b: {c}, c: set()},
            incoming={a: 0, b: 1, c: 1},
            pin_frac={},
        )
        layers = GraphFormatter._assign_layers({a, b, c}, adj)
        self.assertEqual(layers.upstream[a], set())
        self.assertEqual(layers.upstream[b], {a})
        self.assertEqual(layers.upstream[c], {b})

    def test_assign_layers_source_node_pulled_adjacent_to_consumer(self):
        """A source node with no incoming edges is placed one column left of its consumer."""
        a, b, c = 1, 2, 3
        adj = _NodeAdjacencyMap(
            downstream={a: {c}, b: {c}, c: set()},
            incoming={a: 0, b: 0, c: 2},
            pin_frac={},
        )
        layers = GraphFormatter._assign_layers({a, b, c}, adj)
        self.assertEqual(layers.depth[c], 1)
        self.assertEqual(layers.depth[a], 0)

    # -------------------------------------------------------
    # _insert_dummy_nodes Tests
    # -------------------------------------------------------

    def test_insert_dummy_nodes_short_edge_unchanged(self):
        """An edge spanning one layer produces no dummy nodes."""
        a, b = 1, 2
        adj = _NodeAdjacencyMap(downstream={a: {b}, b: set()}, incoming={}, pin_frac={})
        layers = _NodeDepthMap(depth={a: 0, b: 1}, upstream={a: set(), b: {a}})
        vgraph = GraphFormatter._insert_dummy_nodes({a, b}, adj, layers)
        self.assertFalse(any(nid < 0 for nid in vgraph.depth))
        self.assertIn(b, vgraph.downstream[a])

    def test_insert_dummy_nodes_long_edge_inserts_dummy(self):
        """An edge spanning two layers inserts one dummy at the intermediate layer."""
        a, c = 1, 3
        adj = _NodeAdjacencyMap(downstream={a: {c}, c: set()}, incoming={}, pin_frac={})
        layers = _NodeDepthMap(depth={a: 0, c: 2}, upstream={a: set(), c: {a}})
        vgraph = GraphFormatter._insert_dummy_nodes({a, c}, adj, layers)
        dummies = [nid for nid in vgraph.depth if nid < 0]
        self.assertEqual(len(dummies), 1)
        dummy = dummies[0]
        self.assertEqual(vgraph.depth[dummy], 1)
        self.assertNotIn(c, vgraph.downstream[a])
        self.assertIn(dummy, vgraph.downstream[a])
        self.assertIn(c, vgraph.downstream[dummy])

    def test_insert_dummy_nodes_very_long_edge_inserts_multiple_dummies(self):
        """An edge spanning three layers inserts two dummy nodes."""
        a, d = 1, 4
        adj = _NodeAdjacencyMap(downstream={a: {d}, d: set()}, incoming={}, pin_frac={})
        layers = _NodeDepthMap(depth={a: 0, d: 3}, upstream={a: set(), d: {a}})
        vgraph = GraphFormatter._insert_dummy_nodes({a, d}, adj, layers)
        dummies = [nid for nid in vgraph.depth if nid < 0]
        self.assertEqual(len(dummies), 2)
        self.assertEqual(sorted(vgraph.depth[dummy] for dummy in dummies), [1, 2])

    # -------------------------------------------------------
    # _assign_coordinates Tests
    # -------------------------------------------------------

    def test_assign_coordinates_same_column_separated(self):
        """Two nodes in the same column are placed at least ROW_HEIGHT apart."""
        na, nb = object(), object()
        nid_a, nid_b = id(na), id(nb)
        node_ids = {nid_a: na, nid_b: nb}
        layers = _NodeDepthMap(depth={nid_a: 0, nid_b: 0}, upstream={nid_a: set(), nid_b: set()})
        layout = _ColumnLayout(col_list=[0], col_order={0: [nid_a, nid_b]})
        formatter = GraphFormatter(
            get_out_pins=lambda n: [], get_connected_pins=lambda p: [],
            get_pin_owner=lambda p: p, get_node_pos=lambda n: (0, 0),
            set_node_pos=lambda n, x, y: None,
        )
        positions = formatter._assign_coordinates(node_ids, {nid_a, nid_b}, layers, layout, {})
        self.assertGreaterEqual(abs(positions[nid_a] - positions[nid_b]), GraphFormatter.ROW_PADDING)

    def test_assign_coordinates_aligns_with_upstream_y(self):
        """A node with a single upstream neighbour is placed at that neighbour's Y."""
        na, nb = object(), object()
        nid_a, nid_b = id(na), id(nb)
        node_ids = {nid_a: na, nid_b: nb}
        layers = _NodeDepthMap(depth={nid_a: 0, nid_b: 1}, upstream={nid_a: set(), nid_b: {nid_a}})
        layout = _ColumnLayout(col_list=[0, 1], col_order={0: [nid_a], 1: [nid_b]})
        formatter = GraphFormatter(
            get_out_pins=lambda n: [], get_connected_pins=lambda p: [],
            get_pin_owner=lambda p: p, get_node_pos=lambda n: (0, 400),
            set_node_pos=lambda n, x, y: None,
        )
        positions = formatter._assign_coordinates(node_ids, {nid_b}, layers, layout, {})
        self.assertEqual(positions[nid_b], 400)

    # -------------------------------------------------------
    # _find_components Tests
    # -------------------------------------------------------

    def test_find_components_single_component(self):
        """A connected chain is one component."""
        a, b, c = 1, 2, 3
        adj = _NodeAdjacencyMap(
            downstream={a: {b}, b: {c}, c: set()},
            incoming={a: 0, b: 1, c: 1},
            pin_frac={},
        )
        comps = GraphFormatter._find_components({a, b, c}, adj)
        self.assertEqual(len(comps), 1)
        self.assertEqual(comps[0], {a, b, c})

    def test_find_components_two_disconnected(self):
        """Two disconnected chains produce two components."""
        a, b, c, d = 1, 2, 3, 4
        adj = _NodeAdjacencyMap(
            downstream={a: {b}, b: set(), c: {d}, d: set()},
            incoming={a: 0, b: 1, c: 0, d: 1},
            pin_frac={},
        )
        comps = GraphFormatter._find_components({a, b, c, d}, adj)
        self.assertEqual(len(comps), 2)
        comp_sets = [frozenset(comp) for comp in comps]
        self.assertIn(frozenset({a, b}), comp_sets)
        self.assertIn(frozenset({c, d}), comp_sets)

    def test_find_components_undirected(self):
        """a→b and a standalone node c produce {a,b} and {c}."""
        a, b, c = 1, 2, 3
        adj = _NodeAdjacencyMap(
            downstream={a: {b}, b: set(), c: set()},
            incoming={a: 0, b: 1, c: 0},
            pin_frac={},
        )
        comps = GraphFormatter._find_components({a, b, c}, adj)
        comp_sets = [frozenset(x) for x in comps]
        self.assertIn(frozenset({a, b}), comp_sets)
        self.assertIn(frozenset({c}), comp_sets)

    # arrange — two-mode behavior

    def test_arrange_full_component_translates_to_origin(self):
        """A fully-selected component is positioned back at its original bounding box."""
        g = FakeGraph()
        a = g.add_node('a', x=500, y=300)
        b = g.add_node('b', x=700, y=300)
        g.add_edge(a, b)
        g.make_formatter().arrange(g.nodes, set(g.nodes))
        self.assertGreaterEqual(min(a.x, b.x), 500 - 1)

    def test_arrange_partial_does_not_jump_to_zero(self):
        """Nodes in a partial selection stay near their anchor, not at x≈0."""
        g = FakeGraph()
        anchor = g.add_node('anchor', x=1000, y=0)
        mover = g.add_node('mover', x=1200, y=0)
        g.add_edge(anchor, mover)
        g.make_formatter().arrange(g.nodes, {mover})
        self.assertGreater(mover.x, GraphFormatter.COL_PADDING)

    def test_arrange_mixed_full_and_partial(self):
        """Full component translates; partial nodes do not drag the full component out of place."""
        g = FakeGraph()
        # Full component: a→b at x=500
        a = g.add_node('a', x=500, y=0)
        b = g.add_node('b', x=700, y=0)
        g.add_edge(a, b)
        # Partial component: anchor→mover at x=1500
        anchor = g.add_node('anchor', x=1500, y=0)
        mover = g.add_node('mover', x=1700, y=0)
        g.add_edge(anchor, mover)
        # Arrange the full component plus the partial mover (not the anchor)
        g.make_formatter().arrange(g.nodes, {a, b, mover})
        # Full component nodes should still be near x=500
        self.assertGreaterEqual(min(a.x, b.x), 500 - 1)
        # Anchor must not have moved
        self.assertEqual(anchor.x, 1500)

    def test_arrange_partial_source_node_stays_near_anchor_y(self):
        """A source node that feeds into an anchor should stay near the anchor's Y, not jump to 0."""
        g = FakeGraph()
        mover = g.add_node('mover', x=0, y=2000)
        anchor = g.add_node('anchor', x=200, y=2000)
        g.add_edge(mover, anchor)
        g.make_formatter().arrange(g.nodes, {mover})
        self.assertGreater(mover.y, 1000)

    # -------------------------------------------------------
    # _layout_subgraphs_in_graph Tests
    # -------------------------------------------------------

    def test_layout_subgraphs_in_graph_separates_overlapping(self):
        """Two components at the same position are moved apart."""
        g = FakeGraph()
        a = g.add_node('a', x=0, y=0)
        b = g.add_node('b', x=0, y=0)
        formatter = g.make_formatter()
        node_ids = {id(a): a, id(b): b}
        formatter._layout_subgraphs_in_graph([{id(a)}, {id(b)}], [], node_ids, {})
        self.assertTrue(
            abs(a.x - b.x) >= GraphFormatter.COL_PADDING or
            abs(a.y - b.y) >= GraphFormatter.ROW_PADDING
        )

    def test_layout_subgraphs_in_graph_non_overlapping_x_unchanged(self):
        """Components with non-overlapping X ranges are not moved."""
        g = FakeGraph()
        a = g.add_node('a', x=0, y=0)
        b = g.add_node('b', x=5000, y=0)
        formatter = g.make_formatter()
        node_ids = {id(a): a, id(b): b}
        formatter._layout_subgraphs_in_graph([{id(a)}, {id(b)}], [], node_ids, {})
        self.assertEqual(a.y, 0)
        self.assertEqual(b.y, 0)

    def test_layout_subgraphs_in_graph_avoids_obstacle(self):
        """A full component is moved to the nearest clear slot around a fixed obstacle."""
        g = FakeGraph()
        a = g.add_node('a', x=0, y=0)
        formatter = g.make_formatter()
        node_ids = {id(a): a}
        obstacle = _BBox(0, 0, 200, 200)
        formatter._layout_subgraphs_in_graph([{id(a)}], [obstacle], node_ids, {})
        # Component must not overlap the obstacle — it may move up or down.
        bb = formatter._nodes_bbox({id(a)}, node_ids, {})
        self.assertTrue(bb.y2 <= 0 or bb.y1 >= 200, 'component still overlaps obstacle')

    def test_arrange_full_component_avoids_partial_component(self):
        """A fully-selected component is pushed clear of a partial component's footprint."""
        g = FakeGraph()
        # Partial component: anchor fixed at (0, 0), mover arranged but anchored
        anchor = g.add_node('anchor', x=0, y=0)
        mover = g.add_node('mover', x=200, y=0)
        g.add_edge(anchor, mover)
        # Full component placed directly on top of the partial component
        c = g.add_node('c', x=0, y=0)
        d = g.add_node('d', x=200, y=0)
        g.add_edge(c, d)
        g.make_formatter().arrange(g.nodes, {mover, c, d})
        # anchor is not in the arrange set — must never move
        self.assertEqual((anchor.x, anchor.y), (0, 0), 'anchor should not move')
        # mover is in the arrange set but its component is partial — Y must stay near anchor
        self.assertEqual(anchor.y, mover.y, 'partial component should not be displaced vertically')
        # Full component (c, d) must not overlap the partial component's region
        for full_node in (c, d):
            for fixed_node in (anchor, mover):
                self.assertTrue(
                    abs(full_node.x - fixed_node.x) >= GraphFormatter.COL_PADDING or
                    abs(full_node.y - fixed_node.y) >= GraphFormatter.ROW_PADDING,
                    f'{full_node.name} overlaps {fixed_node.name}'
                )

    def test_arrange_two_full_components_do_not_overlap(self):
        """Two fully-selected disconnected components placed at the same position are separated."""
        g = FakeGraph()
        a = g.add_node('a', x=0, y=0)
        b = g.add_node('b', x=100, y=0)
        g.add_edge(a, b)
        c = g.add_node('c', x=0, y=0)
        d = g.add_node('d', x=100, y=0)
        g.add_edge(c, d)
        g.make_formatter().arrange(g.nodes, set(g.nodes))
        for node_a in (a, b):
            for node_c in (c, d):
                self.assertTrue(
                    abs(node_a.x - node_c.x) >= GraphFormatter.COL_PADDING or
                    abs(node_a.y - node_c.y) >= GraphFormatter.ROW_PADDING,
                    f'nodes {node_a.name} and {node_c.name} overlap after arrange'
                )
