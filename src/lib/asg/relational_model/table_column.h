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

using data_type_sptr = std::shared_ptr<data_type>;

class table_column : public table_fragment
{
public:
    static string static_node_type_name;

    using table_fragment::table_fragment;

    void set_data_type(data_type_sptr t);

    bool has_data_type() const;

    data_type_sptr data_type() const;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
