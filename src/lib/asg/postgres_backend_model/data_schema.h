/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/postgres_backend_model/dedicated_schema.h>

namespace asg {
namespace postgres_backend_model {

class data_schema : public dedicated_schema
{
public:
    static string static_node_type_name;

    using dedicated_schema::dedicated_schema;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
