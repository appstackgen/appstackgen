/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <gtest/gtest.h>

#include <asg/kernel/string_tools.h>
#include <asg/kernel/file_tools.h>

#include <asg/base/project.h>

#include <asg/graph_tools/graph_to_plain_text.h>
#include <asg/graph_tools/graph_to_dot.h>

#include <asg/relational_model/model.h>
#include <asg/relational_model/schema.h>
#include <asg/relational_model/table.h>
#include <asg/relational_model/primary_key_constraint.h>

#include "project_factory.h"

using namespace asg;
using namespace asg::graph;
using namespace asg::graph::tools;
using namespace asg::relational_model;
using namespace asg::relational_model::test;

TEST(test_project, test_object_has_default_values) {
    auto proj = project_factory::create_project("A Project");

    for (auto model : proj->nodes<model>()) {
        for (auto schema : model->schemata()) {
            for (auto table : schema->tables()) {
                ASSERT_TRUE(table->has_primary_key_constraint());
                ASSERT_TRUE(!table->primary_key_constraint()->columns().empty());
            }
        }
    }
}

TEST(test_project, project_to_plain_text)
{
    auto proj = project_factory::create_project("A Project");

    ASSERT_TRUE(proj->has_title());

    ASSERT_EQ(name("A Project"), proj->title());
}

TEST(test_project, project_to_dot)
{
    auto proj = project_factory::create_project("A Project");

    ASSERT_EQ(name("A Project"), proj->title());

    save_to_file(graph_to_dot::to_string_vector(proj), "relational_project.dot", "\n");
}
