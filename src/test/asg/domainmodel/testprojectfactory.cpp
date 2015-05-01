/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "testprojectfactory.h"

#include <asg/base/project.h>

namespace ASG {
namespace DomainModel {
namespace Test {

Base::ProjectSPtr TestProjectFactory::createProject(const Name &n)
{
    return std::make_shared<Base::Project>(n);
}

TestProjectFactory::TestProjectFactory()
{

}

}
}
}
