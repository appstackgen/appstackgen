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

class abstract_graph;

class AbstractGraphFragment
{
public:
    virtual ~AbstractGraphFragment() {}

    abstract_graph* graph() const { return impl_graph(); }
    const object_id id() const { return impl_id(); }

    string to_string() const { return impl_to_string(); }

protected:
    AbstractGraphFragment();

    virtual abstract_graph* impl_graph() const = 0;
    virtual const object_id impl_id() const = 0;

    virtual string impl_to_string() const = 0;
};

}
}
