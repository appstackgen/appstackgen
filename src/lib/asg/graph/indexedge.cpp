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

string IndexEdge::staticEdgeName { "IndexEdge" };

string IndexEdge::impl_edge_type_name() const
{
    return staticEdgeName;
}

}
}
