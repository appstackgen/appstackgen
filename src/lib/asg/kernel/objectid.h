/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <boost/uuid/uuid.hpp>

#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/random_generator.hpp>

namespace asg {

class object_id
{
public:
    object_id();
    virtual ~object_id();

    bool is_valid() const { return (!m_id.is_nil()); }

    std::string to_string() const;

    static object_id create_id();

    bool operator < (const object_id& o) const { return (m_id < o.m_id); }
    bool operator ==(const object_id& o) const { return (m_id == o.m_id); }

    void print_on(std::ostream& strm) const;

protected:
    object_id(boost::uuids::uuid uuid);

private:
    boost::uuids::uuid m_id;
};

std::ostream& operator<<(std::ostream& strm, const object_id& id);

}
