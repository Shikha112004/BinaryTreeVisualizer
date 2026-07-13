#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class Button
{
private:
    sf::RectangleShape rectangle;
    std::unique_ptr<sf::Text> text;

public:
    Button();

    void setup(sf::Font& font,
               const std::string& title,
               sf::Vector2f position,
               sf::Vector2f size);

    void draw(sf::RenderWindow& window);

    bool isClicked(sf::Vector2f mousePos);

    bool isHovered(sf::Vector2f mousePos);

    void setColor(sf::Color color);

    sf::FloatRect getBounds() const;
};

#endif