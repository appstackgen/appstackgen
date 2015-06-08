/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "create_database.h"

#include <asg/relational_model/model.h>

namespace asg {
namespace sql {

create_database::create_database(relational_model::model_sptr m)
    : create(m)
{
    stringstream s;
    s << "create database " << m->name();

    set_text(s.str());
}

}
}
