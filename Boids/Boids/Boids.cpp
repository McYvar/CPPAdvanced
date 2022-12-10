#include "Program.h"

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(2560, 1440), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Program p = Program(&window);
    
    while (window.isOpen())
    {
        Time::UpdateTimer();
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        p.Update();
        window.display();
    }

    return 0;
}