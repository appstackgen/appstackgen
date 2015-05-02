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

namespace ASG {
namespace Graph {

DefaultGraph::DefaultGraph(const Name &title)
    : m_title(title)
{
    m_indexNode = createNode<IndexNode>(IndexNode::defaultName);
}

void DefaultGraph::registerNode(AbstractNodeSPtr n) {
    m_nodes[n->uuid()] = n;

    if (indexNode()) {
        createEdge<IndexEdge>(indexNode(), n);
    }
}

void DefaultGraph::registerEdge(AbstractEdgeSPtr e) {
    e->start()->registerOutEdge(e);
    e->end()->registerInEdge(e);

    m_edges[e->uuid()] = e;
}

}
}
