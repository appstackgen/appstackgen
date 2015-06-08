/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "script.h"

#include <asg/sql/begin.h>

namespace asg {
namespace sql {

script::script()
{
}

begin_sptr script::begin()
{
    return create_statement<sql::begin>(begin::default_text);
}

string_vec script::sql(bool with_pre_comments, bool with_post_comments) const
{
    string_vec buf;

    for (auto c : statements()) {
        buf.push_back(c->to_string(with_pre_comments, with_post_comments));
    }

    return buf;
}

}
}
