/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "commit.h"

namespace asg {
namespace sql {

string commit::default_text { "commit" };

commit::commit(const string &txt)
    : transaction_statement(txt)
{
}

}
}
