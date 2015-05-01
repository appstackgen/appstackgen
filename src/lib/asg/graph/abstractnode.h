/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/graphfragment.h>

namespace ASG {
namespace Graph {

class AbstractGraph;
class AbstractEdge;

using AbstractEdgeSPtr = std::shared_ptr<AbstractEdge>;
using AbstractEdgeSPtrVector = std::vector<AbstractEdgeSPtr>;

class AbstractNode: public GraphFragment
{
public:
    using GraphFragment::GraphFragment;

    void registerOutEdge(AbstractEdgeSPtr e) { implRegisterOutEdge(e); }
    void registerInEdge(AbstractEdgeSPtr e) { implRegisterInEdge(e); }

    AbstractEdgeSPtrVector outEdges() const { return implOutEdges(); }
    AbstractEdgeSPtrVector inEdges() const { return implInEdges(); }

    AbstractEdgeSPtrVector edges() const { return implEdges(); }

    Size outEdgeCount() const { return implOutEdgeCount(); }
    Size inEdgeCount() const { return implInEdgeCount(); }
    Size edgeCount() { return edgeCount(); }

protected:
    virtual void implRegisterOutEdge(AbstractEdgeSPtr e) = 0;
    virtual void implRegisterInEdge(AbstractEdgeSPtr e) = 0;

    virtual AbstractEdgeSPtrVector implOutEdges() const = 0;
    virtual AbstractEdgeSPtrVector implInEdges() const = 0;
    virtual AbstractEdgeSPtrVector implEdges() const = 0;

    virtual Size implOutEdgeCount() const = 0;
    virtual Size implInEdgeCount() const = 0;
    virtual Size implEdgeCount() const = 0;
};

}
}
