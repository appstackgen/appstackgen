/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "table.h"

#include <asg/relational_model/table_column.h>

namespace asg {
namespace relational_model {

string table::static_node_type_name { "table" };

table_column_sptr table::create_column(const string &name)
{
    return create_sub_node<table_column>(name);
}

table_column_sptr_vec table::columns() const
{
    return sub_nodes<table_column>();
}

}
}
