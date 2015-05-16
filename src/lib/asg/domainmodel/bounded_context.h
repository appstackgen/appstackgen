/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domainmodel/model_fragment.h>

namespace asg {
namespace domain_model {

class domain;

using domain_sptr = std::shared_ptr<domain>;

class bounded_context : public model_fragment
{
public:
    static string static_node_type_name;

    using model_fragment::model_fragment;

    domain_sptr create_domain(const string& n);

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
