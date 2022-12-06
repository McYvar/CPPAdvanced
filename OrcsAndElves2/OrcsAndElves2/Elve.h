#pragma once
#include "NPC.h"

class Elve : public NPC
{
public:
    Elve(std::string name);
    virtual ~Elve();
    Elve(const Elve& other);
    Elve& operator=(const Elve& other);

    void Render() override;
    
};
