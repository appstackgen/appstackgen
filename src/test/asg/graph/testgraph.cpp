/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/graph/defaultgraph.h>
#include <asg/graph/indexnode.h>
#include <asg/graph/indexedge.h>

#include "testnode.h"
#include "testedge.h"

using namespace asg;
using namespace asg::graph;
using namespace asg::graph::Test;

TEST(TestGraph, testCreateNodesAndEdges) {
    auto g = std::unique_ptr<default_graph>(new default_graph());

    ASSERT_TRUE(nullptr != g->get_index_node());

    ASSERT_EQ((size)0 + 1, g->node_count());

    auto n1 = g->create_node<TestNode>(name("N1"));

    ASSERT_EQ((size)1 + 1, g->node_count());

    auto n2 = g->create_node<TestNode>(name("N2"));

    g->create_edge<TestEdge>(n1, n2);

    ASSERT_EQ((size)1 + 2, g->edge_count());
    ASSERT_EQ((size)2 + 1, g->node_count());

    ASSERT_EQ((size)0, n2->out_edge_count());
    ASSERT_EQ((size)1, n1->out_edge_count());
    ASSERT_EQ((size)0 + 1, n1->in_edge_count());
    ASSERT_EQ((size)1 + 1, n2->in_edge_count());

    ASSERT_TRUE(!g->get_index_node()->typed_out_edges<IndexEdge>().empty());
    ASSERT_EQ((size)0, g->get_index_node()->typed_in_edges<IndexEdge>().size());

    ASSERT_EQ((size)2, (g->get_index_node()->typed_out_edges_to<IndexEdge, TestNode>().size()));
    ASSERT_EQ((size)1, (n1->typed_in_edges_from<IndexEdge, index_node>().size()));

    ASSERT_EQ((size)2, (g->get_index_node()->end_nodes_of_typed_out_edges_to<IndexEdge, TestNode>().size()));
    ASSERT_EQ((size)1, (n1->start_nodes_of_typed_in_edges_from<IndexEdge, index_node>().size()));
}

TEST(TestGraph, testGraphTitle) {
    auto g = std::unique_ptr<default_graph>(new default_graph());

    ASSERT_EQ(name(""), g->title());
    ASSERT_TRUE(!g->has_title());
}

TEST(TestGraph, testNodeHierarchy) {
    auto g = std::unique_ptr<default_graph>(new default_graph());

    auto root = g->create_node<TestNode>(name("root"));
    auto child1 = g->create_sub_node_of<TestNode>(root, name("child 1"));
    g->create_sub_node_of<TestNode>(root, name("child 2"));

    ASSERT_TRUE((g->has_super_node(child1)));
}

