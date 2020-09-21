#ifndef NODE_H
#define NODE_H

template <typename Tkey, typename Tvalue>

class Node{
    public:
        Tkey key;
        Tvalue value;
        Node* left;
        Node* right;
        int height;
};
#endif