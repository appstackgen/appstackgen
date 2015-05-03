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
    GraphFragment(AbstractGraph* g, const Id& uuid);

protected:
    AbstractGraph *implGraph() const override { return m_g; }
    Id implUuid() const override { return m_uuid; }

private:
    AbstractGraph* m_g { nullptr };
    Id m_uuid;
};

}
}
