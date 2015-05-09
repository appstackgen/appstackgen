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

#include <asg/graphtools/graphtoplaintext.h>

#include "testnode.h"
#include "testedge.h"

using namespace asg;
using namespace asg::graph;
using namespace asg::graph::Test;

std::shared_ptr<default_graph> createGraph() {
    auto g = std::make_shared<default_graph>();

    auto n1 = g->create_node<TestNode>(name("N1"));
    auto n2 = g->create_node<TestNode>(name("N2"));

    g->create_edge<TestEdge>(n1, n2);

    return g;
}

TEST(TestGraphTools, testGraphToPlainText) {
    auto g = createGraph();

    auto buf = GraphToPlainText::toStringVector(g);

    ASSERT_TRUE(!buf.empty());

    std::cout << std::endl;

    for(auto r : buf) {
        std::cout << r << std::endl;
    }

    std::cout << std::endl;
}
