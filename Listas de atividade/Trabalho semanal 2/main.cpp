#include <bits/stdc++.h>
#include "avl.h"
#include "item.h"

using namespace std;

int main(){
    Node* root = nullptr;
    Tkey key = "";
    Tvalue value = "";
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
            op = 8;
            break;    
        default:
            cout << "Opcao invalida" << endl;

            op = 0;
            break;
        }
    }
    
}