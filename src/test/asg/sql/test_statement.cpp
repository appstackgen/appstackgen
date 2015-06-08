/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/sql/statement.h>

using namespace asg;
using namespace asg::sql;

TEST(test_sql, default_ctor) {
    statement s;

    ASSERT_EQ(std::string(), s.text());
    ASSERT_FALSE(s.has_text());
}

