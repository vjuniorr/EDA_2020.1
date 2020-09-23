#ifndef AVL_H
#define AVL_H
//#include <bits/stdc++.h>
#include <vector>
#include <list>
#include "node.h"
#include "pessoa.h"

using namespace std;
template <typename Tkey>

class avl{
private:
    Node<Tkey> *root = NULL;
protected:
    Node<Tkey>* left_rotate(Node<Tkey> *node){
        Node<Tkey> *aux = node->right;
        node->right = aux->left;
        aux->left = node;

        node->height = 1 + max(avl_height(node->left), avl_height(node->right));
        aux->height = 1 + max(avl_height(aux->left), avl_height(aux->right));

        return aux;
    }

    Node<Tkey>* right_rotate(Node<Tkey> *node){
        // Rotacionando os elementos
        Node<Tkey> *aux = node->left; // Aux vai receber a sub-arvore esquerda do meu no
        node->left = aux->right;              // A sub-arvore esquerda do no vai ser a sub-arvore direita do aux
        aux->right = node;                    // O meu auxiliar passa a ter o no e seus filhos (que são maiores que ele) como sub-arvore a direita
        // Atualizar a aultura dos nos
        node->height = 1 + max(avl_height(node->left), avl_height(node->right));
        aux->height = 1 + max(avl_height(aux->left), avl_height(aux->right));

        return aux;
    }

    Node<Tkey> * avl_insert(Node<Tkey>* node, Tkey key, Pessoas* value){
        if (node == nullptr){
            Node<Tkey> *novo = new Node<Tkey>();
            novo->key = key;
            novo->value.push_back(value);
            novo->height = 1;
            novo->left = novo->right = nullptr;
            return novo;
        }

        if (node->key > key){
            node->left = avl_insert(node->left, key, value);
        }
        else if (node->key < key){
            node->right = avl_insert(node->right, key, value);
        }
        else{
            node->value.push_back(value);
            return node;
        }

        node->height = 1 + max(avl_height(node->left), avl_height(node->right));
        node = avlinsert_fixup(node, key);
        return node;
    }
    
    Node<Tkey> *avlinsert_fixup(Node<Tkey> *node, Tkey key){
        int equi = avl_balance(node);

        if (equi < -1 && key < node->left->key){
            node = right_rotate(node);
        }
        else if (equi < -1 && key > node->left->key){
            node->left = left_rotate(node->left);
            node = right_rotate(node);
        }
        else if (equi > 1 && key > node->right->key){
            node = left_rotate(node);
        }
        else if (equi > 1 && key < node->right->key){
            node->right = right_rotate(node->right);
            node = left_rotate(node);
        }

        return node;
    }
    
    Node<Tkey>* avl_searchCPF(Node<Tkey> *node, Tkey key){
        Node<Tkey>* aux = root;
        while(aux != nullptr){
            if(aux->key > key){
                aux = aux->left;
            }else if(aux->key < key){
                aux = aux->right;
            }else{
                return aux;
            }
        }
        cout << "O CPF passado nao esta no documento" << endl;
        return nullptr;
    }

    void avl_cout(Node<Tkey>* node){
        for(int i = 0; i < node->value.size(); i++){
            cout << node->value[i]->cpf << ",";
            cout << node->value[i]->nome << ",";
            cout << node->value[i]->sobrenome << ",";
            cout << node->value[i]->data.tm_mon << "/";
            cout << node->value[i]->data.tm_mday << "/";
            cout << node->value[i]->data.tm_year << ",";
            cout << node->value[i]->cidade << endl;
        }
    }

    string nome_(string nome, int aux){
        string str;
        for(int i = 0; i < aux; i++){
            str += nome[i];
        }
        return str;
    }

    void avl_searchDate(Node<Tkey>* node, Tkey key){
        
    }

    int avl_height(Node<Tkey> *node){
        if(node == nullptr){
            return 0;
        }

        return node->height;
    }
    
    int avl_balance(Node<Tkey> *node){
        if(node == nullptr){
            return 0;
        }

        return avl_height(node->right) - avl_height(node->left);
    }

public:
    avl(){
        //root = new Node<Tkey>();
    }

    Node<Tkey>* GetRoot(){
        return root;
    }

    ~avl();

    void avlInsert(Tkey key, Pessoas* value){
        root = avl_insert(root, key, value);
    }

    void nome_inorder(Node<Tkey>* node, string key){
        if(node == nullptr){
            return;
        }
        
        if(nome_(node->key, key.size()) > key){
            nome_inorder(node->left, key);
        }else if(nome_(node->key, key.size()) == key){
            avl_cout(node);
            nome_inorder(node->left, key);
            nome_inorder(node->right, key);
        }else{
            nome_inorder(node->right, key);
        }
    }

    void avl_inorder(Node<Tkey>* root){
        if(root == nullptr){
            return;
        }

        avl_inorder(root->left);
        cout << root->key << endl;
        avl_inorder(root->right);
    }

    Node<Tkey>* avlSearch(Tkey key){
        return avl_searchCPF(root, key);
    }
};

#endif