/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/uuidgenerator.h>

#include <asg/base/abstractnode.h>

namespace ASG {
namespace Base {

template<typename ParentNodeT>
class Node: public AbstractNode {
public:
    using ParentNodeType = ParentNodeT;

    template<typename T=ParentNodeType>
    ParentNodeType* typedParent() const { return dynamic_cast<T*>(parent()); }

protected:
    Node(ParentNodeT* parent = nullptr, const Name& name = "", const Description& description = "")
        : AbstractNode(), m_parent(parent), m_name(name), m_description(description)
    {
        m_uuid = UuidGenerator::createUuid();
    }

    Uuid implUuid() const override { return m_uuid; }
    Name implName() const override { return m_name; }
    Description implDescription() const override { return m_description; }
    void implSetName(const Name &n) override { m_name = n; }
    void implSetDescription(const Description &d) override  { m_description = d; }
    String implToString() const override { StringStream s; s << name() << " [" << uuid() << "]"; return s.str(); }

    ParentNodeType* implParent() const { return m_parent; }

private:
    ParentNodeType* m_parent { nullptr };
    Uuid m_uuid;
    Name m_name { "" };
    Description m_description { "" };

};
}
}
