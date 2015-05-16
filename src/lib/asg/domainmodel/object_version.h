/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domainmodel/persistence_value.h>

namespace asg {
namespace domain_model {

class object_version : public persistence_value
{
public:
    static string static_node_type_name;
    static string default_name;

    using persistence_value::persistence_value;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
