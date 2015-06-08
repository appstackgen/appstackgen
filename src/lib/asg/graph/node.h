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

    template<typename T>
    std::shared_ptr<T> create_edge_to(abstract_node_sptr end) {
        return graph()->create_edge<T>(graph()->node(id()), end);
    }

protected:
    template<typename t>
    std::shared_ptr<t> super_node() const {
        assert((has_super_node<t>()));
        return start_node_of_unique_in_edge_from<owns, t>();
    }

    template<typename t>
    bool has_super_node() const {
        return has_unique_in_edge_from<owns, t>();
    }

    template<typename T>
    std::shared_ptr<T> create_sub_node(const string& name) {
        return graph()->create_sub_node_of<T>(graph()->node(id()), object_name(name));
    }

    template<typename T>
    std::vector<std::shared_ptr<T>> sub_nodes() const {
        return graph()->sub_nodes_of<T>(graph()->node(id()));
    }

    template<typename T>
    bool has_unique_sub_node() const {
        return ((size)1 == sub_nodes<T>().size());
    }

    template<typename T>
    std::shared_ptr<T> unique_sub_node() const {
        assert(has_unique_sub_node<T>());
        return *(sub_nodes<T>().begin());
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
