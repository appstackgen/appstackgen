/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "infrastructure.h"

namespace ASG {
namespace Test {

class TestModule : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ASG::Test::TestModule);
    CPPUNIT_TEST(createId);
    CPPUNIT_TEST_SUITE_END();

protected:
    void createId();
};

}
}
