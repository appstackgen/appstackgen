/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/postgres_model/model.h>

namespace asg {
namespace postgres_backend_model {

class model : public asg::postgres_model::model
{
public:
    static string static_node_type_name;

    using asg::postgres_model::model::model;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
