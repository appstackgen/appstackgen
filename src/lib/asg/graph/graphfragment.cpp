/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "graphfragment.h"

namespace ASG {
namespace Graph {

GraphFragment::GraphFragment(AbstractGraph *g, const Uuid &uuid)
    : AbstractGraphFragment(), m_g(g), m_uuid(uuid)
{

}

}
}
