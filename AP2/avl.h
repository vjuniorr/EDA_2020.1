#ifndef AVL_H
#define AVL_H
#include <bits/stdc++.h>
#include "node.h"

using namespace std;
template <typename Tkey, typename Tvalue>

class avl{
private:
    Node<Tkey, Tvalue>* root;
protected:
    void left_rotate(Node<Tkey, Tvalue> node);
    void right_rotate(Node<Tkey, Tvalue> node);
    void avl_insert(Node<Tkey, Tvalue>* node);
    void avlinsert_fixup(Node<Tkey, Tvalue>* node);
    void avl_search(Node<Tkey, Tvalue>* node);
public:
    avl(/* args */);
    ~avl();
};

/* avl::avl(){
} */

/* avl::~avl(){
} */


#endif 