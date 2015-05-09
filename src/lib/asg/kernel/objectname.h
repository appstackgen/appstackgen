/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <string>

namespace asg {

class object_name
{
public:
    object_name();
    virtual ~object_name();
    explicit object_name(const std::string& n);

    std::string toString() const { return m_str; }

    bool operator ==(const object_name& o) const { return (m_str == o.m_str); }
    bool operator !=(const object_name& o) const { return (m_str != o.m_str); }

    void printOn(std::ostream& strm) const { strm << toString(); }

    bool isEmpty() const { return (m_str.empty()); }

private:
    std::string m_str;
};

std::ostream &operator<<(std::ostream& strm, const asg::object_name& n);

}

