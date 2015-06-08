/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/sql/create.h>

namespace asg {

namespace relational_model {
class table;
class table_column;

using table_sptr = std::shared_ptr<table>;
using table_column_sptr = std::shared_ptr<table_column>;
}

namespace sql {

class create_table : public create<relational_model::table>
{
public:
    explicit create_table(relational_model::table_sptr t);

private:
    string declare_column(relational_model::table_column_sptr col) const;

};

}
}
