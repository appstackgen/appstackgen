/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/user_edge.h>

namespace asg {
namespace postgres_model {

class provides_data_type : public asg::graph::user_edge
{
public:
    static string static_edge_name;

    using asg::graph::user_edge::user_edge;

protected:
    string impl_edge_type_name() const override { return static_edge_name; }
};

}
}
