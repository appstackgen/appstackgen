/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/base/node.h>

namespace ASG {
namespace Base {

class RootNode : public Node
{
public:
    RootNode(const Name& name = "", const Description& description = "");

protected:
    AbstractNode *implParent() const override { return nullptr; }
};

}
}
