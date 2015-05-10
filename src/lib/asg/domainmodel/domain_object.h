/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domainmodel/domain_fragment.h>

namespace asg {
namespace domain_model {

class domain_object : public domain_fragment
{
public:
    static string static_node_type_name;

    using domain_fragment::domain_fragment;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
