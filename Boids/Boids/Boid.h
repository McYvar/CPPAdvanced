#pragma once

#include <SFML/Graphics.hpp>
#include "Time.h"

class Boid
{
public:
	Boid();
	Boid(sf::RenderWindow *window);
	void DrawBoid();
	void NewPos(sf::Vector2f vector2);
	sf::Vector2f position;
	sf::Vector2f velocity;

private:
	sf::CircleShape shape;
	sf::RenderWindow* window;
};