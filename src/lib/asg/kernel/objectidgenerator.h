/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <asg/kernel/types.h>

namespace asg {

class object_id_generator
{
public:
    object_id_generator();

    static object_id create_id();
    static object_id create_invalid_id();
};

}
