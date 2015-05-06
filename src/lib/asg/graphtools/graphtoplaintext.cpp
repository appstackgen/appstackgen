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

namespace ASG {
namespace Graph {

StringVector GraphToPlainText::toStringVector(AbstractGraphSPtr g)
{
    GraphToPlainText i(g);

    return i.graphToStringVector();
}

GraphToPlainText::GraphToPlainText(AbstractGraphSPtr g)
    : m_g(g)
{

}

StringVector GraphToPlainText::graphToStringVector() const
{
    StringVector buf;

    buf.push_back(String("Graph: ") + m_g->title().toString());

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
