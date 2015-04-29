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

class Project;
using ProjectSPtr = std::shared_ptr<Project>;

namespace Test {

class TestProjectFactory
{
public:
    static ProjectSPtr createProject(const Name& n = "Test Project");

protected:
    TestProjectFactory();
};

}
}
}
