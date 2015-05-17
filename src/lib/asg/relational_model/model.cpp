/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "model.h"

#include <asg/relational_model/iso_data_type.h>

namespace asg {
namespace relational_model {

string model::static_node_type_name { "relational model" };

string model::boolean_type_name { "boolean" };
string model::integer_type_name { "integer" };
string model::bigint_type_name { "bigint" };
string model::numeric_type_name { "numeric" };
string model::char_type_name { "char" };
string model::varchar_type_name { "varchar" };
string model::date_type_name { "date" };
string model::time_type_name { "time" };
string model::timestamp_type_name { "timestamp" };

string model::current_date_constant_name { "current_timestamp" };

string_vec model::iso_data_type_names { boolean_type_name,
            integer_type_name,
            bigint_type_name,
            numeric_type_name,
            char_type_name,
            varchar_type_name,
            date_type_name,
            time_type_name,
            timestamp_type_name };

string_vec model::iso_constant_names { current_date_constant_name };

}
}
