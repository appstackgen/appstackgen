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
using project_sptr = std::shared_ptr<project>;
}

namespace relational_model {

class model;

using model_sptr = std::shared_ptr<model>;

namespace test {

class project_factory
{
public:
    static base::project_sptr create_project(const string& n = "Test Project");

protected:
    project_factory() {}

    base::project_sptr do_create_project(const string& n);
};

}
}
}
