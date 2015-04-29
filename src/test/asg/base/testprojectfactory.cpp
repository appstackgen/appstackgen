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
namespace Base {
namespace Test {

ProjectSPtr TestProjectFactory::createProject(const Name &n)
{
    return std::make_shared<Project>(n);
}

TestProjectFactory::TestProjectFactory()
{

}

}
}
}
