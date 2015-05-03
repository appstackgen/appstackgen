/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/abstractgraph.h>

#include <asg/kernel/uuidgenerator.h>

#include <asg/graph/abstractnode.h>
#include <asg/graph/abstractedge.h>

namespace ASG {
namespace Graph {

class DefaultGraph : public AbstractGraph
{
public:
    explicit DefaultGraph(const Name& title = Name(""));

protected:
    void implSetTitle(const Name &t) override { m_title = t; }
    Name implTitle() const override { return m_title; }

    void registerNode(AbstractNodeSPtr n) override;
    void registerNodeAsSubNodeOf(AbstractNodeSPtr n, AbstractNodeSPtr p) override;
    void registerEdge(AbstractEdgeSPtr e) override;

    Uuid createUuid() override { return m_uuidGenerator.createUuid(); }

    Size implNodeCount() const override { return m_nodes.size(); }
    Size implEdgeCount() const override { return m_edges.size(); }

    IndexNodeSPtr implIndexNode() const override { return m_indexNode; }

private:
    Name m_title;

    std::map<Uuid, AbstractNodeSPtr> m_nodes;
    std::map<Uuid, AbstractEdgeSPtr> m_edges;

    IndexNodeSPtr m_indexNode;

    UuidGenerator m_uuidGenerator;
};

}
}
