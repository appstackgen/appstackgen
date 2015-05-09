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
    static string staticNodeName;

    using Node::Node;

protected:
    string implNodeTypeName() const override { return TestNode::staticNodeName; }
};

}
}
}
