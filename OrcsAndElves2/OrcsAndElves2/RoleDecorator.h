#pragma once
#include "Decorator.h"
#include "Elve.h"
#include "Orc.h"

class RoleDecorator : public Decorator
{
public:
    RoleDecorator(NPC* n, Role newRole);
    virtual ~RoleDecorator();

    void Render() override;
};
