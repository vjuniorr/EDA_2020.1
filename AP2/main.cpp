#ifndef MAIN
#define MAIN

#include <bits/stdc++.h>
#include "node.h"
#include "pessoa.h"
#include "avl.h"

using namespace std;

int make_int(Pessoas* pessoa){
    string str = to_string(pessoa->data.tm_year);

    if(pessoa->data.tm_mon < 10){
        str += "0";
        str += to_string(pessoa->data.tm_mon);
    }else{
        str += to_string(pessoa->data.tm_mon);
    }
    if(pessoa->data.tm_mday < 10){
        str += "0";
        str += to_string(pessoa->data.tm_mday);
    }else{
        str += to_string(pessoa->data.tm_mday);
    }

    return stoi(str);
}


int main (){
    ifstream myfile;
    string line;
    Pessoas* pessoa; // Objeto pessoa
    avl<string>* cpf = new avl<string>();
    avl<string>* nomes = new avl<string>();
    avl<int>* datas = new avl<int>(); 

    myfile.open("data.csv");
    getline(myfile, line);
    
    while(myfile.good()){
        pessoa = new Pessoas();
        getline(myfile, line);
   
        pessoa->set_pessoa(line);
        //cout << pessoa->cpf << endl;
        cpf->avlInsert(pessoa->cpf, pessoa);
        nomes->avlInsert(pessoa->nome, pessoa);
        datas->avlInsert(make_int(pessoa), pessoa);
        //cpf->avl_inorder(cpf->GetRoot());
        /* cout << pessoa->cpf << ",";
        cout << pessoa->nome << ",";
        cout << pessoa->sobrenome << ",";
        cout << pessoa->data.tm_mon << "/";
        cout << pessoa->data.tm_mday << "/";
        cout << pessoa->data.tm_year << endl;*/ 
    }
    //cpf->avl_inorder(cpf->GetRoot());
    
    nomes->avlSearch_nome("Ma");
    //datas->data(19840222, 20000802);
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

    cpf->~avl();
    nomes->~avl();
    datas->~avl();

} 

#endif