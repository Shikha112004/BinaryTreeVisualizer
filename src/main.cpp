#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/BST.h"
#include "../include/Button.h"
#include "../include/UI.h"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({1000u, 700u}),
        "Binary Tree Visualizer");

    sf::Font font;

    if (!font.openFromFile("assets/Roboto.ttf"))
    {
        std::cout << "Font not loaded!\n";
        return -1;
    }

    //----------------------------------------------------
    // Buttons
    //----------------------------------------------------

    Button insertBtn;
    Button searchBtn;
    Button deleteBtn;
    Button resetBtn;
    Button inorderBtn;
    Button preorderBtn;
    Button postorderBtn;

    insertBtn.setup(font, "INSERT", {20.f, 120.f}, {140.f, 45.f});
    searchBtn.setup(font, "Search", {180.f, 120.f}, {140.f, 45.f});
    deleteBtn.setup(font, "Delete", {340.f, 120.f}, {140.f, 45.f});
    resetBtn.setup(font, "Reset", {500.f, 120.f}, {140.f, 45.f});
    inorderBtn.setup(font, "Inorder", {40.f, 560.f}, {140.f, 45.f});

    preorderBtn.setup(font, "Preorder", {200.f, 560.f}, {140.f, 45.f});

    postorderBtn.setup(font, "Postorder", {360.f, 560.f}, {140.f, 45.f});
    //----------------------------------------------------
    // UI
    //----------------------------------------------------

    UI ui;
    ui.setup();

    //----------------------------------------------------
    // BST
    //----------------------------------------------------

    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    Node *highlightedNode = nullptr;

    std::string traversalResult = "";

    //----------------------------------------------------
    // Game Loop
    //----------------------------------------------------

    //----------------------------------------------------
    // Game Loop
    //----------------------------------------------------

    while (window.isOpen())
    {
        //----------------------------
        // Handle Events
        //----------------------------
        while (const auto event = window.pollEvent())
        {
            // Close
            if (event->is<sf::Event::Closed>())
                window.close();

            // Keyboard
            if (const auto *key = event->getIf<sf::Event::KeyPressed>())
            {
                if (key->scancode == sf::Keyboard::Scancode::Backspace)
                {
                    ui.removeCharacter();
                }

                if (key->scancode == sf::Keyboard::Scancode::Enter)
                {
                    std::string valueText = ui.getInput();

                    if (!valueText.empty())
                    {
                        int value = std::stoi(valueText);
                        if (highlightedNode)
                            ui.setStatus("Node Found");
                        else
                            ui.setStatus("Node Not Found");

                        ui.clearInput();
                    }
                }
            }

            // Typing
            if (const auto *textEvent = event->getIf<sf::Event::TextEntered>())
            {
                char ch = static_cast<char>(textEvent->unicode);

                if (ch >= '0' && ch <= '9')
                    ui.addCharacter(ch);
            }

            // Mouse
            if (const auto *mouse = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouse->button == sf::Mouse::Button::Left)
                {
                    sf::Vector2f pos = window.mapPixelToCoords(mouse->position);
                    std::cout << "Mouse: "
                              << pos.x << " "
                              << pos.y << std::endl;
                    // INSERT
                    if (insertBtn.isClicked(pos))
                    {
                        std::string valueText = ui.getInput();

                        if (!valueText.empty())
                        {
                            int value = std::stoi(valueText);

                            tree.insert(value);

                            highlightedNode = tree.search(value);

                            ui.clearInput();

                            ui.setStatus("Inserted Successfully");
                        }
                        else
                        {
                            ui.setStatus("Enter a Value");
                        }
                    }

                    // SEARCH
                    else if (searchBtn.isClicked(pos))
                    {
                        std::string valueText = ui.getInput();

                        if (!valueText.empty())
                        {
                            int value = std::stoi(valueText);

                            highlightedNode = tree.search(value);

                            if (highlightedNode != nullptr)
                            {
                                ui.setStatus("Node Found");
                            }
                            else
                            {
                                ui.setStatus("Node Not Found");
                            }

                            ui.clearInput();
                        }
                        else
                        {
                            ui.setStatus("Enter a Value");
                        }
                    }
                    // DELETE
                    else if (deleteBtn.isClicked(pos))
                    {
                        std::string valueText = ui.getInput();

                        if (!valueText.empty())
                        {
                            int value = std::stoi(valueText);

                            tree.remove(value);

                            highlightedNode = nullptr;

                            ui.clearInput();

                            ui.setStatus("Deleted Successfully");
                        }
                        else
                        {
                            ui.setStatus("Enter a Value");
                        }
                    }

                    // RESET
                    else if (resetBtn.isClicked(pos))
                    {
                        tree = BST();

                        tree.insert(50);
                        tree.insert(30);
                        tree.insert(70);
                        tree.insert(20);
                        tree.insert(40);
                        tree.insert(60);
                        tree.insert(80);

                        highlightedNode = nullptr;

                        ui.clearInput();

                        ui.setStatus("Tree Reset");
                    }

                    else if (inorderBtn.isClicked(pos))
                    {
                        traversalResult = tree.inorder();
                    }

                    else if (preorderBtn.isClicked(pos))
                    {
                        traversalResult = tree.preorder();
                    }

                    else if (postorderBtn.isClicked(pos))
                    {
                        traversalResult = tree.postorder();
                    }
                }
            }
        } // End pollEvent loop

        //----------------------------
        // Draw
        //----------------------------

        window.clear(sf::Color::White);

        ui.draw(window, font);

        insertBtn.draw(window);
        searchBtn.draw(window);
        deleteBtn.draw(window);
        resetBtn.draw(window);
        inorderBtn.draw(window);
        preorderBtn.draw(window);
        postorderBtn.draw(window);

        sf::Text traversal(
            font,
            "Traversal: " + traversalResult,
            20);

        traversal.setFillColor(sf::Color(0, 102, 204));
        traversal.setPosition({40.f, 620.f});

        window.draw(traversal);

        tree.draw(window, font, highlightedNode);

        window.display();

    } // End window loop

    return 0;
}