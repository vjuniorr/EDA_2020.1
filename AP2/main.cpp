#ifndef MAIN
#define MAIN

#include <bits/stdc++.h>
#include "node.h"
#include "pessoa.h"
#include "avl.h"

using namespace std;

int main (){
    ifstream myfile;
    string line;
    Pessoas* pessoa; // Objeto pessoa
    avl<string>* cpf = new avl<string>();
    avl<string>* nomes = new avl<string>();
    Node<string>* aux; 
    int cont = 0;
    vector<Pessoas*> vec;

    myfile.open("data.csv"); // Abrindo o arquivo para fazer a leitura
     // Pegando a primeira linha do arquivo (NationalID, GivenName....)

    while(myfile.good()){ // Lendo todas as linhas do arquivo e colocando os dados nos objetos
        pessoa = new Pessoas();
        cont++;
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
        
        cpf->avlInsert(pessoa->cpf, pessoa);
        //cout << cont << endl;
        vec.push_back(pessoa);
    }

    /* cpf->avl_inorder(cpf->GetRoot());
    aux = cpf->avlSearch("187.599.824-11");

    for(int i = 0; i < aux->value.size(); i++){
        cout << aux->value[i]->cpf << endl;
        cout << aux->value[i]->nome << endl;
        cout << aux->value[i]->sobrenome << endl;
        cout << aux->value[i]->data.tm_mday << "/" << aux->value[i]->data.tm_mon << "/" << aux->value[i]->data.tm_year << endl;
    } */

    for(auto const& i : vec){
        cout << i->cpf << ", ";
        cout << i->nome << ", ";
        cout << i->sobrenome << ", ";
        cout << i->data.tm_mon<< "/";
        cout << i->data.tm_mday<< "/";
        cout << i->data.tm_year<< ", ";
        cout << i->cidade << endl;
    }   

    //cout << line << endl;
} 

#endif