#include <iostream>
#include "item.h"
#include "bst.h"

using namespace std;

struct Node {
    Tkey key;
    Tvalue value;
    Node* left;
    Node* right;
};

Tkey bst_getKey(Node *node){
    return node->key;
}

Tvalue bst_getValue(Node *node){
    return node->value;
}

Node *bst_search(Node *node, Tkey myKey){
    if(node == nullptr){
        return nullptr;
    }
    if(node->key == myKey){
        return node;
    }
    if(node->key > myKey){
        return bst_search(node->left, myKey);
    }else{
        return bst_search(node->right, myKey);
    }
}

Node *bst_insert(Node *node, Tkey myKey, Tvalue value){
    if(bst_search(node, myKey) != nullptr){
        cout << "A chave já existe na arvore";
        return bst_search(node, myKey);
    }
    if(node == nullptr){
        node = new Node;
        node->key = myKey;
        node->value = value;
        node->left = node->right = nullptr;
        return node;
    }else if(node->key < myKey){
        return bst_insert(node->right, myKey, value);
    }else{
        return bst_insert(node->left, myKey, value);
    }
}

void bst_preorder(Node *node){
    if(node == nullptr){
        return;
    }
    cout << node->key << ": " << node->value;
    bst_preorder(node->left);
    bst_preorder(node->right);
}

void bst_preorder(Node *node, void f(Node*)){
    if(node != nullptr){
        f(node);
        bst_preorder(node->left, f);
        bst_preorder(node->right, f);
    }
}

Node *bst_clear(Node *node){
    if(node != nullptr){
        node->left = bst_clear(node->left);
        node->right = bst_clear(node->right);
        delete node;
    }
    return nullptr;
}

 Node *bst_remove(Node *node, Tkey key){
     
 }