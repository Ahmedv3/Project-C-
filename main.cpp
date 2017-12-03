#include <iostream>
#include <string>
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

  if(ball.getPosition().x < p1.getPosition().x)
  {
    ball.moveLeft();
    ball.acceleration();
  }
  else if(ball.getPosition().x > p1.getPosition().x)
  {
    ball.moveRight();
    ball.acceleration();
  }
  return true;
}

bool collisionTest2(player2& p2,Ball& ball)
{
  if(!isIntersecting(p2,ball)) return false;

  if(ball.getPosition().x < p2.getPosition().x)
  {
    ball.moveLeft();
    ball.acceleration();
  }
  else if(ball.getPosition().x > p2.getPosition().x)
  {
    ball.moveRight();
    ball.acceleration();
  }
  return true;
}

void check_points(Ball& ball, int& p1_pkt, int& p2_pkt, Text& punkt1, Text& punkt2)
{
  if(ball.getPosition().x < 15)
  {
    ball.destroy();
    p1_pkt++;
    std::string _str1 = std::to_string(p1_pkt);
    punkt1.setString(_str1);

  }
  else if(ball.getPosition().x > 1265)
  {
    ball.destroy();
    p2_pkt++;
    std::string _str = std::to_string(p2_pkt);
    punkt2.setString(_str);
    
  }
}



int main()
{
    int p1_point = 0;
    int p2_point = 0;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    Text points1;
    Text points2;

    points1.setFont(font);
    points1.setCharacterSize(30);
    points1.setColor(sf::Color::White);
    points1.setPosition(1255,10);
    points2.setFont(font);
    points2.setCharacterSize(30);
    points2.setColor(Color::White);
    points2.setPosition(10,10);


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
        check_points(ball,p1_point,p2_point,points1,points2);
        window.draw(points1);
        window.draw(points2);
        window.draw(p1);
        window.draw(p2);
        window.draw(ball);
        window.display();
    }
    return 0;
}
