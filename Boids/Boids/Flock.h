#pragma once
#include <SFML/Graphics.hpp>
#include "Boid.h"

class Flock
{
public:
    Flock();
    Flock(sf::RenderWindow* window, int amount, float speed);
    virtual ~Flock();

    void Update();
    
    sf::Vector2f FindCOM() const;
    sf::Vector2f ExcludeSelfFromCOM(sf::Vector2f com, sf::Vector2f myPosition) const;
    sf::Vector2f DisplacementIfCloseOrOutOfRange(sf::Vector2f myPosition) const;
    sf::Vector2f MatchVelocity(sf::Vector2f myVelocity, float amplifier) const;
    sf::Vector2f LimitSpeed(sf::Vector2f& myVelocity) const;

    float Distance(const sf::Vector2f& a, const sf::Vector2f& b) const;
    sf::Vector2f Normalize(const sf::Vector2f& source) const;
    float Magnitude(const sf::Vector2f& a) const;

private:
    sf::RenderWindow* window;
    float speed;
    float maxSpeed;
    std::vector<Boid> boids;
    int boidAmount;
    float maxRangeToOtherBoids;
    sf::Vector2f centre;
    float borderRange;
    bool useBorder;
    float matchVelocityAmplifier;
    int nextPositionReductor;
    float pullTowardsCentre;
};
