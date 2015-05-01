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

class IndexNode : public Node
{
public:
    static String defaultName;

    using Node::Node;
};

}
}
