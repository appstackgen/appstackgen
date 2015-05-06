/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/usernode.h>

namespace ASG {
namespace DomainModel {

class Model : public ASG::Graph::UserNode
{
public:
protected:
    using ASG::Graph::UserNode::UserNode;
};

}
}
