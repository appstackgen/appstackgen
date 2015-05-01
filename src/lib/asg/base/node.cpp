/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include "node.h"

namespace ASG {
namespace Base {

Node::Node(const ASG::Name &name, const ASG::Description &description)
    : m_uuid(UuidGenerator::createUuid()), m_name(name), m_description(description)
{

}

}
}
