/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "testobjectid.h"

#include <asg/kernel/objectid.h>

CPPUNIT_TEST_SUITE_REGISTRATION(ASG::Test::TestObjectId);

namespace ASG {

void Test::TestObjectId::testDefaultCtor()
{
    ObjectId id;

    CPPUNIT_ASSERT(!id.isValid());
}

}
