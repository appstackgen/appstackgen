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

namespace ASG {

ObjectId::ObjectId()
    : m_id(boost::uuids::nil_uuid())
{   
}

ObjectId::~ObjectId()
{
}

std::string ObjectId::toString() const
{
    std::stringstream s;
    s << m_id;

    return s.str();
}

ObjectId ObjectId::createId()
{
    return boost::uuids::random_generator()();
}

ObjectId::ObjectId(boost::uuids::uuid uuid)
    : m_id(uuid)
{

}

}
