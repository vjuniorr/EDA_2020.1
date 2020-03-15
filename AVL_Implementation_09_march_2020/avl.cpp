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

Node *avl_clear(Node *node){
    if(node != nullptr){
        node->left = avl_clear(node->left);
        node->right = avl_clear(node->right);
        delete node;
    }
    
    return nullptr;
}

int avl_size(Node *node){

}

/* Node* avl_insert(Node *node, Tkey key, Tvalue value){
    if(node == nullptr){
        Node* novo = new Node();
        novo->key = key;
        novo->value = value;
        return novo;
    }
    if(avl_search(node, key) != nullptr){
        cout << "Ja existe um no com essa chave" << endl;
        return nullptr;
    }
    if(node->key > key){
        node->left = avl_insert(node->left, key, value);
    }else{
        node->right = avl_insert(node->right, key, value);
    }
    return node;
} */