/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/base/node.h>

#include <asg/base/project.h>

namespace ASG {
namespace Base {

class ProjectFragment : public Node<Project>
{
public:
    Project* project() const { return typedParent(); }

protected:
    using Node<Project>::Node;
};

}
}
