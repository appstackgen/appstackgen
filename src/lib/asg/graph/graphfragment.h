/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/abstractgraphfragment.h>

namespace ASG {
namespace Graph {

class GraphFragment : public AbstractGraphFragment
{
public:
    GraphFragment(AbstractGraph* g, const ObjectId& id);

protected:
    AbstractGraph *implGraph() const override { return m_g; }
    const ObjectId implId() const override { return m_id; }

private:
    AbstractGraph* m_g { nullptr };
    ObjectId m_id;
};

}
}
