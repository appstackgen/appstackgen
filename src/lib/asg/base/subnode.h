/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/base/node.h>

namespace ASG {
namespace Base {

template<typename ParentT>
class SubNode: public Node {
public:
    using ParentNodeType = ParentT;

    ParentNodeType* typedParent() const { return parentAs<ParentNodeType*>(); }

protected:
    SubNode(ParentNodeType* p = nullptr, const Name& name = "", const Description& description = "")
        : Node(name, description), m_parent(p) {
    }

    AbstractNode *implParent() const override { return m_parent; }

private:
    ParentT* m_parent { nullptr };
};
}
}
