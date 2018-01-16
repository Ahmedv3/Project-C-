#include <SFML/Graphics.hpp>
using namespace sf;
class Ball: public sf::Drawable
{
    public:
        Ball(float t_X, float t_Y);
        Ball() = delete;
        ~Ball() = default;

        void destroy();
        void acceleration();

        void update();

        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();

        Vector2f getPosition();

        float left();
        float right();
        float top();
        float bottom();


    private:
      CircleShape shape;
      const float ballRadius {15.0f};
      float ballvelocity {6.0f};
      Vector2f velocity {ballvelocity,ballvelocity};
      void draw(RenderTarget& target, RenderStates state) const override;
};
