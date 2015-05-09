/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domainmodel/boundedcontextfragment.h>

namespace asg {
namespace DomainModel {

class Domain : public BoundedContextFragment
{
public:
    static string static_node_type_name;

    using BoundedContextFragment::BoundedContextFragment;
};

}
}
