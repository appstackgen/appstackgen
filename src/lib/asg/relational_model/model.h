/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/user_node.h>
#include <asg/graph/unknown_sub_node.h>

namespace asg {
namespace relational_model {

class data_type;
class iso_data_type;
class schema;
class iso_constant;

using iso_data_type_sptr = std::shared_ptr<iso_data_type>;
using schema_sptr = std::shared_ptr<schema>;

using iso_data_type_sptr_vec = std::vector<iso_data_type_sptr>;
using schema_sptr_vec = std::vector<schema_sptr>;

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

    static string current_date_constant_name;

    static string_vec iso_data_type_names;
    static string_vec iso_constant_names;

    using graph::user_node::user_node;

    template<typename T=data_type>
    std::shared_ptr<T> create_data_type(const string& n) {
        return create_sub_node<T>(n);
    }

    template<typename T=schema>
    std::shared_ptr<T> create_schema(const string& n) {
        return create_sub_node<T>(n);
    }

    template<typename T=data_type>
    std::vector<std::shared_ptr<T>> data_types() const {
        return sub_nodes<T>();
    }

    template<typename t=data_type>
    std::shared_ptr<t> data_type(const string& n) const {
        for (auto node : sub_nodes<t>()) {
            if (node->name() == object_name(n)) {
                return node;
            }
        }

        throw graph::unknown_sub_node(n, this);
    }

    template<typename T=schema>
    std::vector<std::shared_ptr<T>> schemata() const {
        return sub_nodes<T>();
    }

    template<typename T=iso_constant>
    std::shared_ptr<T> create_constant(const string& n) {
        return create_sub_node<T>(n);
    }

    template<typename T=iso_constant>
    std::vector<std::shared_ptr<T>> constants() const {
        return sub_nodes<T>();
    }

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
