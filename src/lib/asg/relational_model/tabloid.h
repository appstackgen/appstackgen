/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/schema_fragment.h>

namespace asg {
namespace relational_model {

class tabloid : public schema_fragment
{
public:
    using schema_fragment::schema_fragment;
};

}
}
