/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */


#include <asg/kernel/string_tools.h>

std::string asg::join(const std::vector<std::string> &data, const std::string &sep)
{
    return boost::algorithm::join(data, sep);
}
