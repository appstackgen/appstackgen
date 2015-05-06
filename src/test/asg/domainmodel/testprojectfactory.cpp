/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "testprojectfactory.h"

#include <asg/base/project.h>

#include <asg/domainmodel/boundedcontext.h>
#include <asg/domainmodel/primitivedatatype.h>

namespace ASG {
namespace DomainModel {
namespace Test {

Base::ProjectSPtr TestProjectFactory::createProject(const String &n)
{
    auto proj = std::make_shared<Base::Project>(Name(n));

    proj->createNode<BoundedContext>(Name("NatSci"));

    proj->createNode<PrimitiveDataType>(Name("Integer"));
    return proj;
}

TestProjectFactory::TestProjectFactory()
{

}

}
}
}
