/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "project_factory.h"

#include <asg/base/project.h>

#include <asg/relational_model/model.h>
#include <asg/relational_model/iso_data_type.h>
#include <asg/relational_model/iso_constant.h>
#include <asg/relational_model/schema.h>
#include <asg/relational_model/table.h>

namespace asg {
namespace relational_model {
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

    init_schemata(m);

    return proj;
}

void project_factory::init_iso_data_types(model_sptr m)
{
    for (auto tn : model::iso_data_type_names) {
        m->create_data_type<iso_data_type>(tn);
    }
}

void project_factory::init_iso_constants(model_sptr m)
{
    for (auto cn : model::iso_constant_names) {
        m->create_constant<iso_constant>(cn);
    }
}

void project_factory::init_schemata(model_sptr m)
{
    init_kernel_schema(m);
    init_data_schema(m);
    init_audit_schema(m);
    init_api_schema(m);
}

void project_factory::init_kernel_schema(model_sptr m)
{
    auto kernel = m->create_schema("kernel");
}

void project_factory::init_data_schema(model_sptr m)
{
    auto data = m->create_schema("data");
}

void project_factory::init_audit_schema(model_sptr m)
{
    auto audit = m->create_schema("audit");
}

void project_factory::init_api_schema(model_sptr m)
{
    auto api = m->create_schema("api");

    auto config_t = api->create_table("configuration");
    config_t->create_column("installation_id");
}

}
}
}
