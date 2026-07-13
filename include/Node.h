#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;

    Node* left;
    Node* right;

    float x;
    float y;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
        x = 0.f;
        y = 0.f;
    }
};

#endif