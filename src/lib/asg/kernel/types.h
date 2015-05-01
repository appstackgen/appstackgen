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

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace ASG {
    using Size = std::size_t;

    using String = std::string;
    using Name = String;
    using Description = String;

    using StringStream = std::stringstream;

    using Uuid = boost::uuids::uuid;
}
