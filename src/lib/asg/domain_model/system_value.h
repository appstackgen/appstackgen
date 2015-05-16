/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domain_model/value.h>

namespace asg {
namespace domain_model {

class system_value : public value
{
public:
protected:
    using value::value;
};

}
}
