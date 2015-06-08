/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/tabloid.h>

namespace asg {
namespace relational_model {

class table_column;
class primary_key_constraint;
class unique_constraint;
class data_type;

using table_column_sptr = std::shared_ptr<table_column>;
using primary_key_constraint_sptr = std::shared_ptr<primary_key_constraint>;
using unique_constraint_sptr = std::shared_ptr<unique_constraint>;
using data_type_sptr = std::shared_ptr<data_type>;

using table_column_sptr_vec = std::vector<table_column_sptr>;
using unique_constraint_sptr_vec = std::vector<unique_constraint_sptr>;

class table : public tabloid
{
public:
    static string static_node_type_name;

    using tabloid::tabloid;

    template<typename T=table_column>
    std::shared_ptr<T> create_column(const string& name, data_type_sptr t) {
        assert(t);
        auto col = create_sub_node<T>(name);
        col->set_data_type(t);
        return col;
    }

    primary_key_constraint_sptr create_primary_key_constraint(const string& name);

    template<typename T=table_column>
    std::vector<std::shared_ptr<T>> columns() const {
        return sub_nodes<T>();
    }

    primary_key_constraint_sptr primary_key_constraint() const;
    unique_constraint_sptr create_unique_constraint(const string& name);

    unique_constraint_sptr_vec unique_constraints() const;

    bool has_primary_key_constraint() const;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
