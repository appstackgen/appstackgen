/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "indexedge.h"

namespace asg {
namespace graph {

string index_edge::staticEdgeName { "IndexEdge" };

string index_edge::impl_edge_type_name() const
{
    return staticEdgeName;
}

}
}
