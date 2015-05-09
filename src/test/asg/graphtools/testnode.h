/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/node.h>

namespace asg {
namespace graph {
namespace Test {

class TestNode : public node
{
public:
    static string staticNodeName;

    using node::node;

protected:
    string impl_node_type_name() const override { return TestNode::staticNodeName; }
};

}
}
}
