/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "testuuidgenerator.h"

#include <asg/kernel/uuidgenerator.h>

void ASG::Test::TestUuidGenerator::createUuid()
{
    auto id = UuidGenerator::createUuid();

    CPPUNIT_ASSERT(!id.is_nil());
}

void ASG::Test::TestUuidGenerator::createInvalidUuid()
{
    CPPUNIT_ASSERT(UuidGenerator::createInvalidUuid().is_nil());
}
