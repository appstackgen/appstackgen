/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "infrastructure.h"

namespace ASG {
namespace DomainModel {
namespace Test {

class TestProject : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ASG::DomainModel::Test::TestProject);
    CPPUNIT_TEST(selftestProjectFactory);
    CPPUNIT_TEST_SUITE_END();

protected:
    void selftestProjectFactory();
};

}
}
}
