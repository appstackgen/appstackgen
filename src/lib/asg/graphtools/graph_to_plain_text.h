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

class abstract_graph;
using AbstractGraphSPtr = std::shared_ptr<abstract_graph>;

class GraphToPlainText
{
public:
    static string_vec toStringVector(AbstractGraphSPtr g);

protected:
    GraphToPlainText(AbstractGraphSPtr g);

    string_vec graphToStringVector() const;

private:
    AbstractGraphSPtr m_g;
};

}
}
