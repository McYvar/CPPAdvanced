#include "Boid.h"
#include "Time.h"

Boid::Boid()
{
	window = nullptr;
	position = sf::Vector2f(0, 0);
}

Boid::Boid(sf::RenderWindow *window)
{
	this->window = window;
	position = sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y / 2.0f);
	this->shape.setPosition(position);
	this->shape.setRadius(3);
}

void Boid::DrawBoid()
{
	shape.setPosition(position);
	window->draw(shape);
}

