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
namespace Base {

class AbstractNode
{
public:
    virtual ~AbstractNode();

    Uuid uuid() const { return implUuid(); }

    String toString() const { return implToString(); }
    Name name() const { return implName(); }
    Description description() const { return implDescription(); }
    AbstractNode* parent() const { return implParent(); }

    bool hasName() const { return (!name().empty()); }
    bool hasDescription() const { return (!description().empty()); }
    bool hasParent() const { return (nullptr != parent()); }

    void setName(const Name& n) { implSetName(n); }
    void setDescription(const Description& d) { implSetDescription(d); }

protected:
    AbstractNode();

    virtual AbstractNode* implParent() const = 0;

    virtual Uuid implUuid() const = 0;
    virtual Name implName() const = 0;
    virtual Description implDescription() const = 0;

    virtual void implSetName(const Name& n) = 0;
    virtual void implSetDescription(const Description& d) = 0;

    virtual String implToString() const = 0;
};

}
}
