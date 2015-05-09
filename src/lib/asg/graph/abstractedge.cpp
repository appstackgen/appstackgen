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

string abstract_edge::implToString() const
{
    stringstream s;
    s << edgeTypeName() << " {" << id() << "}: " << start()->toString() << " --> " << end()->toString();
    return s.str();
}

}
}
