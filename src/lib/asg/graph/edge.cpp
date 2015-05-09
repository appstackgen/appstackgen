/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "edge.h"

namespace ASG {
namespace Graph {

Edge::Edge(AbstractGraph *g, const ObjectId &uuid, AbstractNodeSPtr start, AbstractNodeSPtr end)
    : AbstractEdge(g, uuid), m_start(start), m_end(end)
{
}

}
}
