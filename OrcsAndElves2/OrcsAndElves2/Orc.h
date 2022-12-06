#pragma once
#include "NPC.h"

class Orc : public NPC
{
public:
    Orc(std::string name);
    virtual ~Orc();
    Orc(const Orc& other);
    Orc& operator=(const Orc& other);

    void Render() override;
    
};
