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

class statement;

using statement_sptr = std::shared_ptr<statement>;

using statement_sptr_vec = std::vector<statement_sptr>;

class script
{
public:
    script();

    template<typename t>
    std::shared_ptr<t> create_statement(const std::string& text) {
        auto s = std::make_shared<t>(text);
        m_statements.push_back(s);
        return s;
    }

    bool empty() const { return m_statements.empty(); }
    size size() const { return m_statements.size(); }

private:
    statement_sptr_vec m_statements;
};

}
}
