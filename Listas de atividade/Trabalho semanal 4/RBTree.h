#ifndef RBTREE_H 
#define RBTREE_H
#include "Node.h"

//Francisco Valdemi Leal Costa Junior - 485325

class RBTree{
private:
    Node *root = nullptr;
    Node *nil = nullptr;

protected:
    void left_rotate(Node *node);
    void right_rotate(Node *node);
    void RBinsert(Node *node);
    void RBinsert_fixUp(Node *node);
    void RBdelete(Node *z);
    void RBdelete_fixUp(Node *x);
    Node *minimum(Node *node);
    void clear(Node *node);

public:
    RBTree();
    void insert(const Tkey &key, const Tvalue &v);
    void remove(const Tkey &key);
    void clearM();
    bool search(const Tkey &key);
    void preorder();
    bool empty();
    int height();
    ~RBTree();
};

void menu();
#endif
