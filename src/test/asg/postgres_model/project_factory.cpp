/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "project_factory.h"

#include <asg/base/project.h>

#include <asg/relational_model/iso_data_type.h>
#include <asg/relational_model/schema.h>
#include <asg/relational_model/custom_data_type.h>
#include <asg/relational_model/table.h>
#include <asg/relational_model/iso_constant.h>

#include <asg/postgres_model/model.h>
#include <asg/postgres_model/sequence.h>
#include <asg/postgres_model/extension.h>
#include <asg/postgres_model/extension_data_type.h>
#include <asg/postgres_model/provides_data_type.h>

using namespace asg::relational_model;

namespace asg {
namespace postgres_model {
namespace test {

base::project_sptr project_factory::create_project(const string &n)
{
    return project_factory().do_create_project(n);
}

base::project_sptr project_factory::do_create_project(const string &n)
{
    auto proj = std::make_shared<base::project>(name(n));

    auto m = proj->create_node<model>("relational model");

    init_iso_data_types(m);
    init_iso_constants(m);

    init_custom_data_types(m);

    init_schemata(m);

    return proj;
}

void project_factory::init_iso_data_types(model_sptr m)
{
    for (auto tn : relational_model::model::iso_data_type_names) {
        m->create_data_type<iso_data_type>(tn);
    }
}

void project_factory::init_iso_constants(model_sptr m)
{
    for (auto cn : model::iso_constant_names) {
        m->create_constant<iso_constant>(cn);
    }
}

void project_factory::init_custom_data_types(model_sptr m)
{
    for (auto tn : model::custom_data_type_names) {
        m->create_data_type<custom_data_type>(tn);
    }
}

void project_factory::init_schemata(model_sptr m)
{
    init_kernel_schema(m);
    init_data_schema(m);
    init_audit_schema(m);
    init_api_schema(m);
    init_test_schema(m);
}

void project_factory::init_kernel_schema(model_sptr m)
{
    auto kernel = m->create_schema("kernel");

    auto uuid_ossp = kernel->create_schema_fragment<extension>(extension::uuid_extension_name);

    auto uuid_t = m->create_data_type<extension_data_type>(model::uuid_data_type_name);
    uuid_ossp->create_edge_to<provides_data_type>(uuid_t);
}

void project_factory::init_data_schema(model_sptr m)
{
    auto data = m->create_schema("data");

    auto flat = data->create_table<table>("flat_table");
    auto flat_id = flat->create_column("id");

    auto hierarchical = data->create_table<table>("hierarchical_table");
    auto hierarchical_id = hierarchical->create_column("id");
    auto hierarchical_parent_id = hierarchical->create_column("parent_id");
}

void project_factory::init_audit_schema(model_sptr m)
{
    auto audit = m->create_schema("audit");
}

void project_factory::init_api_schema(model_sptr m)
{
    auto api = m->create_schema("api");
}

void project_factory::init_test_schema(model_sptr m)
{
    auto t = m->create_schema("test");
    t->create_schema_fragment<sequence>("seq_test");
}

}
}
}
