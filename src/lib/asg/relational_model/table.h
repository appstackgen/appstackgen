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

using table_column_sptr = std::shared_ptr<table_column>;
using primary_key_constraint_sptr = std::shared_ptr<primary_key_constraint>;

using table_column_sptr_vec = std::vector<table_column_sptr>;

class table : public tabloid
{
public:
    static string static_node_type_name;

    using tabloid::tabloid;

    table_column_sptr create_column(const string& name);
    primary_key_constraint_sptr create_primary_key_constraint(const string& name);

    table_column_sptr_vec columns() const;
    primary_key_constraint_sptr primary_key_constraint() const;

    bool has_primary_key_constraint() const;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
