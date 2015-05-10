/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "default_graph.h"

#include <asg/graph/index_node.h>
#include <asg/graph/indexedge.h>
#include <asg/graph/owns.h>

namespace asg {
namespace graph {

default_graph::default_graph(const name &title)
    : m_title(title)
{
    m_index_node = create_node<index_node>(index_node::default_name);
}

void default_graph::register_node(abstract_node_sptr n) {
    assert(n);

    m_nodes.push_back(n);

    if (get_index_node()) {
        create_edge<index_edge>(get_index_node(), n);
    }
}

void default_graph::register_node_as_sub_node_of(abstract_node_sptr n, abstract_node_sptr p)
{
    assert(n);
    assert(p);

    create_edge<owns>(p, n);
}

void default_graph::register_edge(abstract_edge_sptr e) {
    e->start()->register_out_edge(e);
    e->end()->register_in_edge(e);

    m_edges.push_back(e);
}

abstract_node_sptr_vec default_graph::impl_nodes() const
{
    return m_nodes;
}

abstract_edge_sptr_vec default_graph::impl_edges() const
{
    return m_edges;
}

abstract_node_sptr default_graph::impl_node(const object_id &id) const
{
    auto i = std::find_if(std::begin(m_nodes), std::end(m_nodes), [=](abstract_node_sptr n) { return (n->id() == id); });

    assert(std::end(m_nodes) != i);

    return *i;
}

}
}
