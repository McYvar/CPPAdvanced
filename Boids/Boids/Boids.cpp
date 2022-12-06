#include "Boid.h"

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::RectangleShape rect(sf::Vector2f(100, 100));

    Boid b(300, 300, 200, 200);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw();
        b.DrawBoid(window);
        window.display();
    }

    return 0;
}