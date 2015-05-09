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
    auto g = std::unique_ptr<DefaultGraph>(new DefaultGraph());

    ASSERT_TRUE(nullptr != g->indexNode());

    ASSERT_EQ((size)0 + 1, g->nodeCount());

    auto n1 = g->createNode<TestNode>(name("N1"));

    ASSERT_EQ((size)1 + 1, g->nodeCount());

    auto n2 = g->createNode<TestNode>(name("N2"));

    g->createEdge<TestEdge>(n1, n2);

    ASSERT_EQ((size)1 + 2, g->edgeCount());
    ASSERT_EQ((size)2 + 1, g->nodeCount());

    ASSERT_EQ((size)0, n2->outEdgeCount());
    ASSERT_EQ((size)1, n1->outEdgeCount());
    ASSERT_EQ((size)0 + 1, n1->inEdgeCount());
    ASSERT_EQ((size)1 + 1, n2->inEdgeCount());

    ASSERT_TRUE(!g->indexNode()->typedOutEdges<IndexEdge>().empty());
    ASSERT_EQ((size)0, g->indexNode()->typedInEdges<IndexEdge>().size());

    ASSERT_EQ((size)2, (g->indexNode()->typedOutEdgesTo<IndexEdge, TestNode>().size()));
    ASSERT_EQ((size)1, (n1->typedInEdgesFrom<IndexEdge, IndexNode>().size()));

    ASSERT_EQ((size)2, (g->indexNode()->endNodesOfTypedOutEdgesTo<IndexEdge, TestNode>().size()));
    ASSERT_EQ((size)1, (n1->startNodesOfTypedInEdgesFrom<IndexEdge, IndexNode>().size()));
}

TEST(TestGraph, testGraphTitle) {
    auto g = std::unique_ptr<DefaultGraph>(new DefaultGraph());

    ASSERT_EQ(name(""), g->title());
    ASSERT_TRUE(!g->hasTitle());
}

TEST(TestGraph, testNodeHierarchy) {
    auto g = std::unique_ptr<DefaultGraph>(new DefaultGraph());

    auto root = g->createNode<TestNode>(name("root"));
    auto child1 = g->createSubNodeOf<TestNode>(root, name("child 1"));
    g->createSubNodeOf<TestNode>(root, name("child 2"));

    ASSERT_TRUE((g->hasSuperNode(child1)));
    ASSERT_EQ((size)2, g->subNodeCountOf(root));
    ASSERT_EQ(root, (g->superNodeOf<TestNode>(child1)));
}

