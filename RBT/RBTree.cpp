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