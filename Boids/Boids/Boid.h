#pragma once

#include <SFML/Graphics.hpp>

class Boid
{
public:
	Boid(int x, int y, int dx, int dy);

	void DrawBoid(sf::RenderWindow &window);

private:
	int x;
	int y;

	int dx;
	int dy;

	sf::RectangleShape rect;
	
};

