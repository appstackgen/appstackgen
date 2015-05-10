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

namespace base {
class project;
using ProjectSPtr = std::shared_ptr<project>;
}

namespace domain_model {

namespace Test {

class project_factory
{
public:
    static base::ProjectSPtr create_project(const string& n = "Test Project");

protected:
    project_factory() {}


};

}
}
}
