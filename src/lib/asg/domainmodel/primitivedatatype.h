/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domainmodel/modelfragment.h>

namespace asg {
namespace domain_model {

class primitive_data_type : public model_fragment
{
public:
    static string static_node_type_name;

    using model_fragment::model_fragment;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
