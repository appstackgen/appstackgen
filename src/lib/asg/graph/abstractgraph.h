/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/types.h>

namespace ASG {
namespace Graph {

class AbstractNode;
using AbstractNodePtr = AbstractNode*;
using AbstractNodeSPtr = std::shared_ptr<AbstractNode>;

class AbstractGraph
{
public:
    virtual ~AbstractGraph() {}

    void setTitle(const Name& t) { implSetTitle(t); }

    Name title() const { return implTitle(); }

    bool hasTitle() const { return (!title().empty()); }

    template<typename T>
    std::shared_ptr<T> createNode(const Name& name = "") {
        auto n = std::make_shared<T>(this, name, createUuid());
        registerNode(n);
        return n;
    }

    Size nodeCount() const { return implNodeCount(); }

protected:
    AbstractGraph();

    virtual void implSetTitle(const Name& t) = 0;
    virtual Name implTitle() const = 0;

    virtual void registerNode(AbstractNodeSPtr n) = 0;
    virtual Size implNodeCount() const = 0;

    virtual Uuid createUuid() = 0;
};

}
}
