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
    static Uuid createUuid();
    static Uuid createInvalidUuid();

protected:
    UuidGenerator();
};

}
