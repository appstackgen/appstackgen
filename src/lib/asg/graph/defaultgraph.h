/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/abstractgraph.h>

#include <asg/kernel/objectidgenerator.h>

#include <asg/graph/abstractnode.h>
#include <asg/graph/abstractedge.h>

namespace asg {
namespace Graph {

class DefaultGraph : public AbstractGraph
{
public:
    explicit DefaultGraph(const name& title = name(""));

protected:
    void implSetTitle(const name &t) override { m_title = t; }
    name implTitle() const override { return m_title; }

    void registerNode(AbstractNodeSPtr n) override;
    void registerNodeAsSubNodeOf(AbstractNodeSPtr n, AbstractNodeSPtr p) override;
    void registerEdge(AbstractEdgeSPtr e) override;

    object_id createUuid() override { return m_uuidGenerator.create_id(); }

    size implNodeCount() const override { return m_nodes.size(); }
    size implEdgeCount() const override { return m_edges.size(); }

    IndexNodeSPtr implIndexNode() const override { return m_indexNode; }

    AbstractNodeSPtrVector implNodes() const override;
    AbstractEdgeSPtrVector implEdges() const override;

    AbstractNodeSPtr implNode(const object_id& object_id) const override;

private:
    name m_title;

    AbstractNodeSPtrVector m_nodes;
    AbstractEdgeSPtrVector m_edges;

    IndexNodeSPtr m_indexNode;

    object_id_generator m_uuidGenerator;
};

}
}
