#include "Boid.h"

Boid::Boid(int x, int y, int dx, int dy)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	rect.setPosition(x, y);
	rect.setSize(sf::Vector2f(dx, dy));
}

void Boid::DrawBoid(sf::RenderWindow &window)
{
	window.draw(rect);
}
