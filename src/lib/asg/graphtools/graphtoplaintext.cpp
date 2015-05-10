/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "graphtoplaintext.h"

#include <asg/graph/abstract_graph.h>
#include <asg/graph/abstract_node.h>
#include <asg/graph/abstract_edge.h>

namespace asg {
namespace graph {

string_vec GraphToPlainText::toStringVector(AbstractGraphSPtr g)
{
    GraphToPlainText i(g);

    return i.graphToStringVector();
}

GraphToPlainText::GraphToPlainText(AbstractGraphSPtr g)
    : m_g(g)
{

}

string_vec GraphToPlainText::graphToStringVector() const
{
    string_vec buf;

    buf.push_back(string("Graph: ") + m_g->title().to_string());

    for (auto n : m_g->nodes()) {
        buf.push_back("\t" + n->to_string());
    }

    for (auto e : m_g->edges()) {
        buf.push_back("\t" + e->to_string());
    }

    return buf;
}

}
}
