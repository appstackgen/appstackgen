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

    AbstractNodeSPtr start() const { return implStart(); }
    AbstractNodeSPtr end() const { return implEnd(); }

    bool hasStart() const { return (AbstractNodeSPtr() != start()); }
    bool hasEnd() const { return (AbstractNodeSPtr() != end()); }

protected:
    virtual void implSetStart(AbstractNodeSPtr s) = 0;
    virtual void implSetEnd(AbstractNodeSPtr e) = 0;

    virtual AbstractNodeSPtr implStart() const = 0;
    virtual AbstractNodeSPtr implEnd() const = 0;
};

}
}
