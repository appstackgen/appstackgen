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
