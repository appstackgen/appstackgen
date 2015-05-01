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
    virtual ~AbstractNode() {}

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

    template<typename T>
    T as() {
        return dynamic_cast<T>(this);
    }

    template<typename T>
    bool canCastTo() {
        return (nullptr != dynamic_cast<T>(this));
    }

    template<typename ParentNodeT>
    bool canCastParentNodeTo() const {
        assert(hasParent());

        return (parent()->canCastTo<ParentNodeT>());
    }

    template<typename ParentNodeT>
    ParentNodeT parentAs() const {
        assert(hasParent());
        assert(canCastParentNodeTo<ParentNodeT>());
        return parent()->as<ParentNodeT>();
    }

    template<typename SubNodeT>
    std::shared_ptr<SubNodeT> createSubNode(const Name& name = "", const Description& d = "") {
        auto n = std::make_shared<SubNodeT>(new SubNodeT(this, name, description));
        registerSubNode(n);
        return n;
    }

protected:
    AbstractNode() {}

    virtual AbstractNode* implParent() const = 0;

    virtual Uuid implUuid() const = 0;
    virtual Name implName() const = 0;
    virtual Description implDescription() const = 0;

    virtual void implSetName(const Name& n) = 0;
    virtual void implSetDescription(const Description& d) = 0;

    virtual String implToString() const = 0;

    virtual void registerSubNode(std::shared_ptr<AbstractNode> n) = 0;
};

}
}
