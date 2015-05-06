/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/types.h>

using namespace ASG;

TEST(TestObjectName, testDefaultCtor) {
    ObjectName n;

    ASSERT_EQ(std::string(), n.toString());
}

TEST(TestObjectName, testEquality) {
    ObjectName a("a");
    ObjectName b("b");
    ObjectName a2("a");

    ASSERT_EQ(a, a);
    ASSERT_TRUE(a != b);
    ASSERT_TRUE(a == a);
}
