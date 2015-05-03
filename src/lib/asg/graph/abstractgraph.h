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

class AbstractGraph
{
public:
    virtual ~AbstractGraph() {}

    void setTitle(const Name& t) { implSetTitle(t); }

    Name title() const { return implTitle(); }

    bool hasTitle() const { return (!title().empty()); }

    template<typename T=AbstractNode>
    bool hasSuperNode(AbstractNodeSPtr n) const {
        return n->hasUniqueInEdgeFrom<Owns, T>();
    }

    template<typename T=AbstractNode>
    Size subNodeCountOf(AbstractNodeSPtr p) const {
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
    std::shared_ptr<T> createNode(const Name& name = "") {
        auto n = std::make_shared<T>(this, name, createUuid());
        registerNode(n);
        return n;
    }

    template<typename T>
    std::shared_ptr<T> createEdge(AbstractNodeSPtr start, AbstractNodeSPtr end) {
        assert(AbstractNodeSPtr() != start);
        assert(AbstractNodeSPtr() != end);

        auto e = std::make_shared<T>(this, createUuid(), start, end);

        registerEdge(e);

        return e;
    }

    Size nodeCount() const { return implNodeCount(); }
    Size edgeCount() const { return implEdgeCount(); }

    IndexNodeSPtr indexNode() const { return implIndexNode(); }

protected:
    AbstractGraph();

    virtual void implSetTitle(const Name& t) = 0;
    virtual Name implTitle() const = 0;

    virtual void registerNode(AbstractNodeSPtr n) = 0;
    virtual void registerNodeAsSubNodeOf(AbstractNodeSPtr n, AbstractNodeSPtr p) = 0;
    virtual void registerEdge(AbstractEdgeSPtr e) = 0;

    virtual Size implNodeCount() const = 0;
    virtual Size implEdgeCount() const = 0;

    virtual IndexNodeSPtr implIndexNode() const = 0;

    virtual Uuid createUuid() = 0;
};

}
}
