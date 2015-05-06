/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domainmodel/modelfragment.h>

namespace ASG {
namespace DomainModel {

class BoundedContext : public ModelFragment
{
public:
    static String staticNodeName;

    using ModelFragment::ModelFragment;

protected:
    String implNodeName() const override { return staticNodeName; }
};

}
}
