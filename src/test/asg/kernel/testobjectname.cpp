/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "testobjectname.h"

#include <asg/kernel/types.h>

CPPUNIT_TEST_SUITE_REGISTRATION(ASG::Test::TestObjectName);

namespace ASG {
namespace Test {

void TestObjectName::testDefaultCtor()
{
    ObjectName n;

    CPPUNIT_ASSERT_EQUAL(std::string(), n.toString());
}

void TestObjectName::testEquality()
{
    ObjectName a("a");
    ObjectName b("b");
    ObjectName a2("a");

    CPPUNIT_ASSERT_EQUAL(a, a);
    CPPUNIT_ASSERT(a != b);
    CPPUNIT_ASSERT(a == a);
}

}
}
