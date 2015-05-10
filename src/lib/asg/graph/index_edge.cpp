/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "index_edge.h"

namespace asg {
namespace graph {

string index_edge::static_edge_name { "index_edge" };

string index_edge::impl_edge_type_name() const
{
    return static_edge_name;
}

}
}
