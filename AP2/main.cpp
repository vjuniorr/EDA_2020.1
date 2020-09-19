#include <bits/stdc++.h>
#include <time.h>
#include "pessoa.h"

using namespace std;

/* long int filter_cpf(string cpf){
   string out;
   for(int i = 0; i < cpf.size(); i++){
       if(cpf[i] != '.' && cpf[i] != '-'){
           out += cpf[i];
       }
   }
   return stol(out); 
} */

int main (){
    ifstream myfile;
    string line;
    string cpf;
    struct tm data;
    pessoas* pessoa = new pessoas[500];

    myfile.open("data.csv");
    getline(myfile, line);

    //int cont = 0;
    /* getline(myfile, line, ',');

    cpf = line;

    getline(myfile, line, ',');
    getline(myfile, line, ',');
    getline(myfile, line, '/');
    data.tm_mon = stoi(line);
    getline(myfile, line, '/');
    data.tm_mday = stoi(line);
    getline(myfile, line, ',');
    data.tm_year = stoi(line);


    cout << cpf << endl;

    cout << data.tm_mday << endl;
    cout << data.tm_mon << endl;
    cout << data.tm_year << endl;
*/

    while(myfile.good()){
        getline(myfile, line, ',');
        pessoa->cpf = line;
        getline(myfile, line, ',');
    }
} 