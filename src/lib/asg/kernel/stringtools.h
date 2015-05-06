/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <boost/algorithm/string/join.hpp>

namespace ASG {

std::string join(const std::vector<std::string>& data, const std::string& sep = "\n");

}
