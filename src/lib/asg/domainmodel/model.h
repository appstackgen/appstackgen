/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/usernode.h>

namespace asg {
namespace DomainModel {

class PrimitiveDataType;
class BoundedContext;

using PrimitiveDataTypeSPtr = std::shared_ptr<PrimitiveDataType>;
using BoundedContextSPtr = std::shared_ptr<BoundedContext>;

using PrimitiveDataTypeSPtrVector = std::vector<PrimitiveDataTypeSPtr>;
using BoundedContextSPtrVector = std::vector<BoundedContextSPtr>;

class Model : public asg::graph::user_node
{
public:
    static string static_node_type_name;

    PrimitiveDataTypeSPtr createPrimitiveDataType(const string& name);
    BoundedContextSPtr createBoundedContext(const string& name);

    const PrimitiveDataTypeSPtrVector primtiveDataTypes() const;
    const BoundedContextSPtrVector boundedContexts() const;

protected:
    virtual string impl_node_type_name() const override { return static_node_type_name; }

    using asg::graph::user_node::user_node;
};

}
}
