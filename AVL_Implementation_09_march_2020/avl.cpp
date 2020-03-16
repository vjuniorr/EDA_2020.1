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

void avl_level_traversal(Node *node){
    if(node == nullptr){
        return;
    }
    stack<Node*> fila;
    Node* aux = node;
    fila.push(aux);

    while(!fila.empty()){
        cout << fila.top()->key << endl;
        fila.push(fila.top()->left);
        fila.push(fila.top()->right);
        fila.pop();
    }
    
    return;
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
    if(node == nullptr){
        return 0;
    }
    return 1 + avl_size(node->left) + avl_size(node->right);
}

int avl_height(Node *node){
    if(node == nullptr){
        return 0;
    }
    return node->height;
}

/* Node* avl_insert(Node *node, Tkey key, Tvalue value){
    if(node == nullptr){
        Node* novo = new Node();
        novo->key = key;
        novo->value = value;
        novo->height = 0;
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

Node* rotRight(Node* node){
    // Rotacionando os elementos
    Node* aux = node->left; // Aux vai receber a sub-arvore esquerda do meu no
    node->left = aux->right; // A sub-arvore esquerda do no vai ser a sub-arvore direita do aux
    aux->right = node; // O meu auxiliar passa a ter o no e seus filhos (que são maiores que ele) como sub-arvore a direita
    // Atualizar a aultura dos nos 
    node->height = 1 + max(avl_height(node->left), avl_height(node->right));
    aux->height = 1 + max(avl_height(node->left), avl_height(node->right));

    return aux; 
}

Node* rotLeft(Node* node){
    // Rotacionando os elementos
    Node* aux = node->right; // Aux vai receber a sub-arvore direita do meu no
    node->right = aux->left; // A sub-arvore direita do no vai ser a sub-arvore esquerda do aux
    aux->left = node; // O meu auxiliar passa a ter o no e seus filhos (que são menores que ele) como sub-arvore a esquerda
    // Atualizar a aultura dos nos 
    node->height = 1 + max(avl_height(node->left), avl_height(node->right));
    aux->height = 1 + max(avl_height(node->left), avl_height(node->right));

    return aux;
}