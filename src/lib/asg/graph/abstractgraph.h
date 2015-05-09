/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/types.h>

#include <asg/graph/abstractnode.h>
#include <asg/graph/owns.h>

namespace asg {
namespace graph {

class abstract_node;
class abstract_edge;
class index_node;

using abstract_node_ptr = abstract_node*;

using abstract_node_sptr = std::shared_ptr<abstract_node>;
using abstract_edge_sptr = std::shared_ptr<abstract_edge>;
using index_node_sptr = std::shared_ptr<index_node>;
using abstract_edge_sptr = std::shared_ptr<abstract_edge>;

using abstract_node_sptr_vec = std::vector<abstract_node_sptr>;
using abstract_edge_sptr_vec = std::vector<abstract_edge_sptr>;

class abstract_graph
{
public:
    virtual ~abstract_graph() {}

    void set_title(const name& t) { impl_set_title(t); }

    name title() const { return impl_title(); }

    bool has_title() const { return (!title().is_empty()); }

    template<typename node_t=abstract_node>
    std::vector<std::shared_ptr<node_t>> nodes() const {
        std::vector<std::shared_ptr<node_t>> buf;

        for (auto n : impl_nodes()) {
            auto i = std::dynamic_pointer_cast<node_t>(n);

            if (i) {
                buf.push_back(i);
            }
        }

        return buf;
    }

    template<typename edge_t=abstract_edge>
    std::vector<std::shared_ptr<edge_t>> edges() const {
        std::vector<std::shared_ptr<edge_t>> buf;

        for (auto e : impl_edges()) {
            auto i = std::dynamic_pointer_cast<edge_t>(e);

            if (i) {
                buf.push_back(i);
            }
        }

        return buf;
    }

    template<typename T=abstract_node>
    bool has_super_node(abstract_node_sptr n) const {
        return n->has_unique_in_edge_from<owns, T>();
    }

    template<typename T=abstract_node>
    size sub_node_count_of(abstract_node_sptr p) const {
        return subNodesOf<T>(p).size();
    }

    template<typename T=abstract_node>
    std::vector<std::shared_ptr<T>> subNodesOf(abstract_node_sptr p) const {
        return p->end_nodes_of_typed_out_edges_to<owns, T>();
    }

    template<typename T=abstract_node>
    std::shared_ptr<T> sub_node_of(abstract_node_sptr n) const {
        assert(has_super_node<T>(n));

        return n->start_node_of_unique_in_edge<owns, T>();
    }

    template<typename T>
    std::shared_ptr<T> create_sub_node_of(abstract_node_sptr parent, const name& subNodeName) {
        assert(parent);

        auto n = create_node<T>(subNodeName);
        register_node_as_sub_node_of(n, parent);
        return n;
    }

    template<typename T>
    std::shared_ptr<T> create_node(const name& n = name("")) {
        auto node = std::make_shared<T>(this, n, create_object_id());
        assert(T::staticNodeName == node->node_type_name());
        register_node(node);
        return node;
    }

    template<typename T>
    std::shared_ptr<T> create_edge(abstract_node_sptr start, abstract_node_sptr end) {
        assert(abstract_node_sptr() != start);
        assert(abstract_node_sptr() != end);

        auto e = std::make_shared<T>(this, create_object_id(), start, end);

        assert(T::static_edge_name == e->edge_type_name());

        register_edge(e);

        return e;
    }

    abstract_node_sptr node(const object_id& id) const { return impl_node(id); }

    size node_count() const { return impl_node_count(); }
    size edge_count() const { return impl_edge_count(); }

    index_node_sptr get_index_node() const { return impl_get_index_node(); }

protected:
    abstract_graph();

    virtual void impl_set_title(const name& t) = 0;
    virtual name impl_title() const = 0;

    virtual void register_node(abstract_node_sptr n) = 0;
    virtual void register_node_as_sub_node_of(abstract_node_sptr n, abstract_node_sptr p) = 0;
    virtual void register_edge(abstract_edge_sptr e) = 0;

    virtual size impl_node_count() const = 0;
    virtual size impl_edge_count() const = 0;

    virtual abstract_node_sptr_vec impl_nodes() const = 0;
    virtual abstract_edge_sptr_vec impl_edges() const = 0;

    virtual abstract_node_sptr impl_node(const object_id& object_id) const = 0;

    virtual index_node_sptr impl_get_index_node() const = 0;

    virtual object_id create_object_id() = 0;
};

}
}
