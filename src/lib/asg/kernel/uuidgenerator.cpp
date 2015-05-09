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

namespace asg {

object_id uuid_generator::createUuid()
{
    return object_id::create_id();
}

object_id uuid_generator::createInvalidUuid()
{
    return object_id();
}

uuid_generator::uuid_generator()
{

}

}
