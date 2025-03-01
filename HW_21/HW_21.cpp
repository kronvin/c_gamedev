#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <algorithm>

int main()
{
    unsigned int WINDOW_WIDTH = 700;
    unsigned int WINDOW_HEIGHT = 700;

    sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "HW_21");

    const float circleRadius = 50.f;
    const float borderThickness = 2.f;
    const float borderOffset = 5.f; 

    sf::CircleShape shape(circleRadius);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(sf::Vector2f(circleRadius, circleRadius));
    shape.setPosition(sf::Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f));

    sf::RectangleShape border;
    border.setPosition(sf::Vector2f(borderOffset, borderOffset));
    border.setSize(sf::Vector2f(WINDOW_WIDTH - borderThickness - borderOffset, WINDOW_HEIGHT - borderThickness - borderOffset));
    border.setOutlineThickness(borderThickness);
    border.setOutlineColor(sf::Color::Red);
    border.setFillColor(sf::Color::Transparent);

    float minX = borderOffset + borderThickness + circleRadius;
    float maxX = window.getSize().x - (borderOffset + borderThickness + circleRadius);
    float minY = borderOffset + borderThickness + circleRadius;
    float maxY = window.getSize().y - (borderOffset + borderThickness + circleRadius);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (event->is<sf::Event::Resized>())
            {
                sf::Vector2u newSize = window.getSize();
         
                minX = borderOffset + borderThickness + circleRadius;
                maxX = border.getSize().x + borderOffset - borderThickness - circleRadius;
                minY = borderOffset + borderThickness + circleRadius;
                maxY = border.getSize().y + borderOffset - borderThickness - circleRadius;
            }
        }

        sf::Vector2f pos = shape.getPosition();
        float speed = 0.7f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            pos.x -= speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            pos.x += speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            pos.y -= speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            pos.y += speed;

        pos.x = std::clamp(pos.x, minX, maxX);
        pos.y = std::clamp(pos.y, minY, maxY);
      
        shape.setPosition(pos);


        window.clear();
        window.draw(border);
        window.draw(shape);
        window.display();
    }
}
