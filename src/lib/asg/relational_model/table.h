/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/tabloid.h>

namespace asg {
namespace relational_model {

class table : public tabloid
{
public:
    static string static_node_type_name;

    using tabloid::tabloid;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
