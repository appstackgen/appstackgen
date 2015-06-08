/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/string_tools.h>

#include <asg/sql/script.h>
#include <asg/sql/statement.h>

using namespace asg;
using namespace asg::sql;

TEST(test_script, default_ctor) {
    script s;

    ASSERT_EQ((size)0, s.size());
    ASSERT_TRUE(s.empty());

    s.rollback();
    s.begin();
    s.commit();

    ASSERT_EQ((size)3, s.size());
    ASSERT_FALSE(s.empty());

    std::cout << std::endl << join(s.sql(true, true), "\n") << std::endl;
}


