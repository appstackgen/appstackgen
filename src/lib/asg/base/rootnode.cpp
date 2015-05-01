/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "rootnode.h"

namespace ASG {
namespace Base {

RootNode::RootNode(const Name &name, const Description &description)
    : Node()
{
    setName(name);
    setDescription(description);
}


}
}
