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

using namespace asg;
using namespace asg::graph;
using namespace asg::domain_model;
using namespace asg::domain_model::Test;

TEST(TestProject, selftestProjectFactory)
{
    auto proj = TestProjectFactory::createProject("A Project");

    ASSERT_TRUE(proj->has_title());

    ASSERT_EQ(name("A Project"), proj->title());

    ASSERT_EQ(4, proj->node_count());

    std::cout << std::endl << join(GraphToPlainText::toStringVector(proj)) << std::endl;
}

