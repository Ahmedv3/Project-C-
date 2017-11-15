#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
using namespace std;
using namespace sf;


int main()
{
    Ball ball(400,300);
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ping-PongSUTE");
    window.setFramerateLimit(60);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
          if (event.type == sf::Event::Closed)
            {
              window.close();
              break;
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
              {
                window.close();
                break;
              }
        }

        window.clear(Color::Black);
        ball.update();
        window.draw(ball);
        window.display();
    }
    return 0;
}
