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

class Node: public AbstractNode {
public:

protected:
    Node(const Name& name = "", const Description& description = "");

    Uuid implUuid() const override { return m_uuid; }
    Name implName() const override { return m_name; }
    Description implDescription() const override { return m_description; }
    void implSetName(const Name &n) override { m_name = n; }
    void implSetDescription(const Description &d) override  { m_description = d; }
    String implToString() const override { StringStream s; s << name() << " [" << uuid() << "]"; return s.str(); }

    void registerSubNode(std::shared_ptr<AbstractNode> n) override { m_subNodes[n->uuid()] = n; }

private:
    Uuid m_uuid;
    Name m_name { "" };
    Description m_description { "" };

    std::map<Uuid, std::shared_ptr<AbstractNode>> m_subNodes;
};
}
}
