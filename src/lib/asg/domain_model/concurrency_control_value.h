/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domain_model/persistence_value.h>

namespace asg {
namespace domain_model {

class concurrency_control_value : public persistence_value
{
public:
    using persistence_value::persistence_value;
};

}
}
