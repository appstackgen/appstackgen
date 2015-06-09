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
#include <asg/relational_model/primary_key_constraint.h>
#include <asg/relational_model/table_column.h>

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

    auto m = proj->create_node<model>("testdb");

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

    m_boolean_type = m->data_type(model::boolean_type_name);
    m_integer_type = m->data_type(model::integer_type_name);
    m_bigint_type = m->data_type(model::bigint_type_name);
    m_numeric_type = m->data_type(model::numeric_type_name);
    m_char_type = m->data_type(model::char_type_name);
    m_varchar_type = m->data_type(model::varchar_type_name);
    m_date_type = m->data_type(model::date_type_name);
    m_time_type = m->data_type(model::time_type_name);
    m_timestamp_type = m->data_type(model::timestamp_type_name);
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
    auto config_id = config_t->create_column("installation_id", m_integer_type);
    config_id->create_not_null_constraint();
    auto config_pk = config_t->create_primary_key_constraint("pk_config");
    config_pk->append(config_id);
}

}
}
}
