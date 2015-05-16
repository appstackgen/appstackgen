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
namespace domain_model {

class primitive_data_type;
class bounded_context;

using primitive_data_type_sptr = std::shared_ptr<primitive_data_type>;
using bounded_context_sptr = std::shared_ptr<bounded_context>;

using primitive_data_type_sptr_vec = std::vector<primitive_data_type_sptr>;
using bounded_context_sptr_vec = std::vector<bounded_context_sptr>;

class model : public graph::user_node
{
public:
    static string static_node_type_name;

    static string boolean_type_name;
    static string integer_type_name;
    static string numeric_type_name;
    static string uuid_type_name;
    static string text_type_name;
    static string date_type_name;
    static string time_type_name;
    static string timestamp_type_name;

    static string_vec default_primitve_data_type_names;

    primitive_data_type_sptr create_primitive_data_type(const string& name);
    bounded_context_sptr create_bounded_context(const string& name);

    const primitive_data_type_sptr_vec primitive_data_types() const;
    const bounded_context_sptr_vec bounded_contexts() const;

protected:
    virtual string impl_node_type_name() const override { return static_node_type_name; }

    using graph::user_node::user_node;
};

}
}
