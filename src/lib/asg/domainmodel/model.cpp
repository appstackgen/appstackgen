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

String Model::staticNodeName = "Model";

PrimitiveDataTypeSPtr Model::createPrimitiveDataType(const String &name)
{
    return createSubNode<PrimitiveDataType>(name);
}

BoundedContextSPtr Model::createBoundedContext(const String &name)
{
    return createSubNode<BoundedContext>(name);
}

}
}
