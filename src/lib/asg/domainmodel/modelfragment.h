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

class ModelFragment : public Graph::UserNode
{
public:
    using Graph::UserNode::UserNode;
};

}
}
