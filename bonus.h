#include <SFML/Graphics.hpp>
using namespace sf;
class bonus: public sf::Drawable
{
    public:
        bonus();

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
