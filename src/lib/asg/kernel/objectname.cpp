/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "objectname.h"

namespace ASG {

ObjectName::ObjectName()
{
}

ObjectName::~ObjectName()
{
}

ObjectName::ObjectName(const std::string &n)
    : m_str(n)
{
}

std::ostream& operator<<(std::ostream &strm, const ASG::ObjectName &n)
{
    n.printOn(strm);
    return strm;
}

}
