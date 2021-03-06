/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/system_edge.h>

namespace asg {
namespace graph {

class index_edge : public system_edge
{
public:
    static string static_edge_name;

    using system_edge::system_edge;

protected:
    string impl_edge_type_name() const override;
};

}
}
