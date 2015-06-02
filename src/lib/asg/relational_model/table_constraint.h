/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/table_fragment.h>

namespace asg {
namespace relational_model {

class table_constraint : public table_fragment
{
public:
    using table_fragment::table_fragment;
};

}
}
