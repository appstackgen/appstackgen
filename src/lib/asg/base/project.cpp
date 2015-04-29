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
    : AbstractNode(), m_name(name), m_description(description)
{

}

}
}