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

// Função que vai limpar a arvore apagando todos os nós

Node* avl_clear(Node* node){
    if(node == nullptr){ // Quando chego em uma posição invalida
        return nullptr;
    }

    avl_clear(node->left); // Eliminando todos os filhos da esquerda da raiz passada
    avl_clear(node->right); // Eliminando todos os filhos da direita da raiz passada
    delete node; // Removendo a raiz passada
    return nullptr;
}

// Funções que vão fazer a inserção e balanceamento na arvore

Node* avl_insert(Node* node, Tkey key, Tvalue value){
    if(node == nullptr){
        Node* no = new Node();
        no->key = key;
        no->value = value;
        no->height = 0;
        return no;
    }
    if(key < node->key){
        node->left = avl_insert(node->left, key, value);
    }else if(key > node->key){
        node->right = avl_insert(node->right, key, value);
    }else{
        return node;
    }

    node->height = 1 + max(avl_height(node->left), avl_height(node->right));
    
}

Node* avl_rotRight(Node* node){
    Node* aux = node->left;
    node->left = aux->right;
    aux->right = node;

    node->height = 1 + max(avl_height(node->left), avl_height(node->right));
    aux->height = 1 + max(avl_height(node->left), avl_height(node->right));

    return aux;
}

Node* avl_rotLeft(Node* node){

}

Node* fixup_node(Node* node, Tkey key){

}

int avl_balance(Node* node){

}