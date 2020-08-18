#include <bits/stdc++.h>
#include "RBTree.h"

using namespace std;

RBTree::RBTree () {
    nil = new Node{};
    nil->key = 0;
    nil->left = nil->right = nil->parent = nil;
    nil->color = BLACK;
    root = nil;
}

RBTree::~RBTree() {
    clear(root);
    delete nil;
    nil = nullptr;
    root = nullptr;
}

void RBTree::clear (Node* node){
    stack<Node*> nodes;
    if(!nodes.empty()){
        nodes.push(node);
    }
    while (!nodes.empty()){
        Node* aux = nodes.top();
        if(aux->right != nil){
            nodes.push(aux->right);
        }
        if(aux->left != nil){
            nodes.push(aux->left);
        }
        if(aux->right == nil && aux->left == nil){
            RBdelete(nodes.top());

        }
    }
}

void RBTree::left_rotate(Node* node){
    Node* aux = node->right; 
    node->right = aux->left;

    if(aux->left != nil){
        aux->left->parent = node;
    }
    aux->parent = node->parent;
    if(node->parent == nil){
        root = aux;
    }else if(node == node->parent->left){
        node->parent->left = aux;
    }else{
        node->parent->right = aux;
    }

    aux->left = node;
    node->parent = aux;
}

void RBTree::right_rotate(Node* node){
    Node* aux = node->left;
    node->left = aux->right;

    if(aux->right != nil){
        aux->right->parent = node;
    }
    aux->parent = node->parent;
    if(node->parent == nil){
        root = aux;
    }else if(node == node->parent->right){
        node->parent->right = aux;
    }else{
        node->parent->left = aux;
    }

    aux->right = node;
    node->parent = aux;
}

void RBTree::insert(const Tkey &key, const Tvalue &v){
    Node* novo = new Node{};
    novo->key = key;
    novo->value = v;
    novo->left = novo->right = nil;
    novo->parent = nil;

    RBinsert(novo);
}

void RBTree::RBinsert(Node* node){
    Node* father = nil;
    Node* son = root;

    while(son != nil){
        father = son;

        if(node->key == son->key){
            delete node;
            return;
        }
        if(node->key < son->key){
            son = son->left;
        }
        son = son->right;
    }
    node->parent = father;
    if(father == nil){
        root = node;
    }else if(node->key < father->key){
        father->left = node;
    }else{
        father->right = node;
    }
    node->left = node->right = nil;
    node->color = RED;

    RBinsert_fixUp(node);
}