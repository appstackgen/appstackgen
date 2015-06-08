/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "rollback.h"

namespace asg {
namespace sql {

string rollback::default_text { "rollback" };

rollback::rollback(const string &txt)
    : transaction_statement(txt)
{
}

}
}
