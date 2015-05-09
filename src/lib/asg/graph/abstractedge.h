/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/graphfragment.h>

#include <asg/graph/abstractnode.h>

namespace asg {
namespace graph {

class abstract_edge;
class abstract_node;

using abstract_edge_sptr = std::shared_ptr<abstract_edge>;
using abstract_node_sptr = std::shared_ptr<abstract_node>;

class abstract_edge : public GraphFragment
{
public:
    using GraphFragment::GraphFragment;

    void set_start(abstract_node_sptr s) { impl_set_start(s); }
    void set_end(abstract_node_sptr e) { impl_set_end(e); }

    template<typename T=abstract_node>
    std::shared_ptr<T> start() const { return std::dynamic_pointer_cast<T>(impl_start()); }

    template<typename T=abstract_node>
    std::shared_ptr<T> end() const { return std::dynamic_pointer_cast<T>(impl_end()); }

    bool has_start() const { return (abstract_node_sptr() != start()); }
    bool has_end() const { return (abstract_node_sptr() != end()); }

    string edge_type_name() const { return impl_edge_type_name(); }

protected:
    virtual void impl_set_start(abstract_node_sptr s) = 0;
    virtual void impl_set_end(abstract_node_sptr e) = 0;

    virtual abstract_node_sptr impl_start() const = 0;
    virtual abstract_node_sptr impl_end() const = 0;

    virtual string impl_edge_type_name() const = 0;

    string impl_to_string() const override;
};

}
}
