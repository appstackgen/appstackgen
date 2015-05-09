/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/objectidgenerator.h>

using namespace asg;

TEST(TestUuidGenerator, createUuid) {
    auto id = object_id_generator::create_id();

    ASSERT_TRUE(id.is_valid());
}

TEST(TestUuidGenerator, createInvalidUuid)  {
    ASSERT_TRUE(!object_id_generator::create_invalid_id().is_valid());
}
