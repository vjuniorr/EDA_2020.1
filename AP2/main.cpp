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

    myfile.open("data.csv");
    getline(myfile, line);
    
    while(myfile.good()){
        pessoa = new Pessoas();
        getline(myfile, line);
   
        pessoa->set_pessoa(line);
        //cout << pessoa->cpf << endl;
        cpf->avlInsert(pessoa->cpf, pessoa);
        nomes->avlInsert(pessoa->nome, pessoa);
        //cpf->avl_inorder(cpf->GetRoot());
        /* cout << pessoa->cpf << ",";
        cout << pessoa->nome << ",";
        cout << pessoa->sobrenome << ",";
        cout << pessoa->data.tm_mon << "/";
        cout << pessoa->data.tm_mday << "/";
        cout << pessoa->data.tm_year << endl; */
    }
    //cpf->avl_inorder(cpf->GetRoot());
    
    nomes->avl_searchName("M");
    /* for(int i = 0; i < nomes->vec.size(); i++){
        pessoa = aux->value[i];
        cout << pessoa->cpf << ",";
        cout << pessoa->nome << ",";
        cout << pessoa->sobrenome << ",";
        cout << pessoa->data.tm_mon << "/";
        cout << pessoa->data.tm_mday << "/";
        cout << pessoa->data.tm_year << ",";
        cout << pessoa->cidade << endl;
    } */
    
} 

#endif