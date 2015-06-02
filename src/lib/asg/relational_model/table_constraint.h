/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/table_fragment.h>

namespace asg {
namespace relational_model {

class table_column;

using table_column_sptr = std::shared_ptr<table_column>;

using table_column_sptr_vec = std::vector<table_column_sptr>;

class table_constraint : public table_fragment
{
public:
    using table_fragment::table_fragment;

    void append(table_column_sptr c);

    table_column_sptr_vec columns() const;
};

}
}
