/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/graphfragment.h>

#include <asg/graph/abstractnode.h>

namespace asg {
namespace graph {

class AbstractEdge;
class AbstractNode;

using AbstractEdgeSPtr = std::shared_ptr<AbstractEdge>;
using AbstractNodeSPtr = std::shared_ptr<AbstractNode>;

class AbstractEdge : public GraphFragment
{
public:
    using GraphFragment::GraphFragment;

    void setStart(AbstractNodeSPtr s) { implSetStart(s); }
    void setEnd(AbstractNodeSPtr e) { implSetEnd(e); }

    template<typename T=AbstractNode>
    std::shared_ptr<T> start() const { return std::dynamic_pointer_cast<T>(implStart()); }

    template<typename T=AbstractNode>
    std::shared_ptr<T> end() const { return std::dynamic_pointer_cast<T>(implEnd()); }

    bool hasStart() const { return (AbstractNodeSPtr() != start()); }
    bool hasEnd() const { return (AbstractNodeSPtr() != end()); }

    string edgeTypeName() const { return implEdgeTypeName(); }

protected:
    virtual void implSetStart(AbstractNodeSPtr s) = 0;
    virtual void implSetEnd(AbstractNodeSPtr e) = 0;

    virtual AbstractNodeSPtr implStart() const = 0;
    virtual AbstractNodeSPtr implEnd() const = 0;

    virtual string implEdgeTypeName() const = 0;

    string implToString() const override;
};

}
}
