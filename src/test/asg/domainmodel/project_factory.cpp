/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "project_factory.h"

#include <asg/base/project.h>

#include <asg/domainmodel/model.h>
#include <asg/domainmodel/bounded_context.h>
#include <asg/domainmodel/primitive_data_type.h>
#include <asg/domainmodel/domain.h>

namespace asg {
namespace domain_model {
namespace Test {

void project_factory::init_infrastructure_bounded_context(model_sptr m)
{
    auto infrastructure = m->create_bounded_context("infrastructure");
    auto si = infrastructure->create_domain("si system");
    auto si_unit = si->create_domain_object("si unit");
    auto si_prefix = si->create_domain_object("si prefix");
}

void project_factory::init_nat_sci_bounded_context(model_sptr m)
{
    auto nat_sci = m->create_bounded_context("nat sci");
    auto physics = nat_sci->create_domain("physics");
    auto chemistry = nat_sci->create_domain("chemistry");
    auto element = chemistry->create_domain_object("element");
    auto compound = chemistry->create_domain_object("compound");
    auto geosci = nat_sci->create_domain("geosci");
    auto map_type = geosci->create_domain_object("map type");
    auto map_layer_type = geosci->create_domain_object("map layer type");
    auto map = geosci->create_domain_object("map");
    auto map_layer = geosci->create_domain_object("map layer");
}

base::project_sptr project_factory::create_project(const string &n)
{
    return project_factory().do_create_project(n);
}

void project_factory::init_medical_bounded_context(model_sptr m)
{
    auto medical = m->create_bounded_context("medical");
    auto medical_reference = medical->create_domain("medical reference");
    auto dsm4 = medical_reference->create_domain_object("dsm iv");
    auto dsm5 = medical_reference->create_domain_object("dsm v");
    auto icd10 = medical_reference->create_domain_object("icd10");
    auto icd11 = medical_reference->create_domain_object("icd11");

    auto psychiatry = medical->create_domain("psychiatry");
    auto pharmacology = medical->create_domain("pharmacology");
    auto pharmacological_molecule = pharmacology->create_domain_object("molecule");
    auto drug = pharmacology->create_domain_object("drug");
}

void project_factory::init_statistics_bounded_context(model_sptr m)
{
    auto statistics = m->create_bounded_context("statistics");
    auto data_collecting = statistics->create_domain("data collecting");
    auto data_analytics = statistics->create_domain("data analytics");
}

void project_factory::init_primitive_data_types(model_sptr m)
{
    for (auto tn : model::default_primitve_data_type_names) {
        m->create_primitive_data_type(tn);
    }
}

base::project_sptr project_factory::do_create_project(const string &n)
{
    auto proj = std::make_shared<base::project>(name(n));

    auto m = proj->create_node<model>(name("test_model"));
    init_primitive_data_types(m);

    init_infrastructure_bounded_context(m);
    init_nat_sci_bounded_context(m);
    init_medical_bounded_context(m);
    init_statistics_bounded_context(m);

    return proj;
}

}
}
}
