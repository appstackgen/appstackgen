/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "testgraph.h"

#include <asg/graph/defaultgraph.h>

#include "testnode.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ASG::Graph::Test::TestGraph);

namespace ASG {
namespace Graph {
namespace Test {

void TestGraph::createGraph()
{
    auto g = std::unique_ptr<DefaultGraph>(new DefaultGraph());

    CPPUNIT_ASSERT_EQUAL(String(""), g->title());
    CPPUNIT_ASSERT(!g->hasTitle());

    CPPUNIT_ASSERT_EQUAL((Size)0, g->nodeCount());

    g->createNode<TestNode>("N");


    CPPUNIT_ASSERT_EQUAL((Size)1, g->nodeCount());
}

}
}
}
