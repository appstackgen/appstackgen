/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/abstractgraph.h>

#include <asg/kernel/objectidgenerator.h>

#include <asg/graph/abstractnode.h>
#include <asg/graph/abstractedge.h>

namespace asg {
namespace graph {

class default_graph : public abstract_graph
{
public:
    explicit default_graph(const name& title = name(""));

protected:
    void impl_set_title(const name &t) override { m_title = t; }
    name impl_title() const override { return m_title; }

    void register_node(abstract_node_sptr n) override;
    void register_node_as_sub_node_of(abstract_node_sptr n, abstract_node_sptr p) override;
    void register_edge(abstract_edge_sptr e) override;

    object_id create_object_id() override { return m_id_enerator.create_id(); }

    size impl_node_count() const override { return m_nodes.size(); }
    size impl_edge_count() const override { return m_edges.size(); }

    index_node_sptr impl_get_index_node() const override { return m_index_node; }

    abstract_node_sptr_vec impl_nodes() const override;
    abstract_edge_sptr_vec impl_edges() const override;

    abstract_node_sptr impl_node(const object_id& object_id) const override;

private:
    name m_title;

    abstract_node_sptr_vec m_nodes;
    abstract_edge_sptr_vec m_edges;

    index_node_sptr m_index_node;

    object_id_generator m_id_enerator;
};

}
}
