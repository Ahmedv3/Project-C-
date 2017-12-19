#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "player1.h"
#include "player2.h"
#include "menu.h"

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

int check_points(Ball& ball, int& p1_pkt, Text& punkt1)
{
  if(ball.getPosition().x < 15)
  {
    ball.destroy();
    p1_pkt++;
    std::string _str1 = std::to_string(p1_pkt);
    punkt1.setString(_str1);
  }
  return p1_pkt;
}

int check_points2(Ball& ball,int& p2_pkt,Text& punkt2)
{
  if(ball.getPosition().x > 1265)
    {
      ball.destroy();
      p2_pkt++;
      std::string _str = std::to_string(p2_pkt);
      punkt2.setString(_str);
    }
  return p2_pkt;
}

void endgame(RenderWindow& window,Text& text)
{
  window.close();
  sf::RenderWindow windowEnd(sf::VideoMode(1280, 720), "Ping-PongSUTE_Endgame");
  windowEnd.setFramerateLimit(60);

  while (windowEnd.isOpen())
    {
        sf::Event event;
        while (windowEnd.pollEvent(event))
        {
          if (event.type == sf::Event::Closed)
            {
              windowEnd.close();
              break;
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
              {
                windowEnd.close();
                break;
              }
        }

        windowEnd.clear(Color::Black);
        windowEnd.draw(text);
        windowEnd.display();
    }
}

int main()
{
    auto White = Color::White;  //colors

    int p1_point = 0;
    int p2_point = 0;

    menu menu_test;

    sf::Font font;
    font.loadFromFile("arial.ttf");
    Text points1;
    Text points2;

    Text naglowek;
    naglowek.setFont(font);
    naglowek.setCharacterSize(40);
    naglowek.setColor(White);
    naglowek.setPosition(75,30);
    naglowek.setString("Ping-Pong:SuperUltraTurboExtreme!!!");

    Text koniec;
    koniec.setFont(font);
    koniec.setCharacterSize(40);
    koniec.setColor(White);
    koniec.setPosition(450,30);
    koniec.setString("Koniec gry!");

    Text start;
    start.setFont(font);
    start.setCharacterSize(30);
    start.setColor(White);
    start.setPosition(225,450);
    start.setString("Wcisnij Spacje by zagrac!");

    points1.setFont(font);
    points1.setCharacterSize(30);
    points1.setColor(White);
    points1.setPosition(1255,10);

    points2.setFont(font);
    points2.setCharacterSize(30);
    points2.setColor(White);
    points2.setPosition(10,10);


    player1 p1(150,360);
    player2 p2(1130,360);
    Ball ball(640,360);



    sf::RenderWindow window2(sf::VideoMode(800, 600), "Ping-PongSUTE_Main-Menu");
    window2.setFramerateLimit(60);



    while (window2.isOpen())
    {
        sf::Event event;
        while (window2.pollEvent(event))
        {
          if (event.type == sf::Event::Closed)
            {
              window2.close();
              break;
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
              {
                window2.close();
                break;
              }
            if (Keyboard::isKeyPressed(Keyboard::Key::Space))
              {
                menu_test.start = true;
                break;
              }

        }

        if(menu_test.start == true)
        {
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

                        window2.close();
                        window.clear(Color::Black);
                        ball.update();
                        p1.update();
                        p2.update();
                        collisionTest(p1,ball);
                        collisionTest2(p2,ball);
                        check_points(ball,p1_point,points1);
                        check_points2(ball,p2_point,points2);

                        if(check_points(ball,p1_point,points1)>=2)
                          {
                            endgame(window,koniec);
                            break;
                          }
                        else if(check_points2(ball,p2_point,points2)>=2)
                        {
                          endgame(window,koniec);
                          break;
                        }
                        window.draw(points1);
                        window.draw(points2);
                        window.draw(p1);
                        window.draw(p2);
                        window.draw(ball);
                        window.display();
                }
        }
        else if(menu_test.start == false)
        {
          window2.clear(Color::Black);
          window2.draw(naglowek);
          window2.draw(start);
          window2.display();
        }
    }
    return 0;
}
