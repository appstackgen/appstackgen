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
class begin;
class commit;
class rollback;

using statement_sptr = std::shared_ptr<statement>;
using begin_sptr = std::shared_ptr<begin>;
using commit_sptr = std::shared_ptr<commit>;
using rollback_sptr = std::shared_ptr<rollback>;

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

    template<typename creator_t, typename obj_t>
    std::shared_ptr<creator_t> create(std::shared_ptr<obj_t> o) {
        auto s = std::make_shared<creator_t>(o);
        m_statements.push_back(s);
        return s;
    }

    rollback_sptr rollback();
    begin_sptr begin();
    commit_sptr commit();

    bool empty() const { return m_statements.empty(); }
    size size() const { return m_statements.size(); }

    statement_sptr_vec statements() const { return m_statements; }
    string_vec sql(bool with_pre_comments=false, bool with_post_comments=false) const;

private:
    statement_sptr_vec m_statements;
};

}
}
