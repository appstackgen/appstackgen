/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/types.h>

namespace asg {
namespace graph {

class AbstractGraph;

class AbstractGraphFragment
{
public:
    virtual ~AbstractGraphFragment() {}

    AbstractGraph* graph() const { return implGraph(); }
    const object_id id() const { return implId(); }

    string toString() const { return impl_to_string(); }

protected:
    AbstractGraphFragment();

    virtual AbstractGraph* implGraph() const = 0;
    virtual const object_id implId() const = 0;

    virtual string impl_to_string() const = 0;
};

}
}
