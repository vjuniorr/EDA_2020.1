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
        cout << "A raiz passada e nula" << endl;
        return;
    }

    queue<Node*> fila;
    Node* aux = node;
    fila.push(aux);

    while(!fila.empty()){
        cout << fila.front()->key << endl; // Printa o primeiro elemento da fila
        if(fila.front()->left != nullptr){
            fila.push(fila.front()->left); // Caso o filho esquerdo seja diferente de nulo adiciona o filho esquerdo
        }
        if(fila.front()->right != nullptr){
            fila.push(fila.front()->right); // Caso o filho direito seja diferente de nulo adiciona o filho direito 
        }
        fila.pop(); // Remove o elemento que já foi printado
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

Node* avl_insert(Node *node, Tkey key, Tvalue value){
    if(node == nullptr){
        Node* novo = new Node();
        novo->key = key;
        novo->value = value;
        novo->height = 1;
        return novo;
    }
    /* if(avl_search(node, key) != nullptr){
        cout << "Ja existe um no com essa chave" << endl;
        return nullptr;

        Causa do segmentation fault... Mas pq?
    } */
    if(node->key > key){
        node->left = avl_insert(node->left, key, value);
    }else if(node->key < key){
        node->right = avl_insert(node->right, key, value);
    }else{
        return node;
    }

    node->height = 1 + max(avl_height(node->left), avl_height(node->right));
    node = fixup_node(node, key);
    return node;
}

// Funções de rotação para deixar a avl balanceada

Node* avl_rotRight(Node* node){
    // Rotacionando os elementos
    Node* aux = node->left; // Aux vai receber a sub-arvore esquerda do meu no
    node->left = aux->right; // A sub-arvore esquerda do no vai ser a sub-arvore direita do aux
    aux->right = node; // O meu auxiliar passa a ter o no e seus filhos (que são maiores que ele) como sub-arvore a direita
    // Atualizar a aultura dos nos 
    node->height = 1 + max(avl_height(node->left), avl_height(node->right));
    aux->height = 1 + max(avl_height(node->left), avl_height(node->right));

    return aux; 
}

Node* avl_rotLeft(Node* node){
    // Rotacionando os elementos
    Node* aux = node->right; // Aux vai receber a sub-arvore direita do meu no
    node->right = aux->left; // A sub-arvore direita do no vai ser a sub-arvore esquerda do aux
    aux->left = node; // O meu auxiliar passa a ter o no e seus filhos (que são menores que ele) como sub-arvore a esquerda
    // Atualizar a aultura dos nos 
    node->height = 1 + max(avl_height(node->left), avl_height(node->right));
    aux->height = 1 + max(avl_height(node->left), avl_height(node->right));

    return aux;
}

int avl_balance(Node* node){
    if(node == nullptr){ // Se uma arvore está vazia ela está balanceada
        return 0;
    }

    return avl_height(node->right) - avl_height(node->left);
}

Node* fixup_node(Node* node, Tkey key){
    int equi = avl_balance(node);

    if(equi < -1 && key  < node->left->key){
        node = avl_rotRight(node);
    }else if(equi < -1 && key > node->left->key){
        node->left = avl_rotLeft(node->left);
        node =avl_rotRight(node);
    }else if(equi > 1 && key > node->right->key){
        node = avl_rotLeft(node);
    }else if(equi > 1 && key < node->right->key){
        node->right = avl_rotRight(node->right);
        node = avl_rotLeft(node);
    }

    return node;
}

Node* avl_delete(Node *node, Tkey key){
    if(node == nullptr){
        return nullptr;
    }
    if(key < node->key){
        node->left = avl_delete(node->left, key);
    }else if(key > node->key){
        node->right = avl_delete(node->right, key);
    }else if(node->left == nullptr && node->right == nullptr){
        delete node;
        return nullptr;
    }else if(node->left == nullptr || node->right == nullptr){
        Node* child;
        if(node->left != nullptr){
            child = node->left;
        }else{
            child = node->right;
        }
        delete node;
        return child;
    }else{
        node->left = delete_predecessor(node, node->left);
    }

    node = fixup_node_deletion(node);
    return node;
}