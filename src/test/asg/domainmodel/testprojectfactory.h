/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/types.h>

namespace asg {

namespace Base {
class Project;
using ProjectSPtr = std::shared_ptr<Project>;
}

namespace DomainModel {

namespace Test {

class TestProjectFactory
{
public:
    static Base::ProjectSPtr createProject(const string& n = "Test Project");

protected:
    TestProjectFactory();


};

}
}
}
