/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "unknown_sub_node.h"

#include <asg/graph/abstract_node.h>

namespace asg {
namespace graph {

unknown_sub_node::unknown_sub_node(const string &name, const abstract_node *parent_node)
{
    stringstream s;
    s << "subnode with name '" << name << "' not known in parent node " << ((nullptr != parent_node) ? parent_node->to_string() : "parent node not given");
    m_msg = s.str();
}

const string unknown_sub_node::what() const
{
    return m_msg;
}

}
}
