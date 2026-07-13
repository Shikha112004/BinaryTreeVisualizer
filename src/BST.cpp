#include "../include/BST.h"

BST::BST()
{
    root = nullptr;
}

Node* BST::getRoot()
{
    return root;
}

Node* BST::insert(Node* node, int value)
{
    if(node==nullptr)
        return new Node(value);

    if(value < node->data)
        node->left = insert(node->left,value);

    else if(value > node->data)
        node->right = insert(node->right,value);

    return node;
}

void BST::insert(int value)
{
    root = insert(root,value);

    assignPositions(root,460.f,180.f,220.f);
}

Node* BST::search(Node* node,int value)
{
    if(node==nullptr)
        return nullptr;

    if(node->data==value)
        return node;

    if(value<node->data)
        return search(node->left,value);

    return search(node->right,value);
}

Node* BST::search(int value)
{
    return search(root,value);
}

void BST::assignPositions(Node* node,
                          float x,
                          float y,
                          float offset)
{
    if(node==nullptr)
        return;

    node->x=x;
    node->y=y;

    assignPositions(node->left,
                    x-offset,
                    y+120,
                    offset/2);

    assignPositions(node->right,
                    x+offset,
                    y+120,
                    offset/2);
}

void BST::drawTree(sf::RenderWindow& window,
                   Node* node,
                   sf::Font& font,
                   Node* highlightedNode)
{
    if(node==nullptr)
        return;

    if(node->left)
    {
        sf::Vertex line[2];

        line[0].position={node->x+35,node->y+35};
        line[0].color=sf::Color::Black;

        line[1].position={node->left->x+35,node->left->y+35};
        line[1].color=sf::Color::Black;

        window.draw(line,2,sf::PrimitiveType::Lines);
    }

    if(node->right)
    {
        sf::Vertex line[2];

        line[0].position={node->x+35,node->y+35};
        line[0].color=sf::Color::Black;

        line[1].position={node->right->x+35,node->right->y+35};
        line[1].color=sf::Color::Black;

        window.draw(line,2,sf::PrimitiveType::Lines);
    }

    sf::CircleShape circle(35);

    if(node==highlightedNode)
        circle.setFillColor(sf::Color::Green);
    else
        circle.setFillColor(sf::Color(135,206,250));

    circle.setOutlineThickness(3);
    circle.setOutlineColor(sf::Color::Black);

    circle.setPosition({node->x,node->y});

    window.draw(circle);

    sf::Text text(font,
                  std::to_string(node->data),
                  28);

    text.setFillColor(sf::Color::Black);
    text.setPosition({node->x+18,node->y+12});

    window.draw(text);

    drawTree(window,node->left,font,highlightedNode);
    drawTree(window,node->right,font,highlightedNode);
}

void BST::draw(sf::RenderWindow& window,
               sf::Font& font,
               Node* highlightedNode)
{
    drawTree(window,
             root,
             font,
             highlightedNode);
}

Node* BST::findMin(Node* node)
{
    while (node && node->left != nullptr)
        node = node->left;

    return node;
}
Node* BST::deleteNode(Node* node, int value)
{
    if (node == nullptr)
        return nullptr;

    if (value < node->data)
    {
        node->left = deleteNode(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = deleteNode(node->right, value);
    }
    else
    {
        // No child
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }

        // One child
        if (node->left == nullptr)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }

        if (node->right == nullptr)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Two children
        Node* temp = findMin(node->right);

        node->data = temp->data;

        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}
void BST::remove(int value)
{
    root = deleteNode(root, value);

    assignPositions(root, 460.f, 180.f, 220.f);
}

void BST::inorder(Node* node, std::string& result)
{
    if (node == nullptr)
        return;

    inorder(node->left, result);

    result += std::to_string(node->data) + " ";

    inorder(node->right, result);
}

std::string BST::inorder()
{
    std::string result;
    inorder(root, result);
    return result;
}

void BST::preorder(Node* node, std::string& result)
{
    if (node == nullptr)
        return;

    result += std::to_string(node->data) + " ";

    preorder(node->left, result);
    preorder(node->right, result);
}

std::string BST::preorder()
{
    std::string result;
    preorder(root, result);
    return result;
}
void BST::postorder(Node* node, std::string& result)
{
    if (node == nullptr)
        return;

    postorder(node->left, result);
    postorder(node->right, result);

    result += std::to_string(node->data) + " ";
}

std::string BST::postorder()
{
    std::string result;
    postorder(root, result);
    return result;
}