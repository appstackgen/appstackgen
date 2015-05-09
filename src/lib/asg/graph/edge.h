/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/abstractedge.h>

namespace ASG {
namespace Graph {

class Edge : public AbstractEdge
{
public:
    Edge(AbstractGraph* g, const ObjectId& id, AbstractNodeSPtr start, AbstractNodeSPtr end);

protected:
    void implSetStart(AbstractNodeSPtr s) override { m_start = s; }
    void implSetEnd(AbstractNodeSPtr e) override { m_end = e; }

    AbstractNodeSPtr implStart() const { return m_start; }
    AbstractNodeSPtr implEnd() const { return m_end; }

private:
    AbstractNodeSPtr m_start;
    AbstractNodeSPtr m_end;
};

}
}
