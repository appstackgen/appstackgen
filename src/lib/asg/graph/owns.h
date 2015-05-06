/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/systemedge.h>

namespace ASG {
namespace Graph {

class Owns : public SystemEdge
{
public:
    static String staticEdgeName;

    using SystemEdge::SystemEdge;

protected:
    String implEdgeName() const override { return Owns::staticEdgeName; }
};

}
}
