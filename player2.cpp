#include "player2.h"

player2::player2(float t_X,float t_Y)
{
    shape.setPosition(t_X,t_Y);
    shape.setSize({this->paddleWidht,this->paddleHeight});
    shape.setFillColor(Color::Red);
    shape.setOrigin(paddleWidht/2.f,paddleHeight/2.f);

}
void player2::draw(RenderTarget& target, RenderStates state) const
{
    target.draw(this->shape,state);
}

void player2::update()
{
  this->shape.move(this->velocity);
  if(Keyboard::isKeyPressed(Keyboard::Key::Up)&&this->top()>0)
  {
    velocity.y = -paddleVelocity;
  }
  else if (Keyboard::isKeyPressed(Keyboard::Key::Down)&&this->bottom()<720)
  {
    velocity.y = paddleVelocity;
  }
  else
  {
    velocity.y = 0;
  }
}

float player2::left()
{
  return this->shape.getPosition().x -shape.getSize().x/2.f;
}
float player2::right()
{
  return this->shape.getPosition().x + shape.getSize().x/2.f;
}
float player2::top()
{
  return this->shape.getPosition().y - shape.getSize().y/2.f;
}
float player2::bottom()
{
  return this->shape.getPosition().y + shape.getSize().y/2.f;
}

Vector2f player2::getPosition()
{
  return shape.getPosition();
}
