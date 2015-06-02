/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "table.h"

#include <asg/relational_model/table_column.h>
#include <asg/relational_model/primary_key_constraint.h>

namespace asg {
namespace relational_model {

string table::static_node_type_name { "table" };

table_column_sptr table::create_column(const string &name)
{
    return create_sub_node<table_column>(name);
}

primary_key_constraint_sptr table::create_primary_key_constraint(const string &name)
{
    assert(!has_primary_key_constraint());

    return create_sub_node<relational_model::primary_key_constraint>(name);
}

table_column_sptr_vec table::columns() const
{
    return sub_nodes<table_column>();
}

primary_key_constraint_sptr table::primary_key_constraint() const
{
    return unique_sub_node<relational_model::primary_key_constraint>();
}

bool table::has_primary_key_constraint() const
{
    return has_unique_sub_node<relational_model::primary_key_constraint>();
}

}
}
