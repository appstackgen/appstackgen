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

class table_column : public table_fragment
{
public:
    static string static_node_type_name;

    using table_fragment::table_fragment;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
