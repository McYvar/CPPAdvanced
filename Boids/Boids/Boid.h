#pragma once

#include <SFML/Graphics.hpp>

class Boid
{
public:
	Boid(const sf::RenderWindow &window);

	void DrawBoid(sf::RenderWindow &window);

	void NewPos(float x, float y);

private:
	float x;
	float y;

	sf::CircleShape shape;
	
};

