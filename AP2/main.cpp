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
        //cout << "aqui" << endl;
        pessoa = new Pessoas();
        //cont++;
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
        
        /* cpf->avlInsert(pessoa->cpf, pessoa);
        cout << cont << endl;
        cout << myfile.good() << endl; */
        vec.push_back(pessoa);
    }

    //aux = cpf->avlSearch("187.599.824-11");

    /* for(int i = 0; i < aux->value.size(); i++){
        cpf->avlInsert(vec[i]->cpf, vec[i]);
    } */

    //cpf->avl_inorder(cpf->GetRoot()); 

    for(auto const& i : vec){
        cont++;
        cpf->avlInsert(i->cpf, i);
    }
    cpf->avl_inorder(cpf->GetRoot());   
    cout << cont << endl;
    //cout << line << endl;
} 

#endif