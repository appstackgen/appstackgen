/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "abstractnode.h"

#include <asg/kernel/objectid.h>

namespace asg {
namespace graph {

string abstract_node::impl_to_string() const
{
    stringstream s;

    s << nodeTypeName() << " '" << name() << "' {" << id() << "}";

    return s.str();
}

}
}
