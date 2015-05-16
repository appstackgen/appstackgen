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
namespace test {

class test_node : public node
{
public:
    static string static_node_type_name;

    using node::node;

protected:
    string impl_node_type_name() const override { return test_node::static_node_type_name; }
};

}
}
}
