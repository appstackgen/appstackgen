/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/data_type.h>

namespace asg {
namespace relational_model {

class iso_data_type : public data_type
{
public:
    static string static_node_type_name;

    using data_type::data_type;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
