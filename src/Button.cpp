#include "../include/Button.h"
#include<iostream>

Button::Button()
{
    text = nullptr;
}

void Button::setup(sf::Font& font,
                   const std::string& title,
                   sf::Vector2f position,
                   sf::Vector2f size)
{
    rectangle.setSize(size);
    rectangle.setPosition(position);

    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOutlineThickness(2.f);
    rectangle.setOutlineColor(sf::Color::Black);

    text = std::make_unique<sf::Text>(font, title, 22);

    text->setFillColor(sf::Color::Black);

    sf::FloatRect bounds = text->getLocalBounds();

    text->setPosition({
        position.x + (size.x - bounds.size.x) / 2.f,
        position.y + (size.y - bounds.size.y) / 2.f - 6.f
    });
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);

    if(text)
        window.draw(*text);
}

bool Button::isClicked(sf::Vector2f mousePos)
{
    auto bounds = rectangle.getGlobalBounds();

    std::cout << "Button bounds: "
              << bounds.position.x << ", "
              << bounds.position.y << " -> "
              << bounds.size.x << " x "
              << bounds.size.y << std::endl;

    return bounds.contains(mousePos);
}


bool Button::isHovered(sf::Vector2f mousePos)
{
    return rectangle.getGlobalBounds().contains(mousePos);
}

void Button::setColor(sf::Color color)
{
    rectangle.setFillColor(color);
}

sf::FloatRect Button::getBounds() const
{
    return rectangle.getGlobalBounds();
}