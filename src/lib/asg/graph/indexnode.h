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
namespace graph {

class index_node : public SystemNode
{
public:
    static ::asg::name defaultName;
    static string staticNodeName;

    using SystemNode::SystemNode;

protected:
    string impl_node_type_name() const override { return index_node::staticNodeName; }
};

}
}
