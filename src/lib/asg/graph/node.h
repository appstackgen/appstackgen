/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/abstractnode.h>

#include <asg/graph/abstractedge.h>
#include <asg/graph/abstractgraph.h>

namespace ASG {
namespace Graph {

class Node : public AbstractNode
{
public:
    Node(AbstractGraph* g, const ObjectName& name, const Id& id);

protected:
    template<typename T>
    std::shared_ptr<T> createSubNode(const string& name) {
        return graph()->createSubNodeOf<T>(graph()->node(id()), ObjectName(name));
    }

    void implRegisterOutEdge(AbstractEdgeSPtr e) override { assert(e->start().get() == this); m_edges.push_back(e); }
    void implRegisterInEdge(AbstractEdgeSPtr e) override { assert(e->end().get() == this); m_edges.push_back(e); }

    AbstractEdgeSPtrVector implOutEdges() const override;
    AbstractEdgeSPtrVector implInEdges() const override;
    AbstractEdgeSPtrVector implEdges() const override;

    size implOutEdgeCount() const override { return outEdges().size(); }
    size implInEdgeCount() const override { return inEdges().size(); }
    size implEdgeCount() const override { return m_edges.size(); }

    ObjectName implName() const override { return m_name; }

private:
    ObjectName m_name;
    AbstractEdgeSPtrVector m_edges;
};

}
}
