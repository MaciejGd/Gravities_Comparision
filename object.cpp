#include "object.hpp"
#include <math.h>

physicObject::physicObject()
{
}

physicObject::physicObject(float radius, sf::Vector2f starting_pos, float acceleration)
{   
    this->radius = radius;
    this->pos = starting_pos;
    this->acceleration = acceleration;
}

physicObject::~physicObject()
{
}

void physicObject::move(float boundary, sf::Clock& clock)
{   
    sf::Time elapsed_Time = clock.getElapsedTime();
    float time = elapsed_Time.asSeconds() * (0.1);
    //has to convert energy while falling down
    if (velocity == 0 && slowing_down!=0)
    {
        slowing_down = 0.f;
        clock.restart();
    }
    velocity = acceleration*time - slowing_down;
    pos.y+=velocity;
    if (pos.y+radius >= boundary && velocity >= 0)
    {   
        pos.y = boundary - radius;
        slowing_down = 0.5f*velocity;
        clock.restart();
    }
}



void physicObject::drawCirc(sf::RenderWindow &window, sf::Color color)
{   
    sf::VertexArray list(sf::Points);
    sf::Vector2f position;
    for(float degree = 0.f; degree <= 6.28f; degree+=0.01f)
    {   
        position = {pos.x - radius*std::cos(degree),pos.y - radius*std::sin(degree)};
        list.append(sf::Vertex(position, color));
    }

    window.draw(list);
}
