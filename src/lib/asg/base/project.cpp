/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "project.h"

namespace ASG {
namespace Base {

Project::Project(const Name &name, const Description &description)
    : m_name(name), m_description(description)
{

}

Name Project::name() const
{
    return m_name;
}

void Project::setName(const Name &name)
{
    m_name = name;
}

Description Project::description() const
{
    return m_description;
}

void Project::setDescription(const Description &description)
{
    m_description = description;
}

}
}
