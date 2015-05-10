/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/abstract_node.h>

#include <asg/graph/abstract_edge.h>
#include <asg/graph/abstract_graph.h>

namespace asg {
namespace graph {

class node : public abstract_node
{
public:
    node(abstract_graph* g, const object_name& name, const object_id& id);

protected:
    template<typename T>
    std::shared_ptr<T> createSubNode(const string& name) {
        return graph()->create_sub_node_of<T>(graph()->node(id()), object_name(name));
    }

    void impl_register_out_edge(abstract_edge_sptr e) override { assert(e->start().get() == this); m_edges.push_back(e); }
    void impl_register_in_edge(abstract_edge_sptr e) override { assert(e->end().get() == this); m_edges.push_back(e); }

    abstract_edge_sptr_vec impl_out_edges() const override;
    abstract_edge_sptr_vec impl_in_edges() const override;
    abstract_edge_sptr_vec impl_edges() const override;

    size impl_out_edge_count() const override { return out_edges().size(); }
    size impl_in_edge_count() const override { return in_edges().size(); }
    size impl_edge_count() const override { return m_edges.size(); }

    object_name impl_name() const override { return m_name; }

private:
    object_name m_name;
    abstract_edge_sptr_vec m_edges;
};

}
}
