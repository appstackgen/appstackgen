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
#include <asg/relational_model/unique_constraint.h>

namespace asg {
namespace relational_model {

string table::static_node_type_name { "table" };



primary_key_constraint_sptr table::create_primary_key_constraint(const string &name)
{
    assert(!has_primary_key_constraint());

    return create_sub_node<relational_model::primary_key_constraint>(name);
}



primary_key_constraint_sptr table::primary_key_constraint() const
{
    return unique_sub_node<relational_model::primary_key_constraint>();
}

unique_constraint_sptr table::create_unique_constraint(const string &name)
{
    return create_sub_node<unique_constraint>(name);
}

unique_constraint_sptr_vec table::unique_constraints() const
{
    return sub_nodes<unique_constraint>();
}

bool table::has_primary_key_constraint() const
{
    return has_unique_sub_node<relational_model::primary_key_constraint>();
}

}
}
