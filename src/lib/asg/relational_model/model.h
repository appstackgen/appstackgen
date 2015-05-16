/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/user_node.h>

namespace asg {
namespace relational_model {

class model : public graph::user_node
{
public:
    static string static_node_type_name;

    using graph::user_node::user_node;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
