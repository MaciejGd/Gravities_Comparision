#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "object.hpp"
#include<chrono>

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;


int main ()
{   
    //loading font 
    sf::Font font;
    if (!font.loadFromFile("Fontspring-DEMO-compiler-black.otf")) {
        // Error handling if the font loading fails
        return -1;
    }
    //setting texts for balls
    sf::Text text_earth;
    text_earth.setCharacterSize(40);
    text_earth.setFont(font);
    text_earth.setString("Earth");
    text_earth.setFillColor(sf::Color::Cyan);
    text_earth.setOrigin(text_earth.getLocalBounds().width/2.f, text_earth.getLocalBounds().height / 2.f);
    text_earth.setPosition((float)WINDOW_WIDTH/8 * 3, 20);

    sf::Text text_mars;
    text_mars.setCharacterSize(40);
    text_mars.setFont(font);
    text_mars.setString("Mars");
    text_mars.setFillColor(sf::Color::Red);
    text_mars.setOrigin(text_mars.getLocalBounds().width/2.f, text_mars.getLocalBounds().height / 2.f);
    text_mars.setPosition(WINDOW_WIDTH/8 * 5,20);

    sf::Text text_moon;
    text_moon.setCharacterSize(40);
    text_moon.setFont(font);
    text_moon.setString("Moon");
    text_moon.setFillColor(sf::Color::White);
    text_moon.setOrigin(text_moon.getLocalBounds().width/2.f, text_moon.getLocalBounds().height / 2.f);
    text_moon.setPosition(WINDOW_WIDTH/8 * 7,20);

    sf::Text text_sun;
    text_sun.setCharacterSize(40);
    text_sun.setFont(font);
    text_sun.setString("Sun");
    text_sun.setFillColor(sf::Color:: Yellow);
    text_sun.setOrigin(text_sun.getLocalBounds().width/2.f, text_sun.getLocalBounds().height / 2.f);
    text_sun.setPosition(WINDOW_WIDTH/8,20);
    //initializing window 
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Gravity", sf::Style::Close);

    //initialization of clocks and creating dynamic objects 
    sf::Clock clock_earth;
    sf::Clock clock_mars;
    sf::Clock clock_moon;
    sf::Clock clock_sun;
    physicObject* earth = new physicObject(50,sf::Vector2f((float)WINDOW_WIDTH/8 * 3, (float)WINDOW_HEIGHT/2 - 200), 9.81f);
    physicObject* mars = new physicObject(50,sf::Vector2f((float)WINDOW_WIDTH/8 * 5, (float)WINDOW_HEIGHT/2 - 200), 3.71f);
    physicObject* moon = new physicObject(50,sf::Vector2f((float)WINDOW_WIDTH/8 * 7, (float)WINDOW_HEIGHT/2 - 200), 1.62f);
    physicObject* sun = new physicObject(50,sf::Vector2f((float)WINDOW_WIDTH/8, (float)WINDOW_HEIGHT/2 - 200), 274.f);

    while(window.isOpen())
    {   
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        //refreshing objects
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            delete earth; delete mars; delete moon; delete sun;
            earth = new physicObject(45,sf::Vector2f((float)WINDOW_WIDTH/8 * 3, (float)WINDOW_HEIGHT/2 -200), 9.81f);
            mars = new physicObject(45,sf::Vector2f((float)WINDOW_WIDTH/8 * 5, (float)WINDOW_HEIGHT/2 - 200), 3.71f);
            moon = new physicObject(45,sf::Vector2f((float)WINDOW_WIDTH/8 * 7, (float)WINDOW_HEIGHT/2 -200), 1.62f);
            sun = new physicObject(45,sf::Vector2f((float)WINDOW_WIDTH/8, (float)WINDOW_HEIGHT/2 - 200), 274.f);

            clock_earth.restart();
            clock_mars.restart();
            clock_moon.restart();
            clock_sun.restart();
        }
       
        //moving balls 
        earth->move(WINDOW_HEIGHT, clock_earth);
        mars->move(WINDOW_HEIGHT, clock_mars);
        moon->move(WINDOW_HEIGHT, clock_moon);
        sun->move(WINDOW_HEIGHT, clock_sun);

        window.clear(sf::Color::Black);
        //drawing texts
        window.draw(text_earth);
        window.draw(text_mars);
        window.draw(text_moon);
        window.draw(text_sun);
        //drawing balls
        earth->drawCirc(window, sf::Color::Cyan);
        mars->drawCirc(window, sf::Color::Red);
        moon->drawCirc(window, sf::Color::White);
        sun->drawCirc(window, sf::Color::Yellow);
        //window.draw(list_of_points);
        window.display();
    }

    return 1;
}
