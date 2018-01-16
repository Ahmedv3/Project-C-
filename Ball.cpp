#include "iostream"
#include "Ball.h"
#include <cstdlib>
#include <ctime>



Ball::Ball(float t_X,float t_Y)
{
    srand( time( NULL ) );
    shape.setPosition(t_X,t_Y);
    shape.setRadius(this->ballRadius);
    shape.setFillColor(Color::White);
    shape.setOrigin(this->ballRadius,this->ballRadius);
}

void Ball::draw(RenderTarget& target, RenderStates state) const
{

  target.draw(this->shape,state);
}
void Ball::acceleration()
{
  ballvelocity = ballvelocity + 0.18f;
}

void Ball::destroy()
{
  shape.setPosition(640,360);
  ballvelocity = 6.0f;

  if(velocity.x == ballvelocity)
  {
    velocity.x = -ballvelocity;
  }
  else if(velocity.x == -ballvelocity)
  {
    velocity.x = ballvelocity;
  }

}

void Ball::update()
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
float Ball::left()
{
  return this->shape.getPosition().x - shape.getRadius();
}
float Ball::right()
{
  return this->shape.getPosition().x + shape.getRadius();
}
float Ball::top()
{
  return this->shape.getPosition().y - shape.getRadius();
}
float Ball::bottom()
{
  return this->shape.getPosition().y + shape.getRadius();
}

void Ball::moveDown()
{
  this ->velocity.y = ballvelocity;
}

void Ball::moveUp()
{
  this ->velocity.y = -ballvelocity;
}

void Ball::moveRight()
{
  this ->velocity.x = ballvelocity;
}

void Ball::moveLeft()
{
  this ->velocity.x = -ballvelocity;
}

Vector2f Ball::getPosition()
{
  return shape.getPosition();
}
