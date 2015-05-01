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
#include "testedge.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ASG::Graph::Test::TestGraph);

namespace ASG {
namespace Graph {
namespace Test {

void TestGraph::createGraph()
{
    auto g = std::unique_ptr<DefaultGraph>(new DefaultGraph());

    CPPUNIT_ASSERT_EQUAL(String(""), g->title());
    CPPUNIT_ASSERT(!g->hasTitle());

    CPPUNIT_ASSERT_EQUAL((Size)0 + 1, g->nodeCount());

    auto n1 = g->createNode<TestNode>("N1");

    CPPUNIT_ASSERT_EQUAL((Size)1 + 1, g->nodeCount());

    auto n2 = g->createNode<TestNode>("N2");

    g->createEdge<TestEdge>(n1, n2);

    CPPUNIT_ASSERT_EQUAL((Size)1, g->edgeCount());
    CPPUNIT_ASSERT_EQUAL((Size)2 + 1, g->nodeCount());

    CPPUNIT_ASSERT_EQUAL((Size)0, n2->outEdgeCount());
    CPPUNIT_ASSERT_EQUAL((Size)1, n1->outEdgeCount());
    CPPUNIT_ASSERT_EQUAL((Size)0, n1->inEdgeCount());
    CPPUNIT_ASSERT_EQUAL((Size)1, n2->inEdgeCount());
}

}
}
}
