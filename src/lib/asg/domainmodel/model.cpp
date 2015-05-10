/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "model.h"

#include <asg/graph/abstractgraph.h>

#include <asg/domainmodel/model.h>
#include <asg/domainmodel/primitivedatatype.h>
#include <asg/domainmodel/boundedcontext.h>

namespace asg {
namespace domain_model {

string model::static_node_type_name = "Model";

primitive_data_type_sptr model::create_primitive_data_type(const string &name)
{
    return createSubNode<primitive_data_type>(name);
}

bounded_context_sptr model::create_bounded_context(const string &name)
{
    return createSubNode<bounded_context>(name);
}

}
}
