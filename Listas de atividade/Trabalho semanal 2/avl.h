#ifndef AVL_H
#define AVL_H
#include "item.h"

struct Node;

Node* avl_insert(Node *node, Tkey key, Tvalue value); // Função que vai inserir os elementos da arvore
Node* avl_clear(Node* node); // Função que vai limpar toda a arvore
Tvalue avl_value(Node* node, Tkey key); // Função que retorn o value de uma chave, caso a chave exista
void avl_preorder(Node* node); // Print da arvore em pre ordem
void avl_inorder(Node* node); // Print da arvore em ordem
void avl_posorder(Node* node); // Print da arvore em pos-ordem
int avl_height(Node* node); // Função que calcula a altura da sua arvore

// Funções que irão auxiliar na inserção de elementos

Node* avl_rotRight(Node* node); // Função que vai rotacionar a arvore para a direita
Node* avl_rotLeft(Node* node); // Função que vai rotacionar a arvore para a esquerda
Node* fixup_node(Node* node, Tkey key); // Função que vai verificar qual rotação vai ser feita
int avl_balance(Node* node); // Função que vai verificar o balanço da arvore

#endif
