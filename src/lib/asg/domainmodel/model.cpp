/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "model.h"

#include <asg/graph/abstract_graph.h>

#include <asg/domainmodel/model.h>
#include <asg/domainmodel/primitive_data_type.h>
#include <asg/domainmodel/bounded_context.h>

namespace asg {
namespace domain_model {

string model::static_node_type_name { "model" };

string model::boolean_type_name { "boolean" };
string model::integer_type_name { "integer" };
string model::numeric_type_name { "numeric" };
string model::uuid_type_name { "uuid" };
string model::text_type_name { "text" };
string model::date_type_name { "date" };
string model::time_type_name { "time" };
string model::timestamp_type_name { "timestamp" };

string_vec model::default_primitve_data_type_names {
    model::boolean_type_name,
            model::integer_type_name,
            model::numeric_type_name,
            model::uuid_type_name,
            model::text_type_name,
            model::date_type_name,
            model::time_type_name,
            model::timestamp_type_name };

primitive_data_type_sptr model::create_primitive_data_type(const string &name)
{
    return create_sub_node<primitive_data_type>(name);
}

bounded_context_sptr model::create_bounded_context(const string &name)
{
    return create_sub_node<bounded_context>(name);
}

const bounded_context_sptr_vec model::bounded_contexts() const
{
    return sub_nodes<bounded_context>();
}

}
}
