#ifndef AVL_H
#define AVL_H
#include "item.h"

struct Node;

Node* avl_insert(Node *node, Tkey key, Tvalue);
Node* avl_delete(Node *node, Tkey key);

Tkey avl_getKey(Node *node);
Tvalue avl_getValue(Node *node);
Node *avl_search(Node *node, Tkey key);
void avl_preorder(Node *node);
void avl_inorder(Node *node);
void avl_level_traversal(Node *node);
int avl_height(Node *node);
int avl_size(Node *node);
bool avl_empty(Node *node);
Node *avl_clear(Node *node);

// Funções de rotação para balancear a arvore

Node* avl_rotRight(Node* node);
Node* avl_rotLeft(Node* node);

// Função para verificar se a arvore suas sub-arvores estão balanceadas

int avl_balance(Node* node);

#endif 
