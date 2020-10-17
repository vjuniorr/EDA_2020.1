#include <iostream>
#include "mgraph.h"
#include "Mgraph.h"
#include <fstream>
#include <sstream>

using namespace std;

// Francisco Valdemi Leal Costa Junior - 485325
// Roberto de Oliveira Coutinho - 499484

void trataDado(string dados, Graph *grafo);

int main(){
    Graph *grafo;
    fstream myfile;
    string line;
    myfile.open("grafos.txt");
    
    //loop que manda as linhas do csv para a função trataDado
    getline(myfile, line);
    int n = stoi(line);
    grafo = new MGraph(n);
    
    while (myfile.good()){
        getline(myfile, line);
        if (line != "") { //comparação pode ser removida se o csv não tiver linha vazia
            if (line != "0 0"){
                trataDado(line, grafo);
            }
            else{
                grafo->isBipartite();
                grafo->~Graph();
                getline(myfile, line);
                int n = stoi(line);
                if (n != 0){
                    grafo = new MGraph(n);
                }
                else{
                    getline(myfile, line);
                }
            }
        }
    }
    return 0;
}

void trataDado(string dados, Graph *grafo){

    int n1, n2;
    std::stringstream aux;
    aux << dados;
    getline(aux, dados, ' ');
    n1 = stoi(dados);
    getline(aux, dados, '\n');
    n2 = stoi(dados);
    //cout << n1 << " " << n2 << endl;
    grafo->addEdge(n1, n2);
    grafo->addEdge(n2, n1);
}