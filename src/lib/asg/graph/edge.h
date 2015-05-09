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
    Edge(AbstractGraph* g, const object_id& id, abstract_node_sptr start, abstract_node_sptr end);

protected:
    void impl_set_start(abstract_node_sptr s) override { m_start = s; }
    void impl_set_end(abstract_node_sptr e) override { m_end = e; }

    abstract_node_sptr impl_start() const { return m_start; }
    abstract_node_sptr impl_end() const { return m_end; }

private:
    abstract_node_sptr m_start;
    abstract_node_sptr m_end;
};

}
}
