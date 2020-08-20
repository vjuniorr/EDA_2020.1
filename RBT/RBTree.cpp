#include <bits/stdc++.h>
#include "RBTree.h"

using namespace std;

RBTree::RBTree () {
    nil = new Node{};
    nil->key = 0;
    nil->left = nil->right = nil->parent = nil;
    nil->color = BLACK;
    root = nil;
}

RBTree::~RBTree() {
    clear(root);
    delete nil;
    nil = nullptr;
    root = nullptr;
}

void RBTree::preorder() const{
    Node* tree = root;
    stack<Node*> pilha;
    if(tree != nil){
        pilha.push(tree);
        while(!pilha.empty()){
            tree = pilha.top();
            pilha.pop();
            if(tree->color == BLACK){
                cout << "(" << tree->key << "," << tree->value << ") -> Black" << endl;
            }else{
                cout << "(" << tree->key << "," << tree->value << ") -> Red" << endl;
            }
            if(tree->right != nil){
                pilha.push(tree->right);
            }
            if(tree->left != nil){
                pilha.push(tree->left);
            }
        }
    } 
}

void RBTree::clear (Node* node){
    stack<Node*> nodes;
    if(!nodes.empty()){
        nodes.push(node);
    }
    while (!nodes.empty()){
        Node* aux = nodes.top();
        if(aux->right != nil){
            nodes.push(aux->right);
        }
        if(aux->left != nil){
            nodes.push(aux->left);
        }
        if(aux->right == nil && aux->left == nil){
            RBdelete(nodes.top());

        }
    }
}

void RBTree::left_rotate(Node* node){
    Node* aux = node->right; 
    node->right = aux->left;

    if(aux->left != nil){
        aux->left->parent = node;
    }
    aux->parent = node->parent;
    if(node->parent == nil){
        root = aux;
    }else if(node == node->parent->left){
        node->parent->left = aux;
    }else{
        node->parent->right = aux;
    }

    aux->left = node;
    node->parent = aux;
}

void RBTree::right_rotate(Node* node){
    Node* aux = node->left;
    node->left = aux->right;

    if(aux->right != nil){
        aux->right->parent = node;
    }
    aux->parent = node->parent;
    if(node->parent == nil){
        root = aux;
    }else if(node == node->parent->right){
        node->parent->right = aux;
    }else{
        node->parent->left = aux;
    }

    aux->right = node;
    node->parent = aux;
}

void RBTree::insert(const Tkey &key, const Tvalue &v){
    Node* novo = new Node{};
    novo->key = key;
    novo->value = v;
    novo->left = novo->right = nil;
    novo->parent = nil;

    RBinsert(novo);
}

void RBTree::RBinsert(Node* node){
    Node* father = nil;
    Node* son = root;

    while(son != nil){
        father = son;

        if(node->key == son->key){
            delete node;
            return;
        }
        if(node->key < son->key){
            son = son->left;
        }
        son = son->right;
    }
    node->parent = father;
    if(father == nil){
        root = node;
    }else if(node->key < father->key){
        father->left = node;
    }else{
        father->right = node;
    }
    node->left = node->right = nil;
    node->color = RED;

    RBinsert_fixUp(node);
}

void RBTree::remove(const Tkey &key){
    Node* aux = root;
    
    while(aux != nil && aux->key != key){
        if(aux->key > key){
            aux = aux->left;
        }
        aux = aux->right;
    }

    if(aux != nil){
        RBdelete(aux);
    }
}

void RBTree::RBdelete(Node* node){
    Node* rem; // No que será removido
    Node* suc; // No que vai tomar seu lugar

    if(node->left == nil || node->right == nil){
        rem = node;
    }else{
        rem = minimum(node->right);
    }
    if(rem->left != nil){
        suc = rem->left;
    }else{
        suc = rem->right;
    }
    if(suc != nil){
        suc->parent = rem->parent;
    }
    if(rem->parent == nil){
        root = suc;
    }else{
        if(rem == rem->parent->left){
            rem->parent->left = suc;
        }else{
            rem->parent->right = suc;
        }
    }
    if(rem != node){
        node->key = rem->key;
        node->value = rem->value;
    }
    if(rem->color == BLACK){
        RBdelete_fixUp(suc);
    }

    delete rem;
}

Node* RBTree::minimum(Node* node){
    while (node->left != nil){
        node = node->left;
    }
    return node;
}

void RBTree::RBinsert_fixUp(Node* node){
    root->color = BLACK;
    
    while(node->parent->color == RED){
        if(node->parent == node->parent->parent->left){
            Node* aux = node->parent->parent->right;
            if(aux->color == RED){
                node->parent->color = BLACK;
                aux->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }else{
                if(node == node->parent->right){
                    node = node->parent;
                    left_rotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                right_rotate(node->parent->parent);
            }
        }else{
            Node* aux = node->parent->parent->left;
            if(aux->color == RED){
                node->parent->color = BLACK;
                aux->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }else{
                if(node == node->parent->left){
                    node = node->parent;
                    right_rotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                left_rotate(node->parent->parent);
            }
        }
    }
}

void RBTree::RBdelete_fixUp(Node* z){
    z->color = BLACK;

    while (z != root && z->color == BLACK){
        if(z == z->parent->left){
            Node* aux = z->parent->right;
            if(aux->color == RED){
                aux->color = BLACK;
                z->parent->color = RED;
                left_rotate(z->parent);
                aux = z->parent->right;
            }
            if(aux->left->color == BLACK && aux->right->color == BLACK){
                aux->color = RED;
                z = z->parent;
            }else{
                if(aux->right->color == BLACK){
                    aux->left->color = BLACK;
                    aux->color = RED;
                    right_rotate(aux);
                    aux = z->parent->right;
                }
                aux->color = z->parent->color;
                z->parent->color = BLACK;
                aux->right->color = BLACK;
                left_rotate(z->parent);
                z = root;
            }
        }else{
            
        }
    }
    
}