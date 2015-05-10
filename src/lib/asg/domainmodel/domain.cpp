/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "domain.h"

#include <domain_object.h>

namespace asg {
namespace domain_model {

domain_object_sptr domain::create_domain_object(const string &name)
{
    return create_sub_node<domain_object>(name);
}

domain_object_sptr_vec domain::domain_objects() const
{
    return sub_nodes<domain_object>();
}

}
}
