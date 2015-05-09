/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <asg/kernel/types.h>

namespace asg {

class uuid_generator
{
public:
    uuid_generator();

    static ObjectId createUuid();
    static ObjectId createInvalidUuid();
};

}
