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

String IndexEdge::staticEdgeName { "IndexEdge" };

String IndexEdge::implEdgeName() const
{
    return staticEdgeName;
}

}
}
