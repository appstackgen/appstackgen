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
namespace sql {

class statement
{
public:
    explicit statement(const string& txt="");

    string text() const { return m_txt; }

    void set_text(const string& txt) { m_txt = txt; }

    bool has_text() const { return (!m_txt.empty()); }

    void prepend_comment(const string& txt) { m_pre_comments.push_back(txt); }
    void append_comment(const string& txt) { m_post_comments.push_back(txt); }

    string_vec pre_comments() const { return m_pre_comments; }
    string_vec post_comments() const { return m_post_comments; }

    string to_string(bool with_pre_comments=false, bool with_post_comments=false) const;

private:
    string m_txt;
    string_vec m_pre_comments;
    string_vec m_post_comments;
};

}
}
