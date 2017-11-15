#include "Ball.h"

Ball::Ball(float t_X,float t_Y)
{
    shape.setPosition(t_X,t_Y);
    shape.setRadius(this->ballRadius);
    shape.setFillColor(Color::White);
    shape.setOrigin(this->ballRadius,this->ballRadius);
}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
  target.draw(this->shape,state);
}
void Ball::update()
{
  shape.move(this->velocity);
  if(this->left()<0)
  {
    velocity.x = ballvelocity;
  }
  else if(this->right()>800)
  {
    velocity.x = -ballvelocity;
  }
  if(this->top()<0)
  {
    velocity.y = ballvelocity;
  }
  else if(this->bottom()>600)
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
