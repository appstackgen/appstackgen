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
namespace postgres_model {

class sequence : public relational_model::schema_fragment
{
public:
    static string static_node_type_name;

    using relational_model::schema_fragment::schema_fragment;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
