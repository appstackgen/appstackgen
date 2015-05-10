/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domainmodel/bounded_context_fragment.h>

namespace asg {
namespace domain_model {

class domain : public bounded_context_fragment
{
public:
    static string static_node_type_name;

    using bounded_context_fragment::bounded_context_fragment;
};

}
}
