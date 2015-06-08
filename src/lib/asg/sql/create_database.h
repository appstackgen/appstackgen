/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/sql/create.h>

namespace asg {

namespace relational_model {
class model;
using model_sptr = std::shared_ptr<model>;
}

namespace sql {

class create_database : public create<relational_model::model>
{
public:
    explicit create_database(relational_model::model_sptr m);
};

}
}
