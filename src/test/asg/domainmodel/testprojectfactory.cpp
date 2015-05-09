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

namespace asg {
namespace domain_model {
namespace Test {

base::ProjectSPtr TestProjectFactory::createProject(const string &n)
{
    auto proj = std::make_shared<base::project>(name(n));

    auto m = proj->create_node<model>(name("TestModel"));

    auto natSci = m->createBoundedContext("NatSci");

    m->createPrimitiveDataType("Integer");
    return proj;
}

TestProjectFactory::TestProjectFactory()
{

}

}
}
}
