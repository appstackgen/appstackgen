/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domain_model/system_value.h>

namespace asg {
namespace domain_model {

class persistence_value : public system_value
{
public:
protected:
    using system_value::system_value;
};

}
}
