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

#include <asg/graphtools/graph_to_plain_text.h>

#include "testnode.h"
#include "testedge.h"

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

    auto buf = GraphToPlainText::toStringVector(g);

    ASSERT_TRUE(!buf.empty());

    std::cout << std::endl;

    for(auto r : buf) {
        std::cout << r << std::endl;
    }

    std::cout << std::endl;
}
