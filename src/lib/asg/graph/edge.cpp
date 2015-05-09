/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "edge.h"

namespace asg {
namespace graph {

Edge::Edge(AbstractGraph *g, const object_id &uuid, AbstractNodeSPtr start, AbstractNodeSPtr end)
    : AbstractEdge(g, uuid), m_start(start), m_end(end)
{
}

}
}
