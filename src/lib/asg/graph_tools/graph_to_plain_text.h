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
using abstract_graph_sptr = std::shared_ptr<abstract_graph>;

class graph_to_plain_text
{
public:
    static string_vec to_string_vector(abstract_graph_sptr g);

protected:
    graph_to_plain_text(abstract_graph_sptr g);

    string_vec graph_to_string_vector() const;

private:
    abstract_graph_sptr m_g;
};

}
}
