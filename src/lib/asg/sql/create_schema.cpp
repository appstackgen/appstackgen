/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "create_schema.h"

#include <asg/relational_model/schema.h>

namespace asg {
namespace sql {

create_schema::create_schema(relational_model::schema_sptr obj)
    : create(obj)
{
    stringstream s;
    s << "create schema " << obj->name();

    set_text(s.str());
}

}
}
