/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "node.h"

namespace asg {
namespace graph {

Node::Node(abstract_graph *g, const object_name &name, const object_id &uuid)
    : abstract_node(g, uuid), m_name(name)
{
}

abstract_edge_sptr_vec Node::impl_out_edges() const {
    abstract_edge_sptr_vec buf;

    for (auto e : m_edges) {
        if (e->start().get() == this) {
            buf.push_back(e);
        }
    }

    return buf;
}

abstract_edge_sptr_vec Node::impl_in_edges() const {
    abstract_edge_sptr_vec buf;

    for (auto e : m_edges) {
        if (e->end().get() == this) {
            buf.push_back(e);
        }
    }

    return buf;
}

abstract_edge_sptr_vec Node::impl_edges() const {
    return m_edges;
}

}
}
