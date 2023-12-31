#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class physicObject
{
    float velocity;
    float acceleration;
    float slowing_down;
    float radius;
    sf::Vector2f pos;

    public:
        physicObject();
        physicObject(float radius, sf::Vector2f starting_pos, float acceleration);
        ~physicObject();
        void move(float boundary, sf::Clock& clock);
        void drawCirc(sf::RenderWindow& window, sf::Color color);

};