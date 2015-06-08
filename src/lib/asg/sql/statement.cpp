/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "statement.h"

#include <asg/kernel/string_tools.h>

namespace asg {
namespace sql {

statement::statement(const string &txt)
    : m_txt(txt)
{   
}

string statement::to_string(bool with_pre_comments, bool with_post_comments) const
{
    string_vec buf;

    if (with_pre_comments) {
        for (auto c : pre_comments()) {
            buf.push_back("-- " + c);
        }
    }

    buf.push_back(text() + ";");

    if (with_post_comments) {
        for (auto c : post_comments()) {
            buf.push_back("-- " + c);
        }
    }

    return join(buf, "\n");
}

}
}
