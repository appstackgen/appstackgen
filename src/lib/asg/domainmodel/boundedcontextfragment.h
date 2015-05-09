/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/usernode.h>

namespace asg {
namespace domain_model {

class bounded_context_fragment : public graph::user_node
{
public:
    using graph::user_node::user_node;
};

}
}
