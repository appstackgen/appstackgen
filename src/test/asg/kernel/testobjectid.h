/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include "infrastructure.h"

namespace ASG {
namespace Test {
class TestObjectId : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ASG::Test::TestObjectId);
    CPPUNIT_TEST(testDefaultCtor);
    CPPUNIT_TEST_SUITE_END();

public:
    void testDefaultCtor();
};

}
}
