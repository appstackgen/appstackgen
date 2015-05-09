/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/systemnode.h>

namespace asg {
namespace Graph {

class IndexNode : public SystemNode
{
public:
    static ::asg::name defaultName;
    static string staticNodeName;

    using SystemNode::SystemNode;

protected:
    string implNodeTypeName() const override { return IndexNode::staticNodeName; }
};

}
}
