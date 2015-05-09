/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/usernode.h>

namespace ASG {
namespace DomainModel {

class PrimitiveDataType;
class BoundedContext;

using PrimitiveDataTypeSPtr = std::shared_ptr<PrimitiveDataType>;
using BoundedContextSPtr = std::shared_ptr<BoundedContext>;

using PrimitiveDataTypeSPtrVector = std::vector<PrimitiveDataTypeSPtr>;
using BoundedContextSPtrVector = std::vector<BoundedContextSPtr>;

class Model : public ASG::Graph::UserNode
{
public:
    static string staticNodeName;

    PrimitiveDataTypeSPtr createPrimitiveDataType(const string& name);
    BoundedContextSPtr createBoundedContext(const string& name);

    const PrimitiveDataTypeSPtrVector primtiveDataTypes() const;
    const BoundedContextSPtrVector boundedContexts() const;

protected:
    virtual string implNodeTypeName() const override { return staticNodeName; }

    using ASG::Graph::UserNode::UserNode;
};

}
}
