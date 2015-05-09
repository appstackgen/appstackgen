/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "abstractedge.h"

#include <asg/kernel/objectid.h>

#include <asg/graph/abstractnode.h>

namespace asg {
namespace graph {

string abstract_edge::impl_to_string() const
{
    stringstream s;
    s << edge_type_name() << " {" << id() << "}: " << start()->toString() << " --> " << end()->toString();
    return s.str();
}

}
}
