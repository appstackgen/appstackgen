/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domain_model/bounded_context_fragment.h>

namespace asg {
namespace domain_model {

class domain_object;

using domain_object_sptr = std::shared_ptr<domain_object>;

using domain_object_sptr_vec = std::vector<domain_object_sptr>;

class domain : public bounded_context_fragment
{
public:
    static string static_node_type_name;

    using bounded_context_fragment::bounded_context_fragment;

    domain_object_sptr create_domain_object(const string& name);

    domain_object_sptr_vec domain_objects() const;

protected:
    string impl_node_type_name() const override;
};

}
}
