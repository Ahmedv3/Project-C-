#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class player1 :public sf::Drawable
{
    public:
        player1(float t_X,float t_Y);
        player1() = delete;
        ~player1()=default;
        void update();
        float right();
        float left();
        float top();
        float bottom();

        Vector2f getPosition();
    private:
      void draw(RenderTarget& target, RenderStates state) const override;
      RectangleShape shape;
      const float paddleWidht {20.0f};
      const float paddleHeight {80.0f};
      const float paddleVelocity {6.0f};
      Vector2f velocity {0.f,paddleVelocity};


};