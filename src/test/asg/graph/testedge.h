/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/edge.h>

namespace asg {
namespace graph {
namespace Test {

class TestEdge : public Edge
{
public:
    static string staticEdgeName;

    using Edge::Edge;

protected:
    string impl_edge_type_name() const override { return TestEdge::staticEdgeName; }
};

}
}
}
