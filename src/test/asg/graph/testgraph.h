/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "infrastructure.h"

namespace ASG {
namespace Graph {
namespace Test {

class TestGraph : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ASG::Graph::Test::TestGraph);
    CPPUNIT_TEST(createGraph);
    CPPUNIT_TEST_SUITE_END();

protected:
    void createGraph();
};

}
}
}
