/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/types.h>

using namespace asg;

TEST(TestObjectName, testDefaultCtor) {
    object_name n;

    ASSERT_EQ(std::string(), n.toString());
}

TEST(TestObjectName, testEquality) {
    object_name a("a");
    object_name b("b");
    object_name a2("a");

    ASSERT_EQ(a, a);
    ASSERT_TRUE(a != b);
    ASSERT_TRUE(a == a);
}
