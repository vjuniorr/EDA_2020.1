#include <iostream>
#include "graph.h"
#include "graphm.h"
#include <list>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Francisco Valdemi Leal Costa Junior - 485325
// Roberto de Oliveira Coutinho - 499484

void trataDado(string dados, Graph *grafo, vector<string> &nomes);

int main(){
	
    Graph *grafo;
    fstream myfile;
    string line;
    myfile.open("grafos.txt");

	// Lendo o arquivo TXT
    while (myfile.good()){
        getline(myfile, line); // Linha que vai me dizer o tamanho do meu grafo
        int n = stoi(line);
        if (n != 0){
            vector<string> nomes;
            grafo = new GraphM(n); // Declarando o tamanho do meu grafo(NxN)
            if (line != ""){ // Caso tenha alguma linha em branco no TXT
                for (int i = 0; i < n; i++){ // Lendo o nome dos funcionarios 
                    getline(myfile, line); // Andando de linha de linha
                    trataDado(line, grafo, nomes); // Função responsavel por tratar a linha do TXT
                }
                int res = grafo->melhor_caso(); // Recebendo o numero maximo de convidados
                cout << res << endl;
                grafo->~Graph(); // Destrutor
            }
        }
    }

    return 0;
}

void trataDado(string dados, Graph *grafo, vector<string> &nomes){

    string p1, p2;
    int i_p1 = -1, i_p2 = -1;
    stringstream aux;
    aux << dados; // Aux recebendo minha linha
    getline(aux, dados, ' '); // Dados vai receber uma string de aux até encontrar ' '
    p1 = dados; // Nome do subordinado
    getline(aux, dados, '\n'); // Dados vai receber uma string de aux até encontrar uma quebra de linha
    p2 = dados; // Nome do chefe

    for (int i = 0; i < nomes.size(); i++){ // Percorre o meu vector para ver se o nome do funcionario já existe
        if (nomes[i] == p1){
            i_p1 = i;
        }
    }
    if (i_p1 == -1){ // Se o valor do i_p1 quer dizer que a pessoa não existe no meu vector, então adiciono
        nomes.push_back(p1);
    }
    for (int i = 0; i < nomes.size(); i++){ // Percorrendo o meu vetor para encontrar os indices das pessoas
        if (nomes[i] == p1){
            i_p1 = i;
        }
        if (nomes[i] == p2){
            i_p2 = i;
        }
    }
    grafo->addEdge(i_p2, i_p1); // i_p2 é chefe de i_p1(Exceto quando eu leio o nome do chefe onde fica marcado na matriz a posição [0][0])
}


/*
Caso em que a função melhor_caso e DFS dão resultados diferentes 
20
Paulo
Pedro Paulo
Guilherme Pedro
Isaias Pedro
Jose Isaias
Lucas Jose
Leo Isaias
Francisco Leo
Peter Francisco
Juca Leo
Douglas Juca
Carlos Leo
Samuel Carlos
Simas Leo
Ian Simas
Antonio Simas
Costa Leo
David Costa
Logan David
Roberto Costa
*/
