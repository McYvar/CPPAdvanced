#include "Boid.h"
#include <stdlib.h>

Boid::Boid(const sf::RenderWindow &window)
{
	this->x = window.getSize().x / 2.0f;
	this->y = window.getSize().y / 2.0f;
	shape.setPosition(x, y);
	shape.setRadius(10);
}

void Boid::DrawBoid(sf::RenderWindow &window)
{
	shape.setPosition(x, y);
	window.draw(shape);
}

void Boid::NewPos(float x, float y)
{
	this->x = x;
	this->y = y;
}

