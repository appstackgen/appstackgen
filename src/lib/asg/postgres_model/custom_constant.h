/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#ifndef ASG_POSTGRES_MODEL_CUSTOM_CONSTANT_H
#define ASG_POSTGRES_MODEL_CUSTOM_CONSTANT_H


namespace asg {
namespace postgres_model {

class custom_constant : public relational_model::constant
{
public:
    custom_constant();
};

} // namespace postgres_model
} // namespace asg

#endif // ASG_POSTGRES_MODEL_CUSTOM_CONSTANT_H
