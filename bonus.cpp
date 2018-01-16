#include "iostream"
#include "bonus.h"
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;

bonus::bonus()
{
    srand( time( NULL ) );
    int t_X = ( rand() % 700 ) + 300;
    int t_Y = ( rand() % 500 ) + 100;
    shape.setPosition(t_X,t_Y);
    shape.setRadius(this->ballRadius);
    shape.setFillColor(Color::Magenta);
    shape.setOrigin(this->ballRadius,this->ballRadius);
}

void bonus::draw(RenderTarget& target, RenderStates state) const
{

  target.draw(this->shape,state);
}

void bonus::update()
{
  shape.move(this->velocity);
  if(this->left()<0)
  {
    velocity.x = ballvelocity;
  }
  else if(this->right()>1280)
  {
    velocity.x = -ballvelocity;
  }
  if(this->top()<0)
  {
    velocity.y = ballvelocity;
  }
  else if(this->bottom()>720)
  {
    velocity.y = -ballvelocity;
  }
}
float bonus::left()
{
  return this->shape.getPosition().x - shape.getRadius();
}
float bonus::right()
{
  return this->shape.getPosition().x + shape.getRadius();
}
float bonus::top()
{
  return this->shape.getPosition().y - shape.getRadius();
}
float bonus::bottom()
{
  return this->shape.getPosition().y + shape.getRadius();
}

void bonus::moveDown()
{
  this ->velocity.y = ballvelocity;
}

void bonus::moveUp()
{
  this ->velocity.y = -ballvelocity;
}

void bonus::moveRight()
{
  this ->velocity.x = ballvelocity;
}

void bonus::moveLeft()
{
  this ->velocity.x = -ballvelocity;
}

Vector2f bonus::getPosition()
{
  return shape.getPosition();
}
