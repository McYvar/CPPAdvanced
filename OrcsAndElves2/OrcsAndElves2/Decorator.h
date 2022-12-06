#pragma once
#include "NPC.h"

class Decorator : public NPC
{
public:
    Decorator(NPC* n);
    virtual ~Decorator();

    void Render();

private:
    NPC* decoratorNPC;
};
