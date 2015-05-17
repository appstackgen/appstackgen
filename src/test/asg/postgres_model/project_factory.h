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

using model_sptr = std::shared_ptr<model>;
}

namespace postgres_model {

namespace test {

class project_factory
{
public:
    static base::project_sptr create_project(const string& n = "Test Project");

protected:
    project_factory() {}

    base::project_sptr do_create_project(const string& n);

    void init_iso_data_types(relational_model::model_sptr m);
    void init_schemata(relational_model::model_sptr m);
    void init_kernel_schema(relational_model::model_sptr m);
    void init_data_schema(relational_model::model_sptr m);
    void init_audit_schema(relational_model::model_sptr m);
    void init_api_schema(relational_model::model_sptr m);
    void init_test_schema(relational_model::model_sptr m);
};

}
}
}
