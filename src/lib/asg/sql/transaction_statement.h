/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/sql/statement.h>

namespace asg {
namespace sql {

class transaction_statement : public statement
{
public:
    using statement::statement;
};

}
}
