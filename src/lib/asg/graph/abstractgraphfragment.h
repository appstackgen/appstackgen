/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/types.h>

namespace ASG {
namespace Graph {

class AbstractGraph;

class AbstractGraphFragment
{
public:
    virtual ~AbstractGraphFragment() {}

    AbstractGraph* graph() const { return implGraph(); }
    Id uuid() const { return implUuid(); }

protected:
    AbstractGraphFragment();

    virtual AbstractGraph* implGraph() const = 0;
    virtual Id implUuid() const = 0;
};

}
}
