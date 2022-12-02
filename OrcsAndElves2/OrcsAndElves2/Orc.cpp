#include "Orc.h"

#include <iostream>

Orc::Orc(std::string name) : NPC(name)
{
}

Orc::~Orc()
{
}

Orc::Orc(const Orc& other) : NPC(other)
{
}

Orc& Orc::operator=(const Orc& other)
{
    name = other.name;
    return *this;
}

void Orc::Render()
{
    std::cout << "This Orc is called: " << name << "!" << std::endl;
    NPC::Render();
}
