/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/graphfragment.h>

#include <asg/graph/abstractnode.h>

namespace asg {
namespace graph {

class abstract_graph;
class abstract_edge;

using abstract_edge_sptr = std::shared_ptr<abstract_edge>;
using abstract_edge_sptr_vec = std::vector<abstract_edge_sptr>;

class abstract_node: public graph_fragment
{
public:
    using graph_fragment::graph_fragment;

    string node_type_name() const { return impl_node_type_name(); }
    object_name name() const { return impl_name(); }

    void register_out_edge(abstract_edge_sptr e) { impl_register_out_edge(e); }
    void register_in_edge(abstract_edge_sptr e) { impl_register_in_edge(e); }

    template<typename T=abstract_edge>
    size count_in_edges() const {
        return typed_in_edges<T>().size();
    }

    template<typename T=abstract_edge>
    size count_out_edges() const {
        return typed_out_edges<T>().size();
    }

    template<typename edge_t=abstract_edge, typename node_t=abstract_node>
    bool has_unique_in_edge_from() const {
        return ((size)1 == typed_in_edges_from<edge_t, node_t>().size());
    }

    template<typename edge_t=abstract_edge, typename node_t=abstract_node>
    std::shared_ptr<node_t> start_node_of_unique_in_edge_from() const {
        return *(typed_in_edges_from<edge_t, node_t>().begin());
    }

    template<typename T>
    bool has_unique_in_edge() const {
        return ((size)1 == typed_in_edges<T>().size());
    }

    template<typename T>
    std::shared_ptr<T> unique_in_edge() const {
        assert(has_unique_in_edge<T>());
        return *(typed_in_edges<T>().begin());
    }

    template<typename edge_t, typename node_t=abstract_node>
    std::shared_ptr<node_t> start_node_of_unique_in_edge() const {
        assert(has_unique_in_edge<edge_t>());

        auto n = unique_in_edge<edge_t>()->template start<node_t>();

        assert(std::shared_ptr<node_t>() != n);

        return n;
    }

    template<typename T=abstract_edge>
    std::vector<std::shared_ptr<T>> typed_out_edges() const {
        std::vector<std::shared_ptr<T>> buf;

        for (auto e : out_edges()) {
            auto ee = std::dynamic_pointer_cast<T>(e);

            if (ee) {
                buf.push_back(ee);
            }
        }

        return buf;
    }

    template<typename T=abstract_edge>
    std::vector<std::shared_ptr<T>> typed_in_edges() const {
        std::vector<std::shared_ptr<T>> buf;

        for (auto e : in_edges()) {
            auto ee = std::dynamic_pointer_cast<T>(e);

            if (ee) {
                buf.push_back(ee);
            }
        }

        return buf;
    }

    template<typename edge_t=abstract_edge, typename node_t=abstract_node>
    std::vector<std::shared_ptr<edge_t>> typed_out_edges_to() const {
        std::vector<std::shared_ptr<edge_t>> buf;

        for (auto e : typed_out_edges<edge_t>()) {
            auto n = std::dynamic_pointer_cast<node_t>(e->end());

            if (n) {
                buf.push_back(e);
            }
        }

        return buf;
    }

    template<typename edge_t=abstract_edge, typename node_t=abstract_node>
    std::vector<std::shared_ptr<edge_t>> typed_in_edges_from() const {
        std::vector<std::shared_ptr<edge_t>> buf;

        for (auto e : typed_in_edges<edge_t>()) {
            auto n = std::dynamic_pointer_cast<node_t>(e->start());

            if (n) {
                buf.push_back(e);
            }
        }

        return buf;
    }

    template<typename edge_t=abstract_edge, typename node_t=abstract_node>
    std::vector<std::shared_ptr<node_t>> end_nodes_of_typed_out_edges_to() const {
        std::vector<std::shared_ptr<node_t>> buf;

        for (auto e : typed_out_edges_to<edge_t, node_t>()) {
            buf.push_back(std::dynamic_pointer_cast<node_t>(e->end()));
        }

        return buf;
    }

    template<typename edge_t=abstract_edge, typename node_t=abstract_node>
    std::vector<std::shared_ptr<node_t>> start_nodes_of_typed_in_edges_from() const {
        std::vector<std::shared_ptr<node_t>> buf;

        for (auto e : typed_in_edges_from<edge_t, node_t>()) {
            buf.push_back(std::dynamic_pointer_cast<node_t>(e->start()));
        }

        return buf;
    }

    abstract_edge_sptr_vec out_edges() const { return impl_out_edges(); }
    abstract_edge_sptr_vec in_edges() const { return impl_in_edges(); }

    abstract_edge_sptr_vec edges() const { return impl_edges(); }

    size out_edge_count() const { return impl_out_edge_count(); }
    size in_edge_count() const { return impl_in_edge_count(); }
    size edge_count() { return edge_count(); }

protected:
    virtual void impl_register_out_edge(abstract_edge_sptr e) = 0;
    virtual void impl_register_in_edge(abstract_edge_sptr e) = 0;

    virtual abstract_edge_sptr_vec impl_out_edges() const = 0;
    virtual abstract_edge_sptr_vec impl_in_edges() const = 0;
    virtual abstract_edge_sptr_vec impl_edges() const = 0;

    virtual size impl_out_edge_count() const = 0;
    virtual size impl_in_edge_count() const = 0;
    virtual size impl_edge_count() const = 0;

    virtual string impl_node_type_name() const = 0;
    virtual object_name impl_name() const = 0;

    string impl_to_string() const override;
};

}
}
