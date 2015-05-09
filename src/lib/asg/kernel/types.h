/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2014, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <string>
#include <sstream>
#include <memory>
#include <map>
#include <cassert>

#include "objectname.h"
#include "objectid.h"

namespace ASG {
    using size = std::size_t;

    using string = std::string;
    using name = ObjectName;
    using Description = string;

    using StringStream = std::stringstream;
    using StringVector = std::vector<string>;

    using Id = ObjectId;
}
