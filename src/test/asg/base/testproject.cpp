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

TEST(TestProject, testProjectCtor) {
    auto proj = std::unique_ptr<Project>(new Project(name("A Project")));

    ASSERT_TRUE(proj->has_title());

    ASSERT_EQ(name("A Project"), proj->title());
}

