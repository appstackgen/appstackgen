/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/model.h>

namespace asg {
namespace postgres_model {

class model : public relational_model::model
{
public:
    static string static_node_type_name;

    static string serial_data_type_name;
    static string bigserial_data_type_name;

    static string_vec custom_data_type_names;

    using relational_model::model::model;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
