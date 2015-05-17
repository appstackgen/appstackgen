/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/relational_model/model_fragment.h>

namespace asg {
namespace relational_model {

class schema : public model_fragment
{
public:
    static string static_node_type_name;

    using model_fragment::model_fragment;

    template<typename T>
    std::shared_ptr<T> create_schema_fragment(const string& name) {
        return create_sub_node<T>(name);
    }

    template<typename T>
    std::vector<std::shared_ptr<T>> schema_fragments() const {
        return sub_nodes<T>();
    }

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
