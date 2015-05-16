/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "file_tools.h"

#include <asg/kernel/string_tools.h>

#include <fstream>

namespace asg {

void save_to_file(const string_vec &data, const string &fname, const string &sep)
{
    save_to_file(join(data, sep), fname);
}

void save_to_file(const string &data, const string &fname)
{
    std::ofstream f;
    f.open(fname);
    f << data;
    f.close();
}

}
