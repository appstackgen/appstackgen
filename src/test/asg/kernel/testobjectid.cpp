/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/object_id.h>

using namespace asg;

TEST(test_object_id, default_ctor) {
    object_id id;

    ASSERT_TRUE(!id.is_valid());
}
