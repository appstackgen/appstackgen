/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

TEST(GoogleTestSelfTest, ASSERT_EQ) {
    ASSERT_EQ(1, 1);
    ASSERT_EQ(nullptr, nullptr);
}

TEST(GoogleTestSelfTest, ASSERT_TRUE) {
    ASSERT_TRUE(true);
}

TEST(GoogleTestSelfTest, ASSERT_FALSE) {
    ASSERT_FALSE(false);
}
