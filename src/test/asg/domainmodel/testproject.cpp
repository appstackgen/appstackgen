/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/base/project.h>

#include "testprojectfactory.h"

using namespace ASG;
using namespace ASG::DomainModel;
using namespace ASG::DomainModel::Test;

TEST(TestProject, selftestProjectFactory)
{
    auto proj = TestProjectFactory::createProject("A Project");

    ASSERT_TRUE(proj->hasTitle());

    ASSERT_EQ(Name("A Project"), proj->title());
}

