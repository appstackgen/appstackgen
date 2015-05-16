/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/string_tools.h>

#include <asg/base/project.h>

#include <asg/graphtools/graph_to_plain_text.h>

#include "project_factory.h"

using namespace asg;
using namespace asg::graph;
using namespace asg::domain_model;
using namespace asg::domain_model::Test;

TEST(test_project, project_to_plain_text)
{
    auto proj = project_factory::create_project("A Project");

    ASSERT_TRUE(proj->has_title());

    ASSERT_EQ(name("A Project"), proj->title());

    ASSERT_EQ(4, proj->node_count());

    std::cout << std::endl << join(GraphToPlainText::toStringVector(proj)) << std::endl;
}
