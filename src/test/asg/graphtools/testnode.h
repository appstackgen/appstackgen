/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/node.h>

namespace ASG {
namespace Graph {
namespace Test {

class TestNode : public Node
{
public:
    static String staticNodeName;

    using Node::Node;

protected:
    String implNodeTypeName() const override { return TestNode::staticNodeName; }
};

}
}
}
