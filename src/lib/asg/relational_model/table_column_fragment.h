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

class table_column_fragment : public graph::user_node
{
public:
    using graph::user_node::user_node;
};

}
}
