/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/types.h>

namespace asg {

    void save_to_file(const string_vec& data, const string& fname, const string& sep = "\n");
    void save_to_file(const string& data, const string& fname);

}
