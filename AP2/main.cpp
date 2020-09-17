#include <bits/stdc++.h>
//#include "pessoa.h"

using namespace std;

long int filter_cpf(string cpf){
   string out;
   for(int i = 0; i < cpf.size(); i++){
       if(cpf[i] != '.' && cpf[i] != '-'){
           out += cpf[i];
       }
   }
   return stol(out); 
}

int main (){
    ifstream myfile;
    string registro;
    string aux;
    long int cpf;
    //pessoas* pessoa = new pessoas{}

    myfile.open("data.csv");
    getline(myfile, registro);

    //int cont = 0;
    getline(myfile, registro, ',');

    cpf = filter_cpf(registro);
    cout << cpf << endl;
}