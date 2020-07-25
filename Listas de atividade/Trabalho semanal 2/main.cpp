#include <bits/stdc++.h>
#include "avl.h"
#include "item.h"

using namespace std;

int main(){
    Node* root = nullptr;
    int op = 0;

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
        cout << "8. Sair";
        
        cin >> op;
    }
    
}