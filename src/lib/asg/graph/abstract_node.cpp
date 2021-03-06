/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "abstract_node.h"

#include <asg/kernel/object_id.h>

namespace asg {
namespace graph {

string abstract_node::impl_to_string() const
{
    stringstream s;

    s << node_type_name() << " '" << name() << "' {" << id() << "}";

    return s.str();
}

}
}
