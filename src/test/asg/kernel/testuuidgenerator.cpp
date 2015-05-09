/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/uuidgenerator.h>

using namespace asg;

TEST(TestUuidGenerator, createUuid) {
    auto id = uuid_generator::createUuid();

    ASSERT_TRUE(id.is_valid());
}

TEST(TestUuidGenerator, createInvalidUuid)  {
    ASSERT_TRUE(!uuid_generator::createInvalidUuid().is_valid());
}
