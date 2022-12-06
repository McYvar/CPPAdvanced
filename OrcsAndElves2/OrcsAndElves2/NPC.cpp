#include "NPC.h"

#include <iostream>
#include <valarray>

NPC::NPC(std::string newName)
{
    name = newName;
}

NPC::~NPC()
{
}

NPC::NPC(const NPC& other)
{
    name = other.name;
}

NPC& NPC::operator=(const NPC& other)
{
    this->name = other.name;
    return *this;
}

void NPC::Render()
{
    std::cout << "They have no roles." << std::endl;
}

std::string NPC::GetName()
{
    return name;
}

void NPC::AssignRoles(std::vector<Role> newRoles)
{
    roles = newRoles;
}

std::vector<Role> NPC::GetCurrentRoles()
{
    return roles;
}
