/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "testmodule.h"

#include <asg/kernel/module.h>

CPPUNIT_TEST_SUITE_REGISTRATION(ASG::Test::TestModule);

namespace ASG {
namespace Test {

void TestModule::createId()
{
    CPPUNIT_ASSERT(0 != 1);
}

}
}
