/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domainmodel/concurrency_control_value.h>

namespace asg {
namespace domain_model {

class last_changed_timestamp_value: public concurrency_control_value
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
