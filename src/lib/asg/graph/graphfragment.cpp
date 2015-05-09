/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "graphfragment.h"

namespace asg {
namespace graph {

GraphFragment::GraphFragment(abstract_graph *g, const object_id &uuid)
    : AbstractGraphFragment(), m_g(g), m_id(uuid)
{

}

}
}
