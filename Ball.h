#include <SFML/Graphics.hpp>
using namespace sf;
class Ball: public sf::Drawable
{
    public:
        Ball(float t_X, float t_Y);
        Ball() = delete;
        ~Ball() = default;

        void update();
        float left();
        float right();
        float top();
        float bottom();
    private:
      CircleShape shape;
      const float ballRadius {10.0f};
      const float ballvelocity {3.0f};
      Vector2f velocity {ballvelocity,ballvelocity};
      void draw(RenderTarget& target, RenderStates state) const override;
};
