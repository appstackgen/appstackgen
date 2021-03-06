/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/base/project.h>

using namespace asg;
using namespace asg::base;

TEST(test_project, ctor) {
    auto proj = std::unique_ptr<project>(new project(name("A Project")));

    ASSERT_TRUE(proj->has_title());

    ASSERT_EQ(name("A Project"), proj->title());
}

