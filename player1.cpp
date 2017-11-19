#include "player1.h"

player1::player1(float t_X,float t_Y)
{
    shape.setPosition(t_X,t_Y);
    shape.setSize({this->paddleWidht,this->paddleHeight});
    shape.setFillColor(Color::Green);
    shape.setOrigin(paddleWidht/2.f,paddleHeight/2.f);

}
void player1::draw(RenderTarget& target, RenderStates state) const
{
    target.draw(this->shape,state);
}

void player1::update()
{
  this->shape.move(this->velocity);
  if(Keyboard::isKeyPressed(Keyboard::Key::W)&&this->top()>0)
  {
    velocity.y = -paddleVelocity;
  }
  else if (Keyboard::isKeyPressed(Keyboard::Key::S)&&this->bottom()<720)
  {
    velocity.y = paddleVelocity;
  }
  else
  {
    velocity.y = 0;
  }
}

float player1::left()
{
  return this->shape.getPosition().x -shape.getSize().x/2.f;
}
float player1::right()
{
  return this->shape.getPosition().x + shape.getSize().x/2.f;
}
float player1::top()
{
  return this->shape.getPosition().y - shape.getSize().y/2.f;
}
float player1::bottom()
{
  return this->shape.getPosition().y + shape.getSize().y/2.f;
}

Vector2f player1::getPosition()
{
  return shape.getPosition();
}
