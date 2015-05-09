/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "node.h"

namespace asg {
namespace Graph {

Node::Node(AbstractGraph *g, const object_name &name, const object_id &uuid)
    : AbstractNode(g, uuid), m_name(name)
{
}

AbstractEdgeSPtrVector Node::implOutEdges() const {
    AbstractEdgeSPtrVector buf;

    for (auto e : m_edges) {
        if (e->start().get() == this) {
            buf.push_back(e);
        }
    }

    return buf;
}

AbstractEdgeSPtrVector Node::implInEdges() const {
    AbstractEdgeSPtrVector buf;

    for (auto e : m_edges) {
        if (e->end().get() == this) {
            buf.push_back(e);
        }
    }

    return buf;
}

AbstractEdgeSPtrVector Node::implEdges() const {
    return m_edges;
}

}
}
