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
    statement(const string& txt="");

    string text() const { return m_txt; }

    void set_text(const string& txt) { m_txt = txt; }

    bool has_text() const { return (!m_txt.empty()); }

private:
    string m_txt;
};

}
}
