#include "RoleDecorator.h"

#include <iostream>

RoleDecorator::RoleDecorator(NPC* n, Role newRole) : Decorator(n)
{
    roles = n->GetCurrentRoles();
    roles.push_back(newRole);
    n->AssignRoles(roles);
}

RoleDecorator::~RoleDecorator()
{
}

void RoleDecorator::Render()
{
    if (!roles.empty())
    {
        std::cout << "They have " << roles.size() << " roles:\n";
        for (const auto role : roles)
        {
            switch (role)
            {
            case Farmer:
                std::cout << "Farmer\n";
                break;
            case Soldier:
                std::cout << "Soldier\n";
                break;
            case Shaman:
                std::cout << "Shaman\n";
                break;
            }
        }
        std::cout << std::endl;
        return;
    }
    
    std::cout << "They have no roles." << std::endl;
}
