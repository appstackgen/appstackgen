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

edge::edge(abstract_graph *g, const object_id &uuid, abstract_node_sptr start, abstract_node_sptr end)
    : abstract_edge(g, uuid), m_start(start), m_end(end)
{
}

}
}
