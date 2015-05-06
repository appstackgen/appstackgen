/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/stringtools.h>

#include <asg/base/project.h>

#include <asg/graphtools/graphtoplaintext.h>

#include "testprojectfactory.h"

using namespace ASG;
using namespace ASG::Graph;
using namespace ASG::DomainModel;
using namespace ASG::DomainModel::Test;

TEST(TestProject, selftestProjectFactory)
{
    auto proj = TestProjectFactory::createProject("A Project");

    ASSERT_TRUE(proj->hasTitle());

    ASSERT_EQ(Name("A Project"), proj->title());

    ASSERT_EQ(3, proj->nodeCount());

    std::cout << std::endl << join(GraphToPlainText::toStringVector(proj)) << std::endl;
}

