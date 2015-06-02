/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "table_constraint.h"

#include <asg/relational_model/table_column.h>
#include <asg/relational_model/uses.h>

namespace asg {
namespace relational_model {

void table_constraint::append(table_column_sptr c)
{
    create_edge_to<uses>(c);
}

table_column_sptr_vec table_constraint::columns() const
{
    return end_nodes_of_typed_out_edges_to<uses, table_column>();
}

}
}
