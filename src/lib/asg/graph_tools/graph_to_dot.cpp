/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "graph_to_dot.h"

#include <asg/graph/abstract_graph.h>
#include <asg/graph/user_node.h>
#include <asg/graph/index_node.h>
#include <asg/graph/index_edge.h>

#include <asg/kernel/object_name.h>

namespace asg {
namespace graph {
namespace tools {

string_vec graph_to_dot::to_string_vector(abstract_graph_sptr g, bool skip_index_node)
{
    return graph_to_dot(g).graph_to_string_vector(skip_index_node);
}

graph_to_dot::graph_to_dot(abstract_graph_sptr g)
    : m_g(g)
{
}

void graph_to_dot::format_nodes(string_vec& buf, bool skip_index_node) const
{
    for (auto n : m_g->nodes()) {
        if (skip_index_node) {
            if (index_node::static_node_type_name != n->node_type_name()) {
                buf.push_back("\t" + format(n) + ";");
            }
        } else {
            buf.push_back("\t" + format(n) + ";");
        }

    }
}

void graph_to_dot::format_edges(string_vec& buf, bool skip_index_node) const
{
    for (auto e : m_g->edges()) {
        if (skip_index_node) {
            if (index_node::static_node_type_name != e->start()->node_type_name()) {
                buf.push_back("\t" + format(e) + ";");
            }
        } else {
            buf.push_back("\t" + format(e) + ";");
        }
    }
}

string_vec graph_to_dot::graph_to_string_vector(bool skip_index_node) const
{
    string_vec buf;

    buf.push_back("digraph " + quote(m_g->title()) + " {");

    format_nodes(buf, skip_index_node);
    format_edges(buf, skip_index_node);

    buf.push_back("}");

    return buf;
}

string graph_to_dot::format(abstract_node_sptr n) const
{
    stringstream s;
    s << quote(n->id()) << " [label=" << quote(n->node_type_name() + "\\n" + n->name().to_string()) << " shape=box]";
    return s.str();
}

string graph_to_dot::format(abstract_edge_sptr e) const
{
    stringstream s;
    s << quote(e->start()->id()) << " -> " << quote(e->end()->id()) << " [shape=solid label=" << quote(e->edge_type_name()) << "]";
    return s.str();
}

string graph_to_dot::quote(const object_id &id) const
{
    return quote(id.to_string());
}

string graph_to_dot::quote(const object_name &n) const
{
    return quote(n.to_string());
}

string graph_to_dot::quote(const string &n) const
{
    stringstream s;
    s << "\"" << n << "\"";
    return s.str();
}

}
}
}
