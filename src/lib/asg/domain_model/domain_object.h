/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/domain_model/domain_fragment.h>

namespace asg {
namespace domain_model {

class id_value;

using id_value_sptr = std::shared_ptr<id_value>;

class domain_object : public domain_fragment
{
public:
    static string static_node_type_name;

    using domain_fragment::domain_fragment;

    template<typename T>
    std::shared_ptr<T> create_value(const std::string& name) {
        return create_sub_node<T>(name);
    }

    template<typename T=id_value>
    std::shared_ptr<T> id_value() const {
        return unique_sub_node<T>();
    }

    bool has_id_value() const;

    id_value_sptr id_value() const;

protected:
    string impl_node_type_name() const override { return static_node_type_name; }
};

}
}
