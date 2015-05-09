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

namespace ASG {
namespace Graph {

class AbstractNode;
class AbstractEdge;
class IndexNode;

using AbstractNodePtr = AbstractNode*;

using AbstractNodeSPtr = std::shared_ptr<AbstractNode>;
using AbstractEdgeSPtr = std::shared_ptr<AbstractEdge>;
using IndexNodeSPtr = std::shared_ptr<IndexNode>;
using AbstractEdgeSPtr = std::shared_ptr<AbstractEdge>;

using AbstractNodeSPtrVector = std::vector<AbstractNodeSPtr>;
using AbstractEdgeSPtrVector = std::vector<AbstractEdgeSPtr>;

class AbstractGraph
{
public:
    virtual ~AbstractGraph() {}

    void setTitle(const Name& t) { implSetTitle(t); }

    Name title() const { return implTitle(); }

    bool hasTitle() const { return (!title().isEmpty()); }

    template<typename NodeT=AbstractNode>
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

    template<typename EdgeT=AbstractEdge>
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

    template<typename T=AbstractNode>
    bool hasSuperNode(AbstractNodeSPtr n) const {
        return n->hasUniqueInEdgeFrom<Owns, T>();
    }

    template<typename T=AbstractNode>
    size subNodeCountOf(AbstractNodeSPtr p) const {
        return subNodesOf<T>(p).size();
    }

    template<typename T=AbstractNode>
    std::vector<std::shared_ptr<T>> subNodesOf(AbstractNodeSPtr p) const {
        return p->endNodesOfTypedOutEdgesTo<Owns, T>();
    }

    template<typename T=AbstractNode>
    std::shared_ptr<T> superNodeOf(AbstractNodeSPtr n) const {
        assert(hasSuperNode<T>(n));

        return n->startNodeOfUniqueInEdge<Owns, T>();
    }

    template<typename T>
    std::shared_ptr<T> createSubNodeOf(AbstractNodeSPtr parent, const Name& subNodeName) {
        assert(parent);

        auto n = createNode<T>(subNodeName);
        registerNodeAsSubNodeOf(n, parent);
        return n;
    }

    template<typename T>
    std::shared_ptr<T> createNode(const Name& name = Name("")) {
        auto n = std::make_shared<T>(this, name, createUuid());
        assert(T::staticNodeName == n->nodeTypeName());
        registerNode(n);
        return n;
    }

    template<typename T>
    std::shared_ptr<T> createEdge(AbstractNodeSPtr start, AbstractNodeSPtr end) {
        assert(AbstractNodeSPtr() != start);
        assert(AbstractNodeSPtr() != end);

        auto e = std::make_shared<T>(this, createUuid(), start, end);

        assert(T::staticEdgeName == e->edgeTypeName());

        registerEdge(e);

        return e;
    }

    AbstractNodeSPtr node(const ObjectId& id) const { return implNode(id); }

    size nodeCount() const { return implNodeCount(); }
    size edgeCount() const { return implEdgeCount(); }

    IndexNodeSPtr indexNode() const { return implIndexNode(); }

protected:
    AbstractGraph();

    virtual void implSetTitle(const Name& t) = 0;
    virtual Name implTitle() const = 0;

    virtual void registerNode(AbstractNodeSPtr n) = 0;
    virtual void registerNodeAsSubNodeOf(AbstractNodeSPtr n, AbstractNodeSPtr p) = 0;
    virtual void registerEdge(AbstractEdgeSPtr e) = 0;

    virtual size implNodeCount() const = 0;
    virtual size implEdgeCount() const = 0;

    virtual AbstractNodeSPtrVector implNodes() const = 0;
    virtual AbstractEdgeSPtrVector implEdges() const = 0;

    virtual AbstractNodeSPtr implNode(const ObjectId& id) const = 0;

    virtual IndexNodeSPtr implIndexNode() const = 0;

    virtual Id createUuid() = 0;
};

}
}
