#pragma once
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class Time
{
public:
    static void UpdateTimer();
    static float deltaTime;
    static float currentTime;

private:
    static sf::Clock clock;
    static float lastFrameTime;
    Time();
};
