/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "graph_fragment.h"

namespace asg {
namespace graph {

graph_fragment::graph_fragment(abstract_graph *g, const object_id &uuid)
    : AbstractGraphFragment(), m_g(g), m_id(uuid)
{

}

}
}
