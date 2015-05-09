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

class PrimitiveDataType : public ModelFragment
{
public:
    static string staticNodeName;

    using ModelFragment::ModelFragment;

protected:
    string implNodeTypeName() const override { return staticNodeName; }
};

}
}
