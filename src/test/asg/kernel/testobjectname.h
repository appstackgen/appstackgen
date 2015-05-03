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

class TestObjectName: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ASG::Test::TestObjectName);
    CPPUNIT_TEST(testDefaultCtor);
    CPPUNIT_TEST(testEquality);
    CPPUNIT_TEST_SUITE_END();

protected:
    void testDefaultCtor();
    void testEquality();
};

}
}
