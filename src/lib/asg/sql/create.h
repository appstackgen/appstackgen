/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/sql/ddl_statement.h>

namespace asg {
namespace sql {

template<typename t>
class create: public ddl_statement {
public:
    using obj_sptr_t = std::shared_ptr<t>;

    explicit create(obj_sptr_t obj)
        : ddl_statement("not implemented for object type: " + t::static_node_type_name)
        , m_obj(obj) {
    }

private:
    obj_sptr_t m_obj;
};

}
}
