/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/types.h>

namespace asg {
namespace graph {

class abstract_node;

class unknown_sub_node
{
public:
    unknown_sub_node(const string& name="subnodes name not given", const abstract_node* parent_node=nullptr);

public:
    const string what() const;

private:
    string m_msg;
};

}
}
