/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/sql/transaction_statement.h>

namespace asg {
namespace sql {

class commit : public transaction_statement
{
public:
    static string default_text;

    explicit commit(const string& txt = commit::default_text);
};

}
}
