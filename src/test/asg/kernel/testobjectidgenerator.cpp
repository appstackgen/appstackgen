/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/object_id_generator.h>

using namespace asg;

TEST(test_object_id_generator, create_id) {
    auto id = object_id_generator::create_id();

    ASSERT_TRUE(id.is_valid());
}

TEST(test_object_id_generator, create_invalid_id)  {
    ASSERT_TRUE(!object_id_generator::create_invalid_id().is_valid());
}
