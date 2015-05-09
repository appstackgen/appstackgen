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

class IndexEdge : public SystemEdge
{
public:
    static string staticEdgeName;

    using SystemEdge::SystemEdge;

protected:
    string implEdgeTypeName() const override;
};

}
}
