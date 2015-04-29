/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/kernel/types.h>

namespace ASG {
namespace Base {

class Project
{
public:
    explicit Project(const Name& name = "", const Description& description = "");
    virtual ~Project() {}

    Name name() const;
    Description description() const;

    void setName(const Name &name);
    void setDescription(const Description &description);

    bool hasName() const { return (!name().empty()); }
    bool hasDescription() const { return (!description().empty());  }

private:
    Name m_name { "" };
    Description m_description { "" };
};

}
}
