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

ObjectId UuidGenerator::createUuid()
{
    return ObjectId::createId();
}

ObjectId UuidGenerator::createInvalidUuid()
{
    return ObjectId();
}

UuidGenerator::UuidGenerator()
{

}

}
