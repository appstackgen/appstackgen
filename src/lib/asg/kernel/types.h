/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2014, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <string>
#include <memory>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace ASG {
    using String = std::string;
    using Name = String;
    using Description = String;

    using Uuid = boost::uuids::uuid;
}
