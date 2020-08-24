#include <bits/stdc++.h>
#include "RBTree.h"

using namespace std;

//Construtor

RBTree::RBTree(){
    nil = new Node{};
    nil->key = 0;
    nil->left = nil->right = nil->parent = nil;
    nil->color = BLACK;
    root = nil;
}

//Destrutor

RBTree::~RBTree(){
    clear(root);
    delete nil;
    nil = nullptr;
    root = nullptr;
}

//Função que printa em pre-ordem

void RBTree::preorder(){
    Node *tree = root;
    stack<Node *> pilha;
    
    if (tree != nil){
        pilha.push(tree);
        while (!pilha.empty()){
            tree = pilha.top();
            pilha.pop();
            if (tree->color == BLACK){
                cout << "(" << tree->key << "," << tree->value << ") -> Black" << endl;
            }
            else{
                cout << "(" << tree->key << "," << tree->value << ") -> Red" << endl;
            }
            if (tree->right != nil){
                pilha.push(tree->right);
            }
            if (tree->left != nil){
                pilha.push(tree->left);
            }
        }
    }
}

//Função que busca um no por sua key 

bool RBTree::search(const Tkey &key){
    Node* aux = root;

    while(aux != nil){
        if(aux == nil){
            return false;
        }else if( aux->key == key){
            cout << "A key: " << aux->key << " possui o value: " << aux->value << endl;
            return true;
        }else if(aux->key > key){
            aux = aux->left;
        }else if(aux->key < key){
            aux = aux->right;
        }
    }

    return false;
}

//Função que retorna a altura da arvore

int RBTree::height(){
    Node* aux = root;
    queue<Node*> fila;
    int height = 0;

    if(aux == nil){
        return 0;
    }
    
    fila.push(aux);

    while(true){
        int cont = fila.size();
        if(cont == 0){
            return height;
        }
        height++;

        while(cont > 0){
            Node* node = fila.front();
            fila.pop();
            if(node->left != nil){
                fila.push(node->left);
            }
            if(node->right != nil){
                fila.push(node->right);
            }
            cont--;
        }
    }

}

//Função para verificar se a arvore está ou não vazia

bool RBTree::empty(){
    if (root == nil){
        return true;
    }
    return false;
}

//Função visivel ao menu para chamar a clear e fazer a limpeza da arvore

void RBTree::clearM(){
    clear(root);
    return;
}

//Função responsavel por fazer a limpeza da arvore

void RBTree::clear(Node *root){
    Node *aux = root;
    stack<Node *> nodes;

    if (aux != nil){
        nodes.push(aux);
    }
    while (!nodes.empty()){
        Node *node = nodes.top();
        if (node->right != nil){
            nodes.push(node->right);
        }
        if (node->left != nil){
            nodes.push(node->left);
        }
        if (node->left == nil && node->right == nil){
            RBdelete(node);
            nodes.pop();
        }
    }
}

//Função responsavel por realizar a rotação a esquerda para balancear a arvore

void RBTree::left_rotate(Node *node){
    Node *aux = node->right;
    node->right = aux->left;

    if (aux->left != nil){
        aux->left->parent = node;
    }
    aux->parent = node->parent;
    if (node->parent == nil){
        root = aux;
    }
    else if (node == node->parent->left){
        node->parent->left = aux;
    }
    else{
        node->parent->right = aux;
    }

    aux->left = node;
    node->parent = aux;
}

//Função responsavel por realizar a rotação a direita para balancear a arvore

void RBTree::right_rotate(Node *node){
    Node *aux = node->left;
    node->left = aux->right;

    if (aux->right != nil){
        aux->right->parent = node;
    }
    aux->parent = node->parent;
    if (node->parent == nil){
        root = aux;
    }
    else if (node == node->parent->right){
        node->parent->right = aux;
    }
    else{
        node->parent->left = aux;
    }

    aux->right = node;
    node->parent = aux;
}

//Função que vai criar o novo nó com a key e value passados

void RBTree::insert(const Tkey &key, const Tvalue &v){
    Node *novo = new Node{};
    novo->key = key;
    novo->value = v;
    novo->left = novo->right = nil;
    novo->parent = nil;

    RBinsert(novo);
}

//Função que vai buscar a posição na arvore onde o nó vai ser inserido

void RBTree::RBinsert(Node *node){
    Node *father = nil;
    Node *son = root;

    while (son != nil){
        father = son;

        if (node->key == son->key){
            delete node;
            return;
        }
        if (node->key < son->key){
            son = son->left;
        }
        else{
            son = son->right;
        }
    }
    node->parent = father;
    if (father == nil){
        root = node;
    }
    else if (node->key < father->key){
        father->left = node;
    }
    else{
        father->right = node;
    }
    node->left = node->right = nil;
    node->color = RED;

    RBinsert_fixUp(node);
}

//Função que vai procurar o nó a ser deletado

void RBTree::remove(const Tkey &key){
    Node *aux = root;

    while (aux != nil && aux->key != key){
        if (aux->key > key){
            aux = aux->left;
        }
        else{
            aux = aux->right;
        }
    }

    if (aux != nil){
        RBdelete(aux);
    }
    cout << "A key passada nao esta na arvore" << endl;
}

// Função que vai deletar o no minimo da sub-arvore a direita e antes copia sua key e value no nó

void RBTree::RBdelete(Node *z){
    Node *y; // No que será removido
    Node *x; // No que vai tomar seu lugar

    if (z->left == nil || z->right == nil)
        y = z;
    else
        y = minimum(z->right);
    if (y->left != nil)
        x = y->left;
    else
        x = y->right;

    x->parent = y->parent;

    if (y->parent == nil){
        root = x;
    }
    else{
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    }
    if (y != z){
        z->key = y->key;
        z->value = y->value;
    }
    if (y->color == BLACK){
        RBdelete_fixUp(x);
    }
    delete y;
}

//Função que retorna o minimo da Redblack

Node *RBTree::minimum(Node *node){
    while (node->left != nil){
        node = node->left;
    }
    return node;
}

//Função que vai organizar as cores dos nós e o balanço da arvore após a inserção

void RBTree::RBinsert_fixUp(Node *z){
    while (z->parent->color == RED){
        if (z->parent == z->parent->parent->left){
            Node *uncle = z->parent->parent->right;
            if (uncle->color == RED){
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{
                if (z == z->parent->right){
                    z = z->parent;
                    left_rotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(z->parent->parent);
            }
        }
        else{
            Node *uncle = z->parent->parent->left;
            if (uncle->color == RED){
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{
                if (z == z->parent->left){
                    z = z->parent;
                    right_rotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(z->parent->parent);
            }
        }
    }

    root->color = BLACK;
}

//Função que vai organizar as cores dos nós e o balanço da arvore após a remoção

void RBTree::RBdelete_fixUp(Node *x){
    while (x != root && x->color == BLACK){
        if (x == x->parent->left){
            Node *w = x->parent->right;
            if (w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x = x->parent;
            }
            else{
                if (w->right->color == BLACK){
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(x->parent);
                x = root;
            }
        }
        else{
            Node *w = x->parent->left;
            if (w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(x->parent);
                w = x->parent->left;
            }
            if (w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x = x->parent;
            }
            else{
                if (w->left->color == BLACK){
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                right_rotate(x->parent);
                x = root;
            }
        }
    }

    x->color = BLACK;
}

// Função menu da RedBlack

void menu(){
    RBTree tree = RBTree();
    Tkey key;
    Tvalue value = "";
    int op = 0; // Opção do usuario
    system("clear");

    while (op != 7){
        cout << "--------------------------" << endl;
        cout << "Menu da arvore rubro-negra" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Inserir na arvore" << endl;
        cout << "2. Remover um elemento da arvore baseado na chave" << endl;
        cout << "3. Limpar arvore rubro negra" << endl;
        cout << "4. Exibir a arvore em pre-ordem" << endl;
        cout << "5. Pesquisar uma chave" << endl;
        cout << "6. Calcular a altura da arvore" << endl;
        cout << "7. Sair" << endl;
        cout << "Digite sua opção:";
        cin >> op;

        switch (op){
        case 1:
            cout << "Digite a chave(Inteiro) do elemento que vai ser inserido:";
            cin >> key;
            cout << "Digite o valor(String/Char) do elemento que vai ser inserido:";
            cin >> value;

            tree.insert(key, value);
            system("clear");
            cout << "Elemento inserido com sucesso" << endl;
            break;
        case 2:
            Tkey auxx;
            cout << "Digite a chave(Inteiro) do elemento que vai ser removido:";
            cin >> auxx;

            tree.remove(auxx);
            system("clear");
            break;
        case 3:
            tree.clearM();
            system("clear");
            cout << "Arvore limpa com sucesso" << endl;
            break;
        case 4:
            if (!tree.empty()){
                system("clear");
                tree.preorder();
            }else{
                system("clear");
                cout << "Sua arvore esta vazia" << endl;
            }
            break;
        case 5:
            Tkey aux;
            cout << "Digite a chave do elemento que procura:";
            cin >> aux;
            system("clear");
            tree.search(aux);
            break;
        case 6:
            system("clear");
            cout << "Altura da arvore e: " << tree.height() << endl;
            break;
        case 7:
            tree.~RBTree();
            break;
        default:
            cout << "Opcao invalida" << endl;

            op = 0;
            break;
        }
    }
    return;
}