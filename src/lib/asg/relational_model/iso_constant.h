/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/constant.h>

namespace asg {
namespace relational_model {

class iso_constant : public constant
{
public:
    static string static_node_type_name;

    using constant::constant;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
