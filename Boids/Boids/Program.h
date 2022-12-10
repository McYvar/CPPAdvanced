#pragma once

#include "Flock.h"

class Program
{
public:
    Program(sf::RenderWindow *window);
    virtual ~Program();
    void Update();

private:
    sf::RenderWindow* window;

    Flock f1;
    Flock f2;
    Flock f3;
    Flock f4;
};

