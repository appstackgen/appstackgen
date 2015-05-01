/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "node.h"

namespace ASG {
namespace Graph {

Node::Node(AbstractGraph *g, const Name &name, const Uuid &uuid)
    : AbstractNode(g, uuid), m_name(name)
{
}

}
}
