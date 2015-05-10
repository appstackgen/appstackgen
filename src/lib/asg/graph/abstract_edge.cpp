/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "abstract_edge.h"

#include <asg/kernel/object_id.h>

#include <asg/graph/abstract_node.h>

namespace asg {
namespace graph {

string abstract_edge::impl_to_string() const
{
    stringstream s;
    s << edge_type_name() << " {" << id() << "}: " << start()->to_string() << " --> " << end()->to_string();
    return s.str();
}

}
}
