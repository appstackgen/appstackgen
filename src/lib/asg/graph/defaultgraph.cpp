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

namespace asg {
namespace graph {

DefaultGraph::DefaultGraph(const name &title)
    : m_title(title)
{
    m_indexNode = createNode<IndexNode>(IndexNode::defaultName);
}

void DefaultGraph::registerNode(abstract_node_sptr n) {
    assert(n);

    m_nodes.push_back(n);

    if (indexNode()) {
        createEdge<IndexEdge>(indexNode(), n);
    }
}

void DefaultGraph::registerNodeAsSubNodeOf(abstract_node_sptr n, abstract_node_sptr p)
{
    assert(n);
    assert(p);

    createEdge<Owns>(p, n);
}

void DefaultGraph::registerEdge(abstract_edge_sptr e) {
    e->start()->registerOutEdge(e);
    e->end()->registerInEdge(e);

    m_edges.push_back(e);
}

AbstractNodeSPtrVector DefaultGraph::implNodes() const
{
    return m_nodes;
}

AbstractEdgeSPtrVector DefaultGraph::implEdges() const
{
    return m_edges;
}

abstract_node_sptr DefaultGraph::implNode(const object_id &id) const
{
    auto i = std::find_if(std::begin(m_nodes), std::end(m_nodes), [=](abstract_node_sptr n) { return (n->id() == id); });

    assert(std::end(m_nodes) != i);

    return *i;
}

}
}
