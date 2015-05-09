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

class ObjectId
{
public:
    ObjectId();
    virtual ~ObjectId();

    bool isValid() const { return (!m_id.is_nil()); }

    std::string toString() const;

    static ObjectId createId();

    bool operator < (const ObjectId& o) const { return (m_id < o.m_id); }
    bool operator ==(const ObjectId& o) const { return (m_id == o.m_id); }

    void printOn(std::ostream& strm) const;

protected:
    ObjectId(boost::uuids::uuid uuid);

private:
    boost::uuids::uuid m_id;
};

std::ostream& operator<<(std::ostream& strm, const ObjectId& id);

}
