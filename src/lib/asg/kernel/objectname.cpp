/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "objectname.h"

namespace asg {

object_name::object_name()
{
}

object_name::~object_name()
{
}

object_name::object_name(const std::string &n)
    : m_str(n)
{
}

std::ostream& operator<<(std::ostream &strm, const asg::object_name &n)
{
    n.printOn(strm);
    return strm;
}

}

