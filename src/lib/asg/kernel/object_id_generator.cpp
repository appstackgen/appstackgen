/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "object_id_generator.h"

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/nil_generator.hpp>

namespace asg {

object_id object_id_generator::create_id()
{
    return object_id::create_id();
}

object_id object_id_generator::create_invalid_id()
{
    return object_id();
}

object_id_generator::object_id_generator()
{

}

}
