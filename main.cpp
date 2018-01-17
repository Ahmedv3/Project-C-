#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Ball.h"
#include "player1.h"
#include "player2.h"
#include "menu.h"
#include "bonus.h"
#include <ctime>

using namespace std;
using namespace sf;

template <class T1, class T2 > bool isIntersecting(T1& a, T2& b)
{
  return a.right() >= b.left() && a.left() <= b.right() && a.bottom() >= b.top() && a.top() <= b.bottom();
}
////////////////
template <class T1, class T2 > bool isIntersecting2(T1& a, T2* b)
{
  return a.right() >= b->left() && a.left() <= b->right() && a.bottom() >= b->top() && a.top() <= b->bottom();
}
//////////////////
bool collisionTest_bonus(player1& p1,bonus* b1)
{
  if(!isIntersecting2(p1,b1)) return false;

  if(b1->getPosition().x < p1.getPosition().x)
  {
    b1->moveLeft();
  }
  else if(b1 ->getPosition().x > p1.getPosition().x)
  {
    b1->moveRight();
  }
  return true;
}
//////////////////
bool collisionTest_bonus2(player2& p2,bonus* b1)
{
  if(!isIntersecting2(p2,b1)) return false;

  if(b1 ->getPosition().x < p2.getPosition().x)
  {
    b1 ->moveLeft();
  }
  else if(b1->getPosition().x > p2.getPosition().x)
  {
    b1->moveRight();
  }
  return true;
}
//////////////////
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
////////////
int check_points_bonus(int& p1_pkt, Text& punkt1,bonus* b1)
{
  if(b1->getPosition().x < 15)
  {
    p1_pkt++;
    std::string _str1 = std::to_string(p1_pkt);
    punkt1.setString(_str1);
  }
  return p1_pkt;
}
int check_points2_bonus(int& p2_pkt,Text& punkt2,bonus* b1)
{
    if(b1->getPosition().x > 1265)
    {
      p2_pkt++;
      std::string _str = std::to_string(p2_pkt);
      punkt2.setString(_str);
    }
  return p2_pkt;
}

void endgame(RenderWindow& window,Text& text,sf::Sprite& endScreen)
{

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
        window.close();
        windowEnd.clear(Color::Black);
        windowEnd.draw(endScreen);
        windowEnd.draw(text);
        windowEnd.display();
    }
}


void addBonus(int& los,RenderWindow& window,bonus *b1,Clock& clock2,Ball& ball,player1& p1,player2& p2,Text& tekst_point1,int& punkt1,Text& tekst_point2,int& punkt2 )
{
  if(los == 1)
  {
      int czas2 = clock2.getElapsedTime().asMilliseconds();
      if(czas2 >= 15000){
        los = 0;
      }
      else {

        b1 -> update();
        window.draw(*b1);
        collisionTest_bonus2(p2,b1);
        collisionTest_bonus(p1,b1);
        check_points2_bonus(punkt2,tekst_point2,b1);
        check_points_bonus(punkt1,tekst_point1,b1);
      }
  }
  else if(los == 2)
  {

      ball.ball_bonus_pos();
      los = 0;
  }

  else if(los == 3)
  {
      int czas2 = clock2.getElapsedTime().asMilliseconds();
      if(czas2 >= 2000){
        ball.ball_bonus_return_color();
        los = 0;
      }
      else{

        ball.ball_bonus_color();
      }

  }
  else if(los < 0){

  }

}

void changePosition(Clock& clock,bool& piewszyRaz,CircleShape& circle,Ball& ball,int& los,Clock& clock2)
{
  int czas = clock.getElapsedTime().asMilliseconds();
  if (czas >= 8000)
    {
      int X =( rand() % 700 ) + 300;
      int Y =( rand() % 500 ) + 100;
      circle.setPosition(X,Y);
      piewszyRaz = true;
    }
    else if(ball.getPosition().y >= circle.getPosition().y && ball.getPosition().y <= circle.getPosition().y+100.0f && ball.getPosition().x >= circle.getPosition().x && ball.getPosition().x <= circle.getPosition().x+100.0f )
    {
      int X =( rand() % 700 ) + 300;
      int Y =( rand() % 500 ) + 100;
      circle.setPosition(X,Y);
      los = ( rand()% 3 ) + 1;
      clock2.restart();
      piewszyRaz = true;
    }
}

int main()
{
    srand( time( NULL ) );

    auto White = Color::White;  //colors
    int los;
    int p1_point = 0;
    int p2_point = 0;
    int X =( rand() % 700 ) + 300;
    int Y =( rand() % 500 ) + 100;

    CircleShape circle;
    circle.setRadius(50.0f);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(X,Y);

    bonus* b1 = new bonus;

    bool pierwszyRaz = true;
    bool drugiRaz = true;
    sf::Clock clock;
    sf::Clock clock2;
    menu menu_test;

    Texture background;
    background.loadFromFile("ping-pong-menu.png");
    sf::Sprite tlo(background);
    tlo.setPosition(0,0);

    Texture main_board;
    main_board.loadFromFile("main_board.png");
    sf::Sprite plansza(main_board);
    plansza.setPosition(0,0);

    Texture endgame1;
    endgame1.loadFromFile("endgame.png");
    sf::Sprite endScreen(endgame1);
    endScreen.setPosition(0,0);

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
    koniec.setColor(sf::Color::Cyan);
    koniec.setPosition(420,30);

    Text start;
    start.setFont(font);
    start.setCharacterSize(30);
    start.setColor(White);
    start.setPosition(225,450);
    start.setString("Wcisnij Spacje by zagrac!");

    points1.setFont(font);
    points1.setCharacterSize(30);
    points1.setColor(White);
    points1.setPosition(1240,10);

    points2.setFont(font);
    points2.setCharacterSize(30);
    points2.setColor(White);
    points2.setPosition(25,10);


    sf::Music music;
    music.openFromFile("pong_music.ogg");
    music.setVolume(50);
    music.setLoop(true);
    music.play();




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
                        window.draw(plansza);
                        ball.update();
                        p1.update();
                        p2.update();

                        collisionTest(p1,ball);
                        collisionTest2(p2,ball);
                        check_points(ball,p1_point,points1);
                        check_points2(ball,p2_point,points2);

                        if(check_points(ball,p1_point,points1)>=10)
                          {
                            koniec.setString("Wygrywa gracz drugi !!");
                            endgame(window,koniec,endScreen);
                            break;
                          }
                        else if(check_points2(ball,p2_point,points2)>=10)
                        {
                          koniec.setString("Wygrywa gracz pierwszy !!");
                          endgame(window,koniec,endScreen);
                          break;
                        }

                        if (pierwszyRaz)
                        {
                        clock.restart(); // ustawienie zegarka na 0
                          pierwszyRaz = false;
                        }
                        if (drugiRaz)
                        {
                        clock2.restart();
                          drugiRaz = false;
                        }

                        changePosition( clock, pierwszyRaz, circle,ball,los,clock2);
                        addBonus(los,window,b1,clock2,ball,p1,p2,points1,p1_point,points2,p2_point);
                        window.draw(points1);
                        window.draw(points2);
                        window.draw(p1);
                        window.draw(p2);
                        window.draw(circle);
                        window.draw(ball);
                        window.display();
                }
        }
        else if(menu_test.start == false)
        {
          window2.clear(Color::Black);
          window2.draw(tlo);
          window2.display();
        }
    }
    return 0;
}
