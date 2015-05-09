/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/abstractedge.h>

namespace asg {
namespace graph {

class Edge : public abstract_edge
{
public:
    Edge(AbstractGraph* g, const object_id& id, AbstractNodeSPtr start, AbstractNodeSPtr end);

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
