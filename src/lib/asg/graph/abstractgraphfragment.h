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
    const Id id() const { return implId(); }

    string toString() const { return implToString(); }

protected:
    AbstractGraphFragment();

    virtual AbstractGraph* implGraph() const = 0;
    virtual const Id implId() const = 0;

    virtual string implToString() const = 0;
};

}
}
