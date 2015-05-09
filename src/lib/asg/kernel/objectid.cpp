/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "objectid.h"

#include <string>
#include <sstream>

namespace asg {

object_id::object_id()
    : m_id(boost::uuids::nil_uuid())
{   
}

object_id::~object_id()
{
}

std::string object_id::to_string() const
{
    std::stringstream s;
    s << m_id;

    return s.str();
}

object_id object_id::create_id()
{
    return boost::uuids::random_generator()();
}

void object_id::print_on(std::ostream &strm) const
{
    strm << m_id;
}

object_id::object_id(boost::uuids::uuid uuid)
    : m_id(uuid)
{

}

std::ostream &operator<<(std::ostream &strm, const object_id &id)
{
    id.print_on(strm);
    return strm;
}

}
