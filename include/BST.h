#ifndef BST_H
#define BST_H

#include "Node.h"
#include <SFML/Graphics.hpp>

class BST
{
private:
    Node *root;
    Node *deleteNode(Node *node, int value);
    Node *findMin(Node *node);

    Node *insert(Node *node, int value);
    Node *search(Node *node, int value);
    void inorder(Node *node, std::string &result);
    void preorder(Node *node, std::string &result);
    void postorder(Node *node, std::string &result);

    void assignPositions(Node *node,
                         float x,
                         float y,
                         float offset);

    void drawTree(sf::RenderWindow &window,
                  Node *node,
                  sf::Font &font,
                  Node *highlightedNode);

public:
    BST();

    void insert(int value);

    Node *search(int value);

    void draw(sf::RenderWindow &window,
              sf::Font &font,
              Node *highlightedNode);

    Node *getRoot();
    void remove(int value);
    std::string inorder();
    std::string preorder();
    std::string postorder();
};

#endif