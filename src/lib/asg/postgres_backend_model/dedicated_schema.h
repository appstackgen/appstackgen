/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/schema.h>

namespace asg {
namespace postgres_backend_model {

class dedicated_schema : public asg::relational_model::schema
{
public:
    using asg::relational_model::schema::schema;
};

}
}
