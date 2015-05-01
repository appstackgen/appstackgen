/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/base/subnode.h>

#include <asg/base/project.h>

namespace ASG {
namespace Base {

class ProjectFragment : public SubNode<Project>
{
public:
    using ParentNodeType = Project;

    Project* project() const { return typedParent(); }

protected:
    ProjectFragment(ParentNodeType* p, const Name& name = "", const Description& description = "")
        : SubNode<Project>(p, name, description) {}
};

}
}
