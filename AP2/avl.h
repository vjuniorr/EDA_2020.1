#ifndef AVL_H
#define AVL_H
#include <bits/stdc++.h>
#include "node.h"

using namespace std;
template <typename Tkey, typename Tvalue>

class avl{
private:
    Node<Tkey, Tvalue> *root;

protected:
    Node<Tkey, Tvalue>* left_rotate(Node<Tkey, Tvalue> *node){
        Node<Tkey, Tvalue> *aux = node->right;
        node->right = aux->left;
        aux->left = node;

        node->height = 1 + max(avl_height(node->right), avl_height(node->left));
        aux->height = 1 + max(avl_height(node->right), avl_height(node->left));
    }

    Node<Tkey, Tvalue>* right_rotate(Node<Tkey, Tvalue> *node){
        // Rotacionando os elementos
        Node<Tkey, Tvalue> *aux = node->left; // Aux vai receber a sub-arvore esquerda do meu no
        node->left = aux->right;              // A sub-arvore esquerda do no vai ser a sub-arvore direita do aux
        aux->right = node;                    // O meu auxiliar passa a ter o no e seus filhos (que são maiores que ele) como sub-arvore a direita
        // Atualizar a aultura dos nos
        node->height = 1 + max(avl_height(node->left), avl_height(node->right));
        aux->height = 1 + max(avl_height(node->left), avl_height(node->right));
    }

    Node<Tvalue, Tkey> avl_insert(Node<Tkey, Tvalue> *node, Tkey key, Tvalue value){
        if (node == nullptr)
        {
            Node *novo = new Node();
            novo->key = key;
            novo->value = value;
            novo->height = 1;
            return novo;
        }

        if (node->key > key)
        {
            node->left = avl_insert(node->left, key, value);
        }
        else if (node->key < key)
        {
            node->right = avl_insert(node->right, key, value);
        }
        else
        {
            return node;
        }

        node->height = 1 + max(avl_height(node->left), avl_height(node->right));
        node = fixup_node(node, key);
        return node;
    }

    Node<Tkey, Tvalue> *avlinsert_fixup(Node<Tkey, Tvalue> *node, Tkey key){
        int equi = avl_balance(node);

        if (equi < -1 && key < node->left->key){
            node = avl_rotRight(node);
        }
        else if (equi < -1 && key > node->left->key){
            node->left = avl_rotLeft(node->left);
            node = avl_rotRight(node);
        }
        else if (equi > 1 && key > node->right->key){
            node = avl_rotLeft(node);
        }
        else if (equi > 1 && key < node->right->key){
            node->right = avl_rotRight(node->right);
            node = avl_rotLeft(node);
        }

        return node;
    }
    
    void avl_search(Node<Tkey, Tvalue> *node, Tkey key);

    int avl_height(Node<Tkey, Tvalue> *node){
        if(node == nullptr){
            return 0;
        }

        return node->height;
    }
    
    int avl_balance(Node<Tkey, Tvalue> *node){
        if(node == nullptr){
            return 0;
        }

        return avl_height(node->right) - avl_height(node->left);
    }

public:
    avl(){
        root = new Node<Tkey, Tvalue>();
    }

    Node<Tkey, Tvalue> GetRoot(){
        return root;
    }

    ~avl();

    void avlInsert(Tkey key, Tvalue value)
    {
        root = avl_insert(root, key, value);
    }

    void avlSearch(Tkey key){
        avl_search(root, key);
    }
};

#endif