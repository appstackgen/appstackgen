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
using namespace asg::postgres_model;
using namespace asg::postgres_model::test;

TEST(test_postgres_model, project_to_dot)
{
    auto proj = project_factory::create_project("A Postgres Model Project");

    save_to_file(graph_to_dot::to_string_vector(proj), "postgres_model_project.dot", "\n");
}

TEST(test_postgres_model, table_must_have_non_empty_primary_key)
{
    auto proj = project_factory::create_project("table_must_have_primary_key");

    for (auto db : proj->nodes<relational_model::model>()) {
        for (auto schema : db->schemata()) {
            for (auto table : schema->tables()) {
                ASSERT_TRUE(table->has_primary_key_constraint());
                ASSERT_TRUE(!table->primary_key_constraint()->columns().empty());
            }
        }
    }
}
