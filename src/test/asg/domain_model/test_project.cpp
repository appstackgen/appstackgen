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

#include <asg/domain_model/model.h>
#include <asg/domain_model/bounded_context.h>
#include <asg/domain_model/domain.h>
#include <asg/domain_model/domain_object.h>
#include <asg/domain_model/id_value.h>

#include "project_factory.h"

using namespace asg;
using namespace asg::graph;
using namespace asg::graph::tools;
using namespace asg::domain_model;
using namespace asg::domain_model::Test;

TEST(test_project, test_object_has_default_values) {
    auto proj = project_factory::create_project("A Project");

    for (auto model : proj->nodes<model>()) {
        for (auto bounded_context : model->bounded_contexts()) {
            for (auto domain : bounded_context->domains()) {
                for (auto domain_object : domain->domain_objects()) {
                    ASSERT_TRUE(domain_object->id_value().get());
                }
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

    save_to_file(graph_to_dot::to_string_vector(proj), "a_project.dot", "\n");
}
