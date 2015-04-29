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

class TestUuidGenerator: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ASG::Test::TestUuidGenerator);
    CPPUNIT_TEST(createUuid);
    CPPUNIT_TEST(createInvalidUuid);
    CPPUNIT_TEST_SUITE_END();

protected:
    void createUuid();
    void createInvalidUuid();
};

}
}
