/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/graph/default_graph.h>
#include <asg/graph/index_node.h>
#include <asg/graph/index_edge.h>

#include "test_node.h"
#include "test_edge.h"

using namespace asg;
using namespace asg::graph;
using namespace asg::graph::Test;

TEST(test_graph, test_create_nodes_and_edges) {
    auto g = std::unique_ptr<default_graph>(new default_graph());

    ASSERT_TRUE(nullptr != g->get_index_node());

    ASSERT_EQ((size)0 + 1, g->node_count());

    auto n1 = g->create_node<test_node>(name("N1"));

    ASSERT_EQ((size)1 + 1, g->node_count());

    auto n2 = g->create_node<test_node>(name("N2"));

    g->create_edge<test_edge>(n1, n2);

    ASSERT_EQ((size)1 + 2, g->edge_count());
    ASSERT_EQ((size)2 + 1, g->node_count());

    ASSERT_EQ((size)0, n2->out_edge_count());
    ASSERT_EQ((size)1, n1->out_edge_count());
    ASSERT_EQ((size)0 + 1, n1->in_edge_count());
    ASSERT_EQ((size)1 + 1, n2->in_edge_count());

    ASSERT_TRUE(!g->get_index_node()->typed_out_edges<index_edge>().empty());
    ASSERT_EQ((size)0, g->get_index_node()->typed_in_edges<index_edge>().size());

    ASSERT_EQ((size)2, (g->get_index_node()->typed_out_edges_to<index_edge, test_node>().size()));
    ASSERT_EQ((size)1, (n1->typed_in_edges_from<index_edge, index_node>().size()));

    ASSERT_EQ((size)2, (g->get_index_node()->end_nodes_of_typed_out_edges_to<index_edge, test_node>().size()));
    ASSERT_EQ((size)1, (n1->start_nodes_of_typed_in_edges_from<index_edge, index_node>().size()));
}

TEST(test_graph, test_graph_title) {
    auto g = std::unique_ptr<default_graph>(new default_graph());

    ASSERT_EQ(name(""), g->title());
    ASSERT_TRUE(!g->has_title());
}

TEST(test_graph, test_node_hierarchy) {
    auto g = std::unique_ptr<default_graph>(new default_graph());

    auto root = g->create_node<test_node>(name("root"));
    auto child1 = g->create_sub_node_of<test_node>(root, name("child 1"));
    g->create_sub_node_of<test_node>(root, name("child 2"));

    ASSERT_TRUE((g->has_super_node(child1)));
}

