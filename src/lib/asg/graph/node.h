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

namespace ASG {
namespace Graph {

class Node : public AbstractNode
{
public:
    Node(AbstractGraph* g, const Name& name, const Id& uuid);

protected:
    void implRegisterOutEdge(AbstractEdgeSPtr e) override { assert(e->start().get() == this); m_edges.push_back(e); }
    void implRegisterInEdge(AbstractEdgeSPtr e) override { assert(e->end().get() == this); m_edges.push_back(e); }

    AbstractEdgeSPtrVector implOutEdges() const override;
    AbstractEdgeSPtrVector implInEdges() const override;
    AbstractEdgeSPtrVector implEdges() const override;

    Size implOutEdgeCount() const override { return outEdges().size(); }
    Size implInEdgeCount() const override { return inEdges().size(); }
    Size implEdgeCount() const override { return m_edges.size(); }

private:
    Name m_name;
    AbstractEdgeSPtrVector m_edges;
};

}
}
