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

void avl_value(Node* node, Tkey key){
    if(node == nullptr){ // Caso passe uma raiz nula
        cout << "Key não encontrada na sua arvore" << endl;
        return;
    }
    if(key < node->key){ // Se minha chave é menor o no deve estar a esquerda da raiz passada
        return avl_value(node->left, key);
    }else if(key > node->key){ // Se minha chave é maior o no deve estar a direita da raiz passada
        return avl_value(node->right, key);
    }else{ // Caso em que eu encontrei o nó 
        cout << node->value << endl;
        return;
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
    if(node == nullptr){ // Quando encontro uma posição valida para criar um novo no
        Node* no = new Node();
        no->key = key;
        no->value = value;
        no->height = 0;
        return no;
    }
    if(key < node->key){ // Caso em que a chave passada é menor que a chave do no passado
        node->left = avl_insert(node->left, key, value);
    }else if(key > node->key){ // Caso em que a chave passada é maior que a chave do no passado
        node->right = avl_insert(node->right, key, value);
    }else{
        return node; // Quando a chave passada é igual a chave do no em que estou eu retorno o no
    }

    node->height = 1 + max(avl_height(node->left), avl_height(node->right)); // Atualizando a altura do no
    node = fixup_node(node, key); // balanceando a arvore

    return node;
}

Node* avl_rotRight(Node* node){
    Node* aux = node->left; // Aux recebe o no a esquerda do meu no passado
    node->left = aux->right; // O no a esquerda passa a apontar para o filho a direita do no passado 
    aux->right = node; // O aux passa a ter o no como seu filho a direita 
    // Atualizando a altura dos nós que foram rotacionado na arvore
    node->height = 1 + max(avl_height(node->left), avl_height(node->right));
    aux->height = 1 + max(avl_height(node->left), avl_height(node->right));

    return aux;
}

Node* avl_rotLeft(Node* node){
    Node* aux= node->right; // Aux vai receber o no a direita do no passado
    node->right = aux->left; // O no a direita passa a apontar para o filho a esquerda do aux
    aux->left = node; // O no aux passa a ter o no como seu filho esquerdo
    // Atualizando a altura dos nós
    node->height = 1 + max(avl_height(node->left), avl_height(node->right));
    aux->height = 1 + max(avl_height(node->left), avl_height(node->right));

    return aux;
}

Node* fixup_node(Node* node, Tkey key){
    int equi = avl_balance(node); // verificando se arvore esta balanceada

    if(equi < -1 && key  < node->left->key){ // Caso em que faço a rotação a direita para balancear a arvore
        node = avl_rotRight(node);
    }else if(equi < -1 && key > node->left->key){ // Caso em que faço a rotação dupla a direita para balancear a arvore
        node->left = avl_rotLeft(node->left);
        node =avl_rotRight(node);
    }else if(equi > 1 && key > node->right->key){  // Caso em que faço a rotação a esquerda para balancear a arvore
        node = avl_rotLeft(node);
    }else if(equi > 1 && key < node->right->key){ // Caso em que faço a rotação dupla a esquerda para balancear a arvore
        node->right = avl_rotRight(node->right);
        node = avl_rotLeft(node);
    }

    return node;
}

int avl_balance(Node* node){
    if(node == nullptr){ // Se uma arvore está vazia ela está balanceada
        return 0;
    }

    return avl_height(node->right) - avl_height(node->left);
}