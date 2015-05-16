/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domain_model/audit_value.h>

namespace asg {
namespace domain_model {

class last_changed_by_user_value : public audit_value
{
public:
    static string static_node_type_name;
    static string default_name;

    using audit_value::audit_value;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
