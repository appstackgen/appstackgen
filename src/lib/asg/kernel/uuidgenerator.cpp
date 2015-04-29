/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "uuidgenerator.h"

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/nil_generator.hpp>

namespace ASG {

Uuid UuidGenerator::createUuid()
{
    return boost::uuids::random_generator()();
}

Uuid UuidGenerator::createInvalidUuid()
{
    return boost::uuids::nil_generator()();
}

UuidGenerator::UuidGenerator()
{

}

}
