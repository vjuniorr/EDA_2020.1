#include <bits/stdc++.h>
#include "avl.h"
#include "item.h"

using namespace std;

struct Node{
    Tkey key;
    Tvalue value;
    Node* left;
    Node* right;
    int height;
};

// Funções de print da avl

void avl_preorder(Node* node){
    if(node == nullptr){
        return;
    }

    cout << node->value << endl;
    avl_preorder(node->left);
    avl_preorder(node->right);
}

void avl_inorder(Node* node){
    if(node == nullptr){
        return;
    }

    avl_inorder(node->left);
    cout << node->value << endl;
    avl_inorder(node->right);
}

void avl_posorder(Node* node){
    if(node == nullptr){
        return;
    }

    avl_posorder(node->left);
    avl_posorder(node->right);
    cout << node->value << endl;
}


