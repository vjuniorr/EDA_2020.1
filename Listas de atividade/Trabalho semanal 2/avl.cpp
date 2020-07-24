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

// Altura da arvore

int avl_height(Node* node){
    if(node == nullptr){
        return 0;
    }
    return node->height;
}

// Busca de um valor pela sua key

Tvalue avl_value(Node* node, Tkey key){
    if(node == nullptr){ // Caso passe uma raiz nula
        cout << "Key não encontrada na sua arvore" << endl;
        return;
    }
    if(key < node->key){ // Se minha chave é menor o no deve estar a esquerda da raiz passada
        return avl_value(node->left, key);
    }else if(key > node->key){ // Se minha chave é maior o no deve estar a direita da raiz passada
        return avl_value(node->right, key);
    }else{ // Caso em que eu encontrei o nó 
        return node->value;
    }
}


