/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "object_name.h"

namespace asg {

object_name::object_name(const std::string &str)
    : m_str(str)
{
}

object_name::object_name()
{
}

object_name::~object_name()
{
}

std::ostream& operator<<(std::ostream &strm, const asg::object_name &n)
{
    n.print_on(strm);
    return strm;
}

}

