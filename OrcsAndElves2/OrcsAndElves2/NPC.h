#pragma once
#include <string>
#include <vector>

enum Role { Farmer = 0, Soldier = 1, Shaman = 2 };

class NPC
{
public:
    NPC(std::string newName);
    virtual ~NPC();
    NPC(const NPC& other);
    NPC& operator=(const NPC& other);

    virtual void Render() = 0;
    std::string GetName();

    void AssignRoles(std::vector<Role> newRoles);
    std::vector<Role> GetCurrentRoles();
    
protected:
    std::string name;
    std::vector<Role> roles;
};
