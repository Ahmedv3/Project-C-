#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "player1.h"
#include "player2.h"
using namespace std;
using namespace sf;

template <class T1, class T2 > bool isIntersecting(T1& a, T2& b)
{
  return a.right() >= b.left() && a.left() <= b.right() && a.bottom() >= b.top() && a.top() <= b.bottom();
}
bool collisionTest(player1& p1,Ball& ball)
{
  if(!isIntersecting(p1,ball)) return false;
  ball.moveUp();
  if(ball.getPosition().x < p1.getPosition().x)
  {
    ball.moveLeft();
  }
  else if(ball.getPosition().x > p1.getPosition().x)
  {
    ball.moveRight();
  }

}

bool collisionTest2(player2& p2,Ball& ball)
{
  if(!isIntersecting(p2,ball)) return false;
  //ball.moveUp();
  if(ball.getPosition().x < p2.getPosition().x)
  {
    ball.moveLeft();
  }
  else if(ball.getPosition().x > p2.getPosition().x)
  {
    ball.moveRight();
  }

}


int main()
{
    player1 p1(150,360);
    player2 p2(1130,360);
    Ball ball(640,360);
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ping-PongSUTE");
    window.setFramerateLimit(60);
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
        p1.update();
        p2.update();
        collisionTest(p1,ball);
        collisionTest2(p2,ball);
        window.draw(p1);
        window.draw(p2);
        window.draw(ball);
        window.display();
    }
    return 0;
}
