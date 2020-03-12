#include <bits/stdc++.h>
#include "avl.h"
#include "item.h"

using namespace std;

struct Node {
    Tkey key;
    Tvalue value;
    int height;
    Node *left;
    Node *right;
};

Tkey avl_getKey(Node *node) {
    return node->key;
}

Tvalue avl_getValue(Node *node) {
    return node->value;
}

Node *avl_search(Node *node, Tkey key){
    if(node->key > key){
        return avl_search(node->left, key);
    }else if(node->key < key){
        return avl_search(node->right, key);
    }
    return node;
}

void avl_preorder(Node *node){
    if(node == nullptr){
        return;
    }
    
    cout << node->key << " : " << node->value << endl;
    avl_preorder(node->left);
    avl_preorder(node->right);
}

void avl_inorder(Node *node){
    if(node == nullptr){
        return;
    }

    avl_inorder(node->left);
    cout << node->key << " : " << node->value << endl;
    avl_inorder(node->right);
}

bool avl_empty(Node *node){
    if(node == nullptr){
        return true;
    }
    return false;
}