/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domain_model/concurrency_control_value.h>

namespace asg {
namespace domain_model {

class object_version : public concurrency_control_value
{
public:
    static string static_node_type_name;
    static string default_name;

    using concurrency_control_value::concurrency_control_value;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
