/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "schema_fragment.h"

#include <asg/kernel/string_tools.h>

#include <asg/graph/owns.h>

#include <asg/relational_model/schema.h>

namespace asg {
namespace relational_model {

string schema_fragment::qualified_name() const
{
    string_vec buf;

    buf.push_back(schema()->name().to_string());
    buf.push_back(name().to_string());

    return join(buf, ".");
}

schema_sptr schema_fragment::schema() const
{
    return super_node<relational_model::schema>();
}

}
}
