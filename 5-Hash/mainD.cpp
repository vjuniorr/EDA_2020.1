// Francisco Valdemi Leal Costa Junior - 485325
#include <bits/stdc++.h>
#include "HashingD.h"

using namespace std;

void set_dados(string line, HashTable<string, string>* hash);

int main(){
    HashTable<string, string>* hash = new HashTable<string, string>(1001);
    ifstream myfile;
    string line;
    string key;
    string value;
    int op = 0;

    myfile.open("dados.csv");
    
    while(myfile.good()){// Lendo o arquivo
        getline(myfile, line);
        if(line != ""){
            set_dados(line, hash);
        } 
    }
    
    system("clear");

    while(op != 7){// Menu
        cout << "*************************************************" << endl;
        cout << "* 1 - Buscar um valor                           *" << endl;
        cout << "* 2 - Tamanho da minha tabela                   *" << endl;
        cout << "* 3 - Quantos elementos tem na minha tabela     *" << endl;
        cout << "* 4 - Remover um elemento da tabela             *" << endl;
        cout << "* 5 - Verificar se tem uma chave na tabela      *" << endl;
        cout << "* 6 - Limpar a minha tabela                     *" << endl;
        cout << "* 7 - Sair                                      *" << endl;
        cout << "*************************************************" << endl;
        cin >> op;

        switch (op){
        case 1:
            key = "";
            value = "";
            cout << "Digite a chave do valor:" << endl;
            cin >> key;

            hash->search(key, value);
            system("clear");
            cout << "----------------------------------------------------------------" << endl;
            cout << value << endl;
            cout << "----------------------------------------------------------------" << endl;
            break;
        case 2:
            system("clear");
            cout << "----------------------------------------------------------------" << endl;
            cout << hash->size() << endl;
            cout << "----------------------------------------------------------------" << endl;
            break;
        case 3:
            system("clear");
            cout << "----------------------------------------------------------------" << endl;
            cout << hash->get_current() << endl;
            cout << "----------------------------------------------------------------" << endl;
            break;
        case 4:
            key = "";
            cout << "Digite a chave que vai ser deletada:" << endl;
            cin >> key;
            system("clear");
            if(hash->remove(key)){
                cout << "----------------------------------------------------------------" << endl;
                cout << "Sucesso ao remover o elemento" << endl;
                cout << "----------------------------------------------------------------" << endl;
            }else{
                cout << "----------------------------------------------------------------" << endl;
                cout << "Erro ao excluir a chave passada" << endl;
                cout << "----------------------------------------------------------------" << endl;
            }
            break;
        case 5:
            key = "";
            cout << "Digite a chave que procura:" << endl;
            cin >> key;
            system("clear");
            if(hash->contains(key)){
                cout << "----------------------------------------------------------------" << endl;
                cout << "A chave esta na tabela" << endl;
                cout << "----------------------------------------------------------------" << endl;
            }else{
                cout << "----------------------------------------------------------------" << endl;
                cout << "A chave nao esta na tabela" << endl;
                cout << "----------------------------------------------------------------" << endl;
            }
            break;
        case 6:
            hash->makeEmpty();
            system("clear");
            cout << "----------------------------------------------------------------" << endl;
            cout << "A tabela foi limpa" << endl;
            cout << "----------------------------------------------------------------" << endl;
            break;
        case 7:
            op = 7;
            break;
        default:
            cout << "----------------------------------------------------------------" << endl;
            cout << "Opcao invalida" << endl;
            cout << "----------------------------------------------------------------" << endl;
            break;
        }
    }

}

void set_dados(string line, HashTable<string, string>* hash){
    string key;
    string value;
    stringstream aux;

    aux << line;
    getline(aux, line, ',');
    key = line;
    getline(aux, line, ';');
    value = line;

    if(!hash->insert(key, value)){
        cout << "ERRO" << endl;
    }
}
