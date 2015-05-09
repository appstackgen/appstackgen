/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/abstractgraphfragment.h>

namespace asg {
namespace graph {

class GraphFragment : public AbstractGraphFragment
{
public:
    GraphFragment(abstract_graph* g, const object_id& id);

protected:
    abstract_graph *impl_graph() const override { return m_g; }
    const object_id impl_id() const override { return m_id; }

private:
    abstract_graph* m_g { nullptr };
    object_id m_id;
};

}
}
