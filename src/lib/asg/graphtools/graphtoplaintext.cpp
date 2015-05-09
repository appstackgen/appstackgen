/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "graphtoplaintext.h"

#include <asg/graph/abstractgraph.h>
#include <asg/graph/abstractnode.h>
#include <asg/graph/abstractedge.h>

namespace asg {
namespace Graph {

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
        buf.push_back("\t" + n->toString());
    }

    for (auto e : m_g->edges()) {
        buf.push_back("\t" + e->toString());
    }

    return buf;
}

}
}
