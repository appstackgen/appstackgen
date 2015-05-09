/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "testprojectfactory.h"

#include <asg/base/project.h>

#include <asg/domainmodel/model.h>
#include <asg/domainmodel/boundedcontext.h>
#include <asg/domainmodel/primitivedatatype.h>

namespace ASG {
namespace DomainModel {
namespace Test {

Base::ProjectSPtr TestProjectFactory::createProject(const string &n)
{
    auto proj = std::make_shared<Base::Project>(name(n));

    auto model = proj->createNode<Model>(name("TestModel"));

    auto natSci = model->createBoundedContext("NatSci");

    model->createPrimitiveDataType("Integer");
    return proj;
}

TestProjectFactory::TestProjectFactory()
{

}

}
}
}
