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

using AbstractNodePtr = abstract_node*;

using abstract_node_sptr = std::shared_ptr<abstract_node>;
using abstract_edge_sptr = std::shared_ptr<abstract_edge>;
using IndexNodeSPtr = std::shared_ptr<index_node>;
using abstract_edge_sptr = std::shared_ptr<abstract_edge>;

using AbstractNodeSPtrVector = std::vector<abstract_node_sptr>;
using AbstractEdgeSPtrVector = std::vector<abstract_edge_sptr>;

class AbstractGraph
{
public:
    virtual ~AbstractGraph() {}

    void setTitle(const name& t) { implSetTitle(t); }

    name title() const { return implTitle(); }

    bool hasTitle() const { return (!title().is_empty()); }

    template<typename NodeT=abstract_node>
    std::vector<std::shared_ptr<NodeT>> nodes() const {
        std::vector<std::shared_ptr<NodeT>> buf;

        for (auto n : implNodes()) {
            auto i = std::dynamic_pointer_cast<NodeT>(n);

            if (i) {
                buf.push_back(i);
            }
        }

        return buf;
    }

    template<typename EdgeT=abstract_edge>
    std::vector<std::shared_ptr<EdgeT>> edges() const {
        std::vector<std::shared_ptr<EdgeT>> buf;

        for (auto e : implEdges()) {
            auto i = std::dynamic_pointer_cast<EdgeT>(e);

            if (i) {
                buf.push_back(i);
            }
        }

        return buf;
    }

    template<typename T=abstract_node>
    bool hasSuperNode(abstract_node_sptr n) const {
        return n->hasUniqueInEdgeFrom<Owns, T>();
    }

    template<typename T=abstract_node>
    size subNodeCountOf(abstract_node_sptr p) const {
        return subNodesOf<T>(p).size();
    }

    template<typename T=abstract_node>
    std::vector<std::shared_ptr<T>> subNodesOf(abstract_node_sptr p) const {
        return p->endNodesOfTypedOutEdgesTo<Owns, T>();
    }

    template<typename T=abstract_node>
    std::shared_ptr<T> superNodeOf(abstract_node_sptr n) const {
        assert(hasSuperNode<T>(n));

        return n->startNodeOfUniqueInEdge<Owns, T>();
    }

    template<typename T>
    std::shared_ptr<T> createSubNodeOf(abstract_node_sptr parent, const name& subNodeName) {
        assert(parent);

        auto n = createNode<T>(subNodeName);
        registerNodeAsSubNodeOf(n, parent);
        return n;
    }

    template<typename T>
    std::shared_ptr<T> createNode(const name& n = name("")) {
        auto node = std::make_shared<T>(this, n, createUuid());
        assert(T::staticNodeName == node->nodeTypeName());
        registerNode(node);
        return node;
    }

    template<typename T>
    std::shared_ptr<T> createEdge(abstract_node_sptr start, abstract_node_sptr end) {
        assert(abstract_node_sptr() != start);
        assert(abstract_node_sptr() != end);

        auto e = std::make_shared<T>(this, createUuid(), start, end);

        assert(T::staticEdgeName == e->edge_type_name());

        registerEdge(e);

        return e;
    }

    abstract_node_sptr node(const object_id& id) const { return implNode(id); }

    size nodeCount() const { return implNodeCount(); }
    size edgeCount() const { return implEdgeCount(); }

    IndexNodeSPtr indexNode() const { return implIndexNode(); }

protected:
    AbstractGraph();

    virtual void implSetTitle(const name& t) = 0;
    virtual name implTitle() const = 0;

    virtual void registerNode(abstract_node_sptr n) = 0;
    virtual void registerNodeAsSubNodeOf(abstract_node_sptr n, abstract_node_sptr p) = 0;
    virtual void registerEdge(abstract_edge_sptr e) = 0;

    virtual size implNodeCount() const = 0;
    virtual size implEdgeCount() const = 0;

    virtual AbstractNodeSPtrVector implNodes() const = 0;
    virtual AbstractEdgeSPtrVector implEdges() const = 0;

    virtual abstract_node_sptr implNode(const object_id& object_id) const = 0;

    virtual IndexNodeSPtr implIndexNode() const = 0;

    virtual object_id createUuid() = 0;
};

}
}
