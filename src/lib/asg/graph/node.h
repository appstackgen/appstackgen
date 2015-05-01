/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/abstractnode.h>

namespace ASG {
namespace Graph {

class Node : public AbstractNode
{
public:
    Node(AbstractGraph* g, const Name& name, const Uuid& uuid);

protected:

private:
    Name m_name;
};

}
}
