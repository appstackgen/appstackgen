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

class data_type;
class not_null_constraint;

using data_type_sptr = std::shared_ptr<data_type>;
using not_null_constraint_sptr = std::shared_ptr<not_null_constraint>;

class table_column : public table_fragment
{
public:
    static string static_node_type_name;

    using table_fragment::table_fragment;

    void set_data_type(data_type_sptr t);

    not_null_constraint_sptr create_not_null_constraint();

    bool has_data_type() const;
    bool has_not_null_constraint() const;

    data_type_sptr data_type() const;
    not_null_constraint_sptr not_null_constraint() const;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
