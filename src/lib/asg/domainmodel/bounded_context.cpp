/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "bounded_context.h"

#include <asg/domainmodel/domain.h>

namespace asg {
namespace domain_model {

string bounded_context::static_node_type_name { "bounded_context" };

domain_sptr bounded_context::create_domain(const string &n)
{
    return create_sub_node<domain>(n);
}

domain_sptr_vec bounded_context::domains() const
{
    return sub_nodes<domain>();
}

}
}
