/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "indexedge.h"

namespace ASG {
namespace Graph {

string IndexEdge::staticEdgeName { "IndexEdge" };

string IndexEdge::implEdgeTypeName() const
{
    return staticEdgeName;
}

}
}
