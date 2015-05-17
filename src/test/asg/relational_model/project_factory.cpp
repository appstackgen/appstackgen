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

    return proj;
}

void project_factory::init_iso_data_types(model_sptr m)
{
    for (auto tn : model::iso_data_type_names) {
        m->create_data_type<iso_data_type>(tn);
    }
}

}
}
}
