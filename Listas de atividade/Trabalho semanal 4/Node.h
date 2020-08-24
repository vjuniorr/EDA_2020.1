#ifndef NODE_H
#define NODE_H
#include "Item.h"

//Francisco Valdemi Leal Costa Junior - 485325

enum Color {RED, BLACK};

class Node{
public:
    Tkey key;
    Tvalue value;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
};

#endif