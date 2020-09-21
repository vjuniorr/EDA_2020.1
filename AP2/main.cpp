#include <bits/stdc++.h>
#include "pessoa.h"
#include "avl.h"

using namespace std;

int main (){
    ifstream myfile;
    string line;
    pessoas* pessoa; // Objeto pessoa
    avl<string, pessoas*>* cpf = new avl<string, pessoas*>();
    avl<string, pessoas[]>* nomes = new avl<string, pessoas[]>();

    myfile.open("data.csv"); // Abrindo o arquivo para fazer a leitura
    getline(myfile, line); // Pegando a primeira linha do arquivo (NationalID, GivenName....)

    while(myfile.good()){ // Lendo todas as linhas do arquivo e colocando os dados nos objetos
        pessoa = new pessoas();
        
        getline(myfile, line);
        
        getline(myfile, line, ',');
        pessoa->cpf = line;
        getline(myfile, line, ',');
        pessoa->nome = line;
        getline(myfile, line, ',');
        pessoa->sobrenome = line;
        getline(myfile, line, '/');
        pessoa->data.tm_mon = stoi(line);
        getline(myfile, line, '/');
        pessoa->data.tm_mday = stoi(line);
        getline(myfile, line, ',');
        pessoa->data.tm_year = stoi(line);
        getline(myfile, line, ';');
        pessoa->cidade = line;
        
        //vec.push_back(pessoa);
    }

    /* for(auto const& i : list){
        cout << i->cpf << ", ";
        cout << i->nome << ", ";
        cout << i->sobrenome << ", ";
        cout << i->data.tm_mon<< "/";
        cout << i->data.tm_mday<< "/";
        cout << i->data.tm_year<< ", ";
        cout << i->cidade << endl;
    } */  

    //cout << line << endl;
} 