#include "Decorator.h"

#include <iostream>

Decorator::Decorator(NPC* n) : NPC(*n)
{
    decoratorNPC = n;
}

Decorator::~Decorator()
{
    delete decoratorNPC;
}

void Decorator::Render()
{
    decoratorNPC->Render();
}
