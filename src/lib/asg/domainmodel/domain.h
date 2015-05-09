/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domainmodel/boundedcontextfragment.h>

namespace ASG {
namespace DomainModel {

class Domain : public BoundedContextFragment
{
public:
    static String staticNodeTypeName;

    using BoundedContextFragment::BoundedContextFragment;
};

}
}
