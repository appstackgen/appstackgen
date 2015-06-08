/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/types.h>

namespace asg {

namespace base {
class project;
using project_sptr = std::shared_ptr<project>;
}

namespace relational_model {

class model;
class data_type;

using model_sptr = std::shared_ptr<model>;
using data_type_sptr = std::shared_ptr<data_type>;

namespace test {

class project_factory
{
public:
    static base::project_sptr create_project(const string& n = "Test Project");

protected:
    project_factory() {}

    base::project_sptr do_create_project(const string& n);

    void init_iso_data_types(model_sptr m);
    void init_iso_constants(model_sptr m);
    void init_schemata(model_sptr m);
    void init_kernel_schema(model_sptr m);
    void init_data_schema(model_sptr m);
    void init_audit_schema(model_sptr m);
    void init_api_schema(model_sptr m);

    data_type_sptr m_boolean_type;
    data_type_sptr m_integer_type;
    data_type_sptr m_bigint_type;
    data_type_sptr m_numeric_type;
    data_type_sptr m_char_type;
    data_type_sptr m_varchar_type;
    data_type_sptr m_date_type;
    data_type_sptr m_time_type;
    data_type_sptr m_timestamp_type;
};

}
}
}
