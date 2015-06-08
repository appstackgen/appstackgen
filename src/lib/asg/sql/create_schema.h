/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/sql/create.h>

namespace asg {

namespace relational_model {
class schema;
using schema_sptr = std::shared_ptr<schema>;
}

namespace sql {

class create_schema : public create<relational_model::schema>
{
public:
    explicit create_schema(relational_model::schema_sptr obj);
};

}
}
