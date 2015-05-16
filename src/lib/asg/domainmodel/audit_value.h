/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domainmodel/system_value.h>

namespace asg {
namespace domain_model {

class audit_value : public system_value
{
public:
    using system_value::system_value;
};

}
}
