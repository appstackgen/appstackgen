/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domain_model/model_fragment.h>

namespace asg {
namespace domain_model {

class domain;

using domain_sptr = std::shared_ptr<domain>;

using domain_sptr_vec = std::vector<domain_sptr>;

class bounded_context : public model_fragment
{
public:
    static string static_node_type_name;

    using model_fragment::model_fragment;

    domain_sptr create_domain(const string& n);

    domain_sptr_vec domains() const;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
