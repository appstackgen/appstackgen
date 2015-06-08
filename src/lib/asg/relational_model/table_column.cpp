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

data_type_sptr table_column::data_type() const
{
    return end_node_of_unique_out_edge_to<relational_model::has_data_type, relational_model::data_type>();
}

}
}
