/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "domain_object.h"

#include <asg/domain_model/id_value.h>

namespace asg {
namespace domain_model {

string domain_object::static_node_type_name = "domain_object";

bool domain_object::has_id_value() const
{
    return has_unique_sub_node<domain_model::id_value>();
}

id_value_sptr domain_object::id_value() const
{
    return unique_sub_node<domain_model::id_value>();
}

}
}
