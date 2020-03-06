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
    cout << node->key << " : " << node->value << endl;
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

int bst_height(Node *node){
    if(node == nullptr){ // Caso base da recursão
        return 0;
    }
    if(bst_height(node->left) > bst_height(node->right)){ // Verifica a maior distancia para retornar
        return 1 + bst_height(node->left); // Se a folha mais longe da raiz estiver na sub-arvore esquerda retorna sua distancia + 1
    }else{
        return 1 + bst_height(node->right); // Se a folha mais longe da raiz estiver na sub-arvore direita retorna sua distancia + 1
    }
}

bool bst_empty(Node* node){
    if(node == nullptr){ // Se a raiz da arvore for nula a arvore é vazia 
        return true;
    }
    return false;
}

Node *bst_minimum(Node *node){
    if(node->left == nullptr){ // Se o proximo nó a esquerda for nulo, quer dizer que aquele nó é o menor da arvore
        return node;
    }
    return bst_minimum(node->left); // Procura pelo menor nó
}

Node *bst_maximum(Node *node){
    if(node->right == nullptr){ // Se o proximo nó a direita for nulo, quer dizer que aquele nó é o menor da arvore
        return node;
    }
    return bst_maximum(node->right); // Procura pelo maior nó
}

Node* bst_successor(Node* root, Node *x){   
    if(bst_empty(root)){
        return nullptr;
    }

    while(root->key != x->key){
        if(root->key > x->key){
            root = root->left;
        }else{
            root = root->right;
        }
    }

    return bst_minimum(root->right);
    
}

Node* bst_predecessor(Node* root, Node *x){

}