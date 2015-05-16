/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domainmodel/domain_object_fragment.h>

namespace asg {
namespace domain_model {

class value : public domain_object_fragment
{
public:
protected:
    using domain_object_fragment::domain_object_fragment;
};

}
}
