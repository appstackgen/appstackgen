/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "table_column.h"

#include <asg/relational_model/has_data_type.h>
#include <asg/relational_model/data_type.h>
#include <asg/relational_model/not_null_constraint.h>

namespace asg {
namespace relational_model {

string table_column::static_node_type_name { "table_column" };

void table_column::set_data_type(data_type_sptr t)
{
    create_edge_to<relational_model::has_data_type>(t);
}

bool table_column::has_data_type() const
{
    return has_unique_out_edge_to<relational_model::has_data_type, relational_model::data_type>();
}

bool table_column::has_not_null_constraint() const
{
    return has_unique_sub_node<relational_model::not_null_constraint>();
}

data_type_sptr table_column::data_type() const
{
    return end_node_of_unique_out_edge_to<relational_model::has_data_type, relational_model::data_type>();
}

not_null_constraint_sptr table_column::not_null_constraint() const
{
    return unique_sub_node<relational_model::not_null_constraint>();
}

not_null_constraint_sptr table_column::create_not_null_constraint()
{
    return create_sub_node<asg::relational_model::not_null_constraint>("not null");
}

}
}
