/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/graphfragment.h>

namespace ASG {
namespace Graph {

class AbstractGraph;

class AbstractNode: public GraphFragment
{
public:
    using GraphFragment::GraphFragment;
};

}
}
