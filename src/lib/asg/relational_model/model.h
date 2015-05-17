/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/user_node.h>

namespace asg {
namespace relational_model {

class iso_data_type;

using iso_data_type_sptr = std::shared_ptr<iso_data_type>;

using iso_data_type_sptr_vec = std::vector<iso_data_type_sptr>;

class model : public graph::user_node
{
public:
    static string static_node_type_name;

    static string boolean_type_name;
    static string integer_type_name;
    static string bigint_type_name;
    static string numeric_type_name;
    static string char_type_name;
    static string varchar_type_name;
    static string date_type_name;
    static string time_type_name;
    static string timestamp_type_name;

    static string_vec iso_data_type_names;

    using graph::user_node::user_node;

    iso_data_type_sptr create_iso_data_type(const string& n);

    iso_data_type_sptr_vec iso_data_types() const;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
