#include "Program.h"

#include <iostream>

Program::Program(sf::RenderWindow *window)
{
    this->window = window;
    f1 = Flock(window, 100, 1);
    f2 = Flock(window, 500, 0.6f);
    f3 = Flock(window, 50, 10);
    f4 = Flock(window, 200, 3);
}

Program::~Program()
=default;

void Program::Update()
{
    f1.Update();
    f2.Update();
    f3.Update();
    f4.Update();
}


