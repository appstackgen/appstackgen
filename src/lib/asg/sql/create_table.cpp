/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "create_table.h"

#include <asg/kernel/string_tools.h>

#include <asg/relational_model/table.h>
#include <asg/relational_model/table_column.h>
#include <asg/relational_model/data_type.h>

namespace asg {
namespace sql {

create_table::create_table(relational_model::table_sptr t)
    : create(t)
{
    string_vec buf;
    string_vec defs;

    buf.push_back("create table " + t->qualified_name() + " (");

    for (auto col : t->columns()) {
        defs.push_back(declare_column(col));
    }

    buf.push_back("\t " + join(defs, "\n\t, "));
    buf.push_back(")");

    set_text(join(buf, "\n"));
}

string create_table::declare_column(relational_model::table_column_sptr col) const
{
    stringstream s;

    s << col->name() << " " << col->data_type()->name();

    if (col->has_not_null_constraint()) {
        s << " not null";
    }

    return s.str();
}

}
}
