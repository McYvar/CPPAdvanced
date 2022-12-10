#include "Program.h"

#include <iostream>

Program::Program(sf::RenderWindow *window)
{
    // variables to play with
    boidAmount = 1000;
    speed = 2;
    maxSpeed = 100;
    borderRange = 700;
    useBorder = true;
    maxRangeToOtherBoids = 1;
    matchVelocityAmplifier = 3;
    centre = sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2);
    nextPositionReductor = 100;
    
    this->window = window;

    for (int i = 0; i < boidAmount; i++)
    {
        boids.emplace_back(window);
    }

    for (auto& boid : boids)
    {
        boid.position = sf::Vector2f(rand() % window->getSize().x, rand() % window->getSize().y);
    }
}

Program::~Program()
=default;

void Program::Update()
{
    const sf::Vector2f com = FindCOM();
    
    for (auto& boid : boids)
    {
        sf::Vector2f v1 = ExcludeSelfFromCOM(com, boid.position);
        v1 = sf::Vector2f(v1.x / nextPositionReductor, v1.y / nextPositionReductor);
        sf::Vector2f v2 = DisplacementIfCloseOrOutOfRange(boid.position);
        sf::Vector2f v3 = MatchVelocity(boid.velocity, matchVelocityAmplifier);

        boid.velocity += v1 + v2 + v3;
        boid.velocity = LimitSpeed(boid.velocity);

        const sf::Vector2f nextPos = boid.position + boid.velocity * speed * Time::deltaTime;
        boid.position = nextPos;
        
        boid.DrawBoid();
    }
}

sf::Vector2f Program::FindCOM() const
{
    sf::Vector2f com;
    for (const auto& boid : boids)
    {
        com += boid.position;
    }
    return com;
}

sf::Vector2f Program::ExcludeSelfFromCOM(sf::Vector2f com, sf::Vector2f myPosition) const
{
    return {(com.x - myPosition.x) / (boids.size() - 1) - myPosition.x, (com.y - myPosition.y) / (boids.size() - 1) - myPosition.y
    };
}

sf::Vector2f Program::DisplacementIfCloseOrOutOfRange(sf::Vector2f myPosition) const
{
    if (useBorder)
    {
        const float rangeToCentre = Distance(myPosition, centre);
        if (rangeToCentre >= borderRange)
        {
            const float rangeOutsideBorderRange = rangeToCentre - borderRange;
            return Normalize(centre - myPosition) * rangeOutsideBorderRange;
        }
    }

    sf::Vector2f displacement;
    for (auto& boid : boids)
    {
        if (boid.position != myPosition)
        {
            float dist = (Distance(boid.position, myPosition));
            if (dist < maxRangeToOtherBoids)
            {
                displacement += myPosition - boid.position;
                if (dist > 1)
                    displacement *= 1 / dist;
                else
                {
                    displacement *= dist;
                }
            }
        }
    }
    
    return displacement;
}

sf::Vector2f Program::MatchVelocity(sf::Vector2f myVelocity, float amplifier) const
{
    sf::Vector2f velocity;
    for (const auto& boid : boids)
    {
        if (boid.velocity != myVelocity)
        {
            velocity += boid.velocity;
        }
    }
    velocity = sf::Vector2f(velocity.x / (boidAmount - 1), velocity.y / (boidAmount - 1));
    velocity *= amplifier;
    return velocity;
}

sf::Vector2f Program::LimitSpeed(sf::Vector2f& myVelocity) const
{
    if (Magnitude(myVelocity) > maxSpeed)
    {
        myVelocity = Normalize(myVelocity) * maxSpeed;
    }
    return myVelocity;
}

float Program::Distance(const sf::Vector2f& a, const sf::Vector2f& b) const
{
    return std::sqrt((
        ((b.x - a.x) * (b.x - a.x))
        + ((b.y - a.y) * (b.y - a.y))
        ));
}

sf::Vector2f Program::Normalize(const sf::Vector2f& source) const
{
    const float length = sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0)
        return {source.x / length, source.y / length};
    else
        return source;
}

float Program::Magnitude(const sf::Vector2f& a) const
{
    return std::sqrt((a.x * a.x) + (a.y * a.y));
}



