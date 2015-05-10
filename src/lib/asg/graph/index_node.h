/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/system_node.h>

namespace asg {
namespace graph {

class index_node : public system_node
{
public:
    static ::asg::name default_name;
    static string static_node_type_name;

    using system_node::system_node;

protected:
    string impl_node_type_name() const override { return index_node::static_node_type_name; }
};

}
}
