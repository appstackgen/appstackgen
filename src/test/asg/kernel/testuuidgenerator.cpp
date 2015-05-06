/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/uuidgenerator.h>

using namespace ASG;

TEST(TestUuidGenerator, createUuid) {
    auto id = UuidGenerator::createUuid();

    ASSERT_TRUE(id.isValid());
}

TEST(TestUuidGenerator, createInvalidUuid)  {
    ASSERT_TRUE(!UuidGenerator::createInvalidUuid().isValid());
}
