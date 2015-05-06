/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "abstractnode.h"

#include <asg/kernel/objectid.h>

namespace ASG {
namespace Graph {

String AbstractNode::implToString() const
{
    StringStream s;

    s << nodeName() << " {" << uuid() << "}";

    return s.str();
}

}
}
