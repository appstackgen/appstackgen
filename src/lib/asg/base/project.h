/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/types.h>

#include <asg/base/abstractnode.h>

namespace ASG {
namespace Base {

class Project: public AbstractNode
{
public:
    explicit Project(const Name& name = "", const Description& description = "");
    virtual ~Project() {}

protected:
    Uuid implUuid() const override { return m_uuid; }
    Name implName() const override { return m_name; }
    Description implDescription() const override { return m_description; }
    AbstractNode* implParent() const override { return nullptr; }

    void implSetName(const Name &n) override { m_name = n; }
    void implSetDescription(const Description &d) override { m_description = d; }

    String implToString() const { StringStream s; s << name() << " [" << uuid() << "]"; return s.str(); }

private:
    Uuid m_uuid;
    Name m_name { "" };
    Description m_description { "" };
};

}
}
