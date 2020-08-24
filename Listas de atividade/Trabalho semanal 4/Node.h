#ifndef NODE_H
#define NODE_H
#include "Item.h"

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