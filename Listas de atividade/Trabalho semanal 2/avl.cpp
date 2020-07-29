#include <bits/stdc++.h>
#include "avl.h"
#include "item.h"

/*
Francisco Valdemi Leal Costa Junior - 485325
*/

using namespace std;

struct Node{
    Tkey key;
    Tvalue value;
    Node* left;
    Node* right;
    int height;
};


Tkey avl_getKey(Node* node){
    return node->key;
}

Tvalue avl_getValue(Node* node){
    return node->value;
}

// Funções de print da avl

void avl_preorder(Node* node){
    if(node == nullptr){
        return;
    }

    cout << avl_getKey(node) << ":" << avl_getValue(node) << endl;
    avl_preorder(node->left);
    avl_preorder(node->right);
}

void avl_inorder(Node* node){
    if(node == nullptr){
        return;
    }

    avl_inorder(node->left);
    cout << avl_getKey(node) << ":" << avl_getValue(node) << endl;
    avl_inorder(node->right);
}

void avl_posorder(Node* node){
    if(node == nullptr){
        return;
    }

    avl_posorder(node->left);
    avl_posorder(node->right);
    cout << avl_getKey(node) << ":" << avl_getValue(node) << endl;
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
        cout << "Chave não encontrada na sua arvore" << endl;
        return;
    }
    if(key < node->key){ // Se minha chave é menor o no deve estar a esquerda da raiz passada
        return avl_value(node->left, key);
    }else if(key > node->key){ // Se minha chave é maior o no deve estar a direita da raiz passada
        return avl_value(node->right, key);
    }else{ // Caso em que eu encontrei o nó 
        cout << avl_getValue(node) << endl;
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
        no->height = 1;
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
        node = avl_rotRight(node);
    }else if(equi > 1 && key > node->right->key){  // Caso em que faço a rotação a esquerda para balancear a arvore
        node = avl_rotLeft(node);
    }else if(equi > 1 && key < node->right->key){ // Caso em que faço a rotação dupla a esquerda para balancear a arvore
        node->right = avl_rotRight(node->right);
        node = avl_rotLeft(node);
    }

    return node;
}

 // Função para verificar o balanceamento da arvore

int avl_balance(Node* node){
    if(node == nullptr){ // Se uma arvore está vazia ela está balanceada
        return 0;
    }

    return avl_height(node->right) - avl_height(node->left);
}

// Função menu da minha arvore

void menu(){
    Node* root = nullptr;
    Tkey key = "";
    Tvalue value = "";
    int op = 0; // Opção do usuario

    while (op != 8){
        cout << "--------------" << endl;
        cout << "Menu da arvore" << endl;
        cout << "--------------" << endl;
        cout << "1. Inserir na arvore" << endl;
        cout << "2. Limpar a arvore" << endl;
        cout << "3. Buscar um valor na arvore" << endl;
        cout << "4. Exibir a arvore em pre-ordem" << endl;
        cout << "5. Exibir a arvore em ordem" << endl;
        cout << "6. Exibir a arvore em pos-ordem" << endl;
        cout << "7. Altura da sua arvore" << endl;
        cout << "8. Sair" << endl;
        cout << "Digite sua opção:";
        cin >> op;

        switch (op){
        case 1:
            cout << "Digite a chave do elemento que vai ser inserido:";
            cin >> key;
            cout << "Digite o valor do elemento que vai ser inserido:";
            cin >> value;
            
            root = avl_insert(root, key, value);
            system("clear");
            cout << "Elemento inserido com sucesso" << endl;
            break;
        case 2:
            root = avl_clear(root);
            system("clear");
            cout << "Arvore limpa com sucesso" << endl;
            break;
        case 3:
            cout << "Digite a chave do elemento desejado:";
            cin >> key;

            system("clear");
            cout << "Valor da chave passada:";
            avl_value(root, key);
            break;
        case 4:
            if(root != nullptr){
                system("clear");
                avl_preorder(root);
            }else{
                cout << "Sua arvore esta vazia" << endl;
            }
            break;
        case 5:
            if(root != nullptr){
                system("clear");
                avl_inorder(root);
            }else{
                cout << "Sua arvore esta vazia" << endl;
            }
            break;
        case 6:
            if(root != nullptr){
                system("clear");
                avl_posorder(root);
            }else{
                cout << "Sua arvore esta vazia" << endl;
            }
            break;
        case 7:
            system("clear");
            cout << avl_height(root) << endl;
            break;
        case 8:
            root = avl_clear(root);
            op = 8;
            break;    
        default:
            cout << "Opcao invalida" << endl;

            op = 0;
            break;
        }
    }

    return;
}