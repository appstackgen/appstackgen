/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/objectid.h>

using namespace asg;

TEST(TestObjectId, testDefaultCtor) {
    object_id id;

    ASSERT_TRUE(!id.is_valid());
}
