/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "begin.h"

namespace asg {
namespace sql {

string begin::default_text { "begin" };

begin::begin(const string &txt)
    : transaction_statement(txt)
{
}

}
}
