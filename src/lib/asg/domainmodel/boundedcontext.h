/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domainmodel/modelfragment.h>

namespace asg {
namespace DomainModel {

class BoundedContext : public ModelFragment
{
public:
    static string staticNodeName;

    using ModelFragment::ModelFragment;

protected:
    string impl_node_type_name() const override { return staticNodeName; }
};

}
}
