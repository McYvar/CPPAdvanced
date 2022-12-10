#include "Time.h"

Time::Time()
{
    clock = sf::Clock();
    currentTime = clock.getElapsedTime().asSeconds();
    lastFrameTime = 0;
    deltaTime = 0;
}

void Time::UpdateTimer()
{
    lastFrameTime = currentTime;
    currentTime = clock.getElapsedTime().asSeconds();

    deltaTime = currentTime - lastFrameTime;
}

float Time::deltaTime;
float Time::currentTime;
float Time::lastFrameTime;
sf::Clock Time::clock;
