/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "domain.h"

#include <asg/domain_model/domain_object.h>

#include <asg/domain_model/id_value.h>
#include <asg/domain_model/last_changed_timestamp_value.h>
#include <asg/domain_model/object_version.h>
#include <asg/domain_model/last_changed_by_user_value.h>

namespace asg {
namespace domain_model {

string domain::static_node_type_name { "domain" };

domain_object_sptr domain::create_domain_object(const string &name)
{
    auto o = create_sub_node<domain_object>(name);

    o->create_value<id_value>(id_value::default_name);
    o->create_value<object_version>(object_version::default_name);
    o->create_value<last_changed_timestamp_value>(last_changed_timestamp_value::default_name);
    o->create_value<last_changed_by_user_value>(last_changed_by_user_value::default_name);

    return o;
}

domain_object_sptr_vec domain::domain_objects() const
{
    return sub_nodes<domain_object>();
}

string domain::impl_node_type_name() const
{
    return static_node_type_name;
}

}
}
