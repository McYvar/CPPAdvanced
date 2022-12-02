#include "Elve.h"

#include <iostream>

Elve::Elve(std::string name) : NPC (name)
{
}

Elve::~Elve()
{
}

Elve::Elve(const Elve& other) : NPC (other)
{
}

Elve& Elve::operator=(const Elve& other)
{
    name = other.name;
    return *this;
}

void Elve::Render()
{
    std::cout << "This Elve is called: " << name << "!" << std::endl;
    NPC::Render();
}
