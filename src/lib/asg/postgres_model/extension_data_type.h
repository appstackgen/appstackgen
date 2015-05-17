/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/custom_data_type.h>

namespace asg {
namespace postgres_model {

class extension_data_type : public relational_model::custom_data_type
{
public:
    static string static_node_type_name;

    using relational_model::custom_data_type::custom_data_type;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
