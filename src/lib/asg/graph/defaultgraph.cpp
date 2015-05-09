/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "defaultgraph.h"

#include <asg/graph/indexnode.h>
#include <asg/graph/indexedge.h>
#include <asg/graph/owns.h>

namespace ASG {
namespace Graph {

DefaultGraph::DefaultGraph(const Name &title)
    : m_title(title)
{
    m_indexNode = createNode<IndexNode>(IndexNode::defaultName);
}

void DefaultGraph::registerNode(AbstractNodeSPtr n) {
    assert(n);

    m_nodes[n->id()] = n;

    if (indexNode()) {
        createEdge<IndexEdge>(indexNode(), n);
    }
}

void DefaultGraph::registerNodeAsSubNodeOf(AbstractNodeSPtr n, AbstractNodeSPtr p)
{
    assert(n);
    assert(p);

    registerNode(n);

    createEdge<Owns>(p, n);
}

void DefaultGraph::registerEdge(AbstractEdgeSPtr e) {
    e->start()->registerOutEdge(e);
    e->end()->registerInEdge(e);

    m_edges[e->id()] = e;
}

AbstractNodeSPtrVector DefaultGraph::implNodes() const
{
    AbstractNodeSPtrVector buf;

    for (auto i : m_nodes) {
        buf.push_back(i.second);
    }

    return buf;
}

AbstractEdgeSPtrVector DefaultGraph::implEdges() const
{
    AbstractEdgeSPtrVector buf;

    for (auto e : m_edges) {
        buf.push_back(e.second);
    }

    return buf;
}

AbstractNodeSPtr DefaultGraph::implNode(const ObjectId &id) const
{
    auto i = m_nodes.find(id);

    assert(m_nodes.end() != i);

    return (*i).second;
}

}
}
