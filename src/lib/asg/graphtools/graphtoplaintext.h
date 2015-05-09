/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/types.h>

namespace ASG {
namespace Graph {

class AbstractGraph;
using AbstractGraphSPtr = std::shared_ptr<AbstractGraph>;

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
