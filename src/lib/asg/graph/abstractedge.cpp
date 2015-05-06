/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "abstractedge.h"

#include <asg/kernel/objectid.h>

namespace ASG {
namespace Graph {

String AbstractEdge::implToString() const
{
    StringStream s;
    s << edgeName() << " {" << uuid() << "}";
    return s.str();
}

}
}
