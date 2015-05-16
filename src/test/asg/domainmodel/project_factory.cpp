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
    auto quantity = si->create_domain_object("quantity");
    auto unit = si->create_domain_object("unit");
    auto prefix = si->create_domain_object("prefix");
}

void project_factory::init_nat_sci_bounded_context(model_sptr m)
{
    auto nat_sci = m->create_bounded_context("nat sci");
    auto physics = nat_sci->create_domain("physics");

    auto chemistry = nat_sci->create_domain("chemistry");
    auto crystal_family = chemistry->create_domain_object("crystal family");
    auto crystal_system = chemistry->create_domain_object("crystal system");
    auto point_group = chemistry->create_domain_object("point group");
    auto lattice_system = chemistry->create_domain_object("lattice system");

    auto element = chemistry->create_domain_object("element");
    auto compound = chemistry->create_domain_object("compound");

    auto cartography = nat_sci->create_domain("cartography");
    auto map_type = cartography->create_domain_object("map type");
    auto map_layer_type = cartography->create_domain_object("map layer type");
    auto map = cartography->create_domain_object("map");
    auto map_layer = cartography->create_domain_object("map layer");

    auto biology = nat_sci->create_domain("biology");
    auto taxon_type = biology->create_domain_object("taxon type");
    auto taxon = biology->create_domain_object("taxon");

    auto geosci = nat_sci->create_domain("geosci");
    auto rock_class = geosci->create_domain_object("rock class");
    auto rock = geosci->create_domain_object("rock");
    auto fossil_type = geosci->create_domain_object("fossil type");
    auto fossil = geosci->create_domain_object("fossil");
    auto tectonic_unit_type = geosci->create_domain_object("tectonic unit type");
    auto tectonic_unit = geosci->create_domain_object("tectonic unit");
    auto stratigraphic_unit_type = geosci->create_domain_object("stratigraphic unit type");
    auto stratigraphic_unit = geosci->create_domain_object("stratigraphic unit");
    auto sedimentologic_unit_type = geosci->create_domain_object("sedimentologic unit type");
    auto sedimentologic_unit = geosci->create_domain_object("sedimentologic unit");
    auto facies = geosci->create_domain_object("facies");
    auto contact_type = geosci->create_domain_object("contact type");
    auto contact = geosci->create_domain_object("contact");
    auto hydrogeological_phenomenon_type = geosci->create_domain_object("hydrogeological phenomenon type");
    auto hydrogeological_phenomenon = geosci->create_domain_object("hydrogeological phenomenon");
    auto stratigraphic_model_type = geosci->create_domain_object("stratigraphic model type");
    auto stratigraphic_model = geosci->create_domain_object("stratigraphic model");
}

base::project_sptr project_factory::create_project(const string &n)
{
    return project_factory().do_create_project(n);
}

void project_factory::init_medical_bounded_context(model_sptr m)
{
    auto medical = m->create_bounded_context("medical");
    auto medical_reference = medical->create_domain("medical reference");
    auto diagnostic_criterion = medical_reference->create_domain_object("diagnostic criterion");
    auto dsm4 = medical_reference->create_domain_object("dsm iv");
    auto dsm5 = medical_reference->create_domain_object("dsm v");
    auto icd10 = medical_reference->create_domain_object("icd10");
    auto icd11 = medical_reference->create_domain_object("icd11");

    auto psychiatry = medical->create_domain("psychiatry");

    auto pharmacology = medical->create_domain("pharmacology");
    auto pharmacological_molecule = pharmacology->create_domain_object("molecule");
    auto drug = pharmacology->create_domain_object("drug");
    auto drug_administration_method = pharmacology->create_domain_object("drug_administration_method");
}

void project_factory::init_statistics_bounded_context(model_sptr m)
{
    auto statistics = m->create_bounded_context("statistics");
    auto data_collecting = statistics->create_domain("data collecting");
    auto data_analytics = statistics->create_domain("data analytics");
}

void project_factory::init_ddd_bounded_context(model_sptr m)
{
    auto ddd = m->create_bounded_context("ddd");
    auto conceptual_model = ddd->create_domain("conceptual model");
    auto relational_model = ddd->create_domain("relational model");
    auto object_model = ddd->create_domain("object model");
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

    init_ddd_bounded_context(m);
    init_infrastructure_bounded_context(m);
    init_nat_sci_bounded_context(m);
    init_medical_bounded_context(m);
    init_statistics_bounded_context(m);

    return proj;
}

}
}
}
