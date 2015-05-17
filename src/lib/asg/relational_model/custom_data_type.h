/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/data_type.h>

namespace asg {
namespace relational_model {

class custom_data_type : public data_type
{
public:
    using data_type::data_type;
};

}
}
