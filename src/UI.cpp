#include "../include/UI.h"

UI::UI()
{
    inputText = "";
    statusText = "Ready";
}

void UI::setup()
{
    inputBox.setSize({250.f,45.f});

    inputBox.setPosition({20.f,60.f});

    inputBox.setFillColor(sf::Color::White);

    inputBox.setOutlineThickness(2);

    inputBox.setOutlineColor(sf::Color::Black);
}

void UI::addCharacter(char c)
{
    inputText += c;
}

void UI::removeCharacter()
{
    if(!inputText.empty())
        inputText.pop_back();
}

void UI::clearInput()
{
    inputText.clear();
}

std::string UI::getInput()
{
    return inputText;
}

void UI::setStatus(const std::string& text)
{
    statusText = text;
}

void UI::draw(sf::RenderWindow& window,
              sf::Font& font)
{
    window.draw(inputBox);

    sf::Text heading(font,
                     "Binary Tree Visualizer",
                     34);

    heading.setFillColor(sf::Color::Black);

    heading.setPosition({250.f,10.f});

    window.draw(heading);

    sf::Text label(font,
                   "Enter Value",
                   22);

    label.setFillColor(sf::Color::Black);

    label.setPosition({20.f,30.f});

    window.draw(label);

    sf::Text input(font,
                   inputText,
                   24);

    input.setFillColor(sf::Color::Blue);

    input.setPosition({30.f,68.f});

    window.draw(input);

    sf::Text status(font,
                    "Status : " + statusText,
                    22);

    status.setFillColor(sf::Color::Red);

    status.setPosition({320.f,68.f});

    window.draw(status);
}