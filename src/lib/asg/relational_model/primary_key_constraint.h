/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/table_constraint.h>

namespace asg {
namespace relational_model {

class primary_key_constraint : public table_constraint
{
public:
    static string static_node_type_name;

    using table_constraint::table_constraint;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
