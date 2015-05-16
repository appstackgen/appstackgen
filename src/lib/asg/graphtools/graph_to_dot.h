/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/types.h>

#include <asg/kernel/object_id.h>

namespace asg {
namespace graph {

class abstract_graph;
class abstract_node;
class abstract_edge;

using abstract_graph_sptr = std::shared_ptr<abstract_graph>;
using abstract_node_sptr = std::shared_ptr<abstract_node>;
using abstract_edge_sptr = std::shared_ptr<abstract_edge>;

class graph_to_dot
{
public:
    static string_vec to_string_vector(abstract_graph_sptr g, bool skip_index_node=true);

    void format_nodes(string_vec &buf, bool skip_index_node) const;
    void format_edges(string_vec &buf, bool skip_index_node) const;
protected:
    graph_to_dot(abstract_graph_sptr g);

    string_vec graph_to_string_vector(bool skip_index_node) const;

private:
    abstract_graph_sptr m_g;

    string format(abstract_node_sptr n) const;
    string format(abstract_edge_sptr e) const;

    string quote(const object_id& id) const;
    string quote(const object_name& n) const;
    string quote(const string& n) const;
};

}
}
