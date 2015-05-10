/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "abstractedge.h"

#include <asg/kernel/object_id.h>

#include <asg/graph/abstractnode.h>

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
