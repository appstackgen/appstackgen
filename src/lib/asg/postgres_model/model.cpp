/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "model.h"

namespace asg {
namespace postgres_model {

string model::static_node_type_name { "postgres model" };

string model::serial_data_type_name { "serial" };
string model::bigserial_data_type_name { "bigserial" };

string_vec model::custom_data_type_names { serial_data_type_name, bigserial_data_type_name };

}
}
