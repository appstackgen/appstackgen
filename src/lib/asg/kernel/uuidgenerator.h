/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <asg/kernel/types.h>

namespace ASG {

class UuidGenerator
{
public:
    UuidGenerator();

    static ObjectId createUuid();
    static ObjectId createInvalidUuid();
};

}
