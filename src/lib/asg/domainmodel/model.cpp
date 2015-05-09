/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "model.h"

#include <asg/graph/abstractgraph.h>

#include <asg/domainmodel/model.h>
#include <asg/domainmodel/primitivedatatype.h>
#include <asg/domainmodel/boundedcontext.h>

namespace ASG {
namespace DomainModel {

string Model::staticNodeName = "Model";

PrimitiveDataTypeSPtr Model::createPrimitiveDataType(const string &name)
{
    return createSubNode<PrimitiveDataType>(name);
}

BoundedContextSPtr Model::createBoundedContext(const string &name)
{
    return createSubNode<BoundedContext>(name);
}

}
}
