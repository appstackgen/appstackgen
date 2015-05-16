/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/file_tools.h>

#include <asg/graph/default_graph.h>
#include <asg/graph/index_node.h>
#include <asg/graph/index_edge.h>

#include <asg/graphtools/graph_to_plain_text.h>
#include <asg/graphtools/graph_to_dot.h>

#include "test_node.h"
#include "test_edge.h"

using namespace asg;
using namespace asg::graph;
using namespace asg::graph::Test;

std::shared_ptr<default_graph> createGraph() {
    auto g = std::make_shared<default_graph>();

    auto n1 = g->create_node<test_node>(name("N1"));
    auto n2 = g->create_node<test_node>(name("N2"));

    g->create_edge<test_edge>(n1, n2);

    return g;
}

TEST(test_graph_tools, graph_to_plain_text) {
    auto g = createGraph();

    auto formatted_data = graph_to_plain_text::to_string_vector(g);

    ASSERT_TRUE(!formatted_data.empty());

    stringstream data;

    data << std::endl;

    for(auto r : formatted_data) {
        data << r << std::endl;
    }

    data << std::endl;

    save_to_file(data.str(), "graph_to_plain_text.txt");
}

TEST(test_graph_tools, graph_to_dot) {
    auto g = createGraph();

    auto dot_data = graph_to_dot::to_string_vector(g);

    ASSERT_TRUE(!dot_data.empty());

    stringstream buf;

    buf << std::endl;

    for(auto r : dot_data) {
        buf << r << std::endl;
    }

    buf << std::endl;

    save_to_file(buf.str(), "graph_to_dot.dot");
}
