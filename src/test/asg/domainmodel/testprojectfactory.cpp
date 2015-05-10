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

base::ProjectSPtr test_project_factory::create_project(const string &n)
{
    auto proj = std::make_shared<base::project>(name(n));

    auto m = proj->create_node<model>(name("TestModel"));

    auto natSci = m->create_bounded_context("NatSci");

    m->create_primitive_data_type("Integer");
    return proj;
}

test_project_factory::test_project_factory()
{

}

}
}
}
