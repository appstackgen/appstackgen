/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "graph_to_plain_text.h"

#include <asg/graph/abstract_graph.h>
#include <asg/graph/abstract_node.h>
#include <asg/graph/abstract_edge.h>
#include <asg/graph/index_node.h>
#include <asg/graph/index_edge.h>

namespace asg {
namespace graph {
namespace tools {

string_vec graph_to_plain_text::to_string_vector(abstract_graph_sptr g)
{
    graph_to_plain_text i(g);

    return i.graph_to_string_vector();
}

graph_to_plain_text::graph_to_plain_text(abstract_graph_sptr g)
    : m_g(g)
{

}

string_vec graph_to_plain_text::graph_to_string_vector() const
{
    string_vec buf;

    buf.push_back(string("Graph: ") + m_g->title().to_string());

    for (auto n : m_g->nodes()) {
        buf.push_back("\t" + n->name().to_string());
    }

    for (auto e : m_g->edges()) {
        buf.push_back("\t" + e->to_string());
    }

    return buf;
}

}
}
}
