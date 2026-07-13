#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include <string>

class UI
{
private:
    sf::RectangleShape inputBox;

    std::string inputText;
    std::string statusText;

public:
    UI();

    void setup();

    void addCharacter(char c);

    void removeCharacter();

    void clearInput();

    std::string getInput();

    void setStatus(const std::string& text);

    void draw(sf::RenderWindow& window,
              sf::Font& font);
};

#endif