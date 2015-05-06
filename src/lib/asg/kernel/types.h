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
    using Size = std::size_t;

    using String = std::string;
    using Name = ObjectName;
    using Description = String;

    using StringStream = std::stringstream;
    using StringVector = std::vector<String>;

    using Id = ObjectId;
}
