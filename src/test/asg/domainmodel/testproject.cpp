/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "testproject.h"

#include <asg/base/project.h>

#include "testprojectfactory.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ASG::DomainModel::Test::TestProject);

namespace ASG {
namespace DomainModel {
namespace Test {

void TestProject::selftestProjectFactory()
{
    auto proj = TestProjectFactory::createProject("A Project");

    CPPUNIT_ASSERT(proj->hasName());
    CPPUNIT_ASSERT(!proj->hasDescription());

    CPPUNIT_ASSERT_EQUAL(Name("A Project"), proj->name());
}

}
}
}
