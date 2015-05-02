/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/systemnode.h>

namespace ASG {
namespace Graph {

class IndexNode : public SystemNode
{
public:
    static String defaultName;

    using SystemNode::SystemNode;
};

}
}
