/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */



#include <asg/kernel/stringtools.h>

std::string ASG::join(const std::vector<std::string> &data, const std::string &sep)
{
    return boost::algorithm::join(data, sep);
}
