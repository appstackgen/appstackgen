/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "testgraph.h"

#include <asg/graph/defaultgraph.h>
#include <asg/graph/indexnode.h>
#include <asg/graph/indexedge.h>

#include "testnode.h"
#include "testedge.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ASG::Graph::Test::TestGraph);

namespace ASG {
namespace Graph {
namespace Test {

void TestGraph::testCreateNodesAndEdges()
{
    auto g = std::unique_ptr<DefaultGraph>(new DefaultGraph());

    CPPUNIT_ASSERT(g->indexNode());

    CPPUNIT_ASSERT_EQUAL((Size)0 + 1, g->nodeCount());

    auto n1 = g->createNode<TestNode>("N1");

    CPPUNIT_ASSERT_EQUAL((Size)1 + 1, g->nodeCount());

    auto n2 = g->createNode<TestNode>("N2");

    g->createEdge<TestEdge>(n1, n2);

    CPPUNIT_ASSERT_EQUAL((Size)1 + 2, g->edgeCount());
    CPPUNIT_ASSERT_EQUAL((Size)2 + 1, g->nodeCount());

    CPPUNIT_ASSERT_EQUAL((Size)0, n2->outEdgeCount());
    CPPUNIT_ASSERT_EQUAL((Size)1, n1->outEdgeCount());
    CPPUNIT_ASSERT_EQUAL((Size)0 + 1, n1->inEdgeCount());
    CPPUNIT_ASSERT_EQUAL((Size)1 + 1, n2->inEdgeCount());

    CPPUNIT_ASSERT(!g->indexNode()->typedOutEdges<IndexEdge>().empty());
    CPPUNIT_ASSERT_EQUAL((Size)0, g->indexNode()->typedInEdges<IndexEdge>().size());

    CPPUNIT_ASSERT_EQUAL((Size)2, (g->indexNode()->typedOutEdgesTo<IndexEdge, TestNode>().size()));
    CPPUNIT_ASSERT_EQUAL((Size)1, (n1->typedInEdgesFrom<IndexEdge, IndexNode>().size()));

    CPPUNIT_ASSERT_EQUAL((Size)2, (g->indexNode()->endNodesOfTypedOutEdgesTo<IndexEdge, TestNode>().size()));
    CPPUNIT_ASSERT_EQUAL((Size)1, (n1->startNodesOfTypedInEdgesFrom<IndexEdge, IndexNode>().size()));
}

void TestGraph::testGraphTitle()
{
    auto g = std::unique_ptr<DefaultGraph>(new DefaultGraph());

    CPPUNIT_ASSERT_EQUAL(String(""), g->title());
    CPPUNIT_ASSERT(!g->hasTitle());
}

}
}
}
