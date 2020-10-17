#include <bits/stdc++.h>
#include "grafo_list.h"

using namespace std;

int melhor_caso(Grafo* graph){
	
}


int main(){
	// criando um grafo de 4 vértices
	Grafo grafo(6);
	vector<string>* nomes = new vector<string>();
	
	// adicionando as arestas
	/*
		0 = Paulo
		1 = Jackson
		2 = karina
		3 = luiza
		4 = joao
		5 = carlos
	*/

	grafo.adicionarAresta(0, 0);
    grafo.adicionarAresta(1, 0);
	grafo.adicionarAresta(2, 1);
	grafo.adicionarAresta(3, 0);
	grafo.adicionarAresta(4, 1);
	grafo.adicionarAresta(5, 3);

	// mostrando os graus de saída
	// verifica se existe vizinhos
	/* if(grafo.existeVizinho(0, 1))
		cout << "\n\n1 eh vizinho de 0\n";
	else
		cout << "\n\n1 NAO eh vizinho de 0\n";

	if(grafo.existeVizinho(0, 2))
		cout << "2 eh vizinho de 0\n";
	else
		cout << "2 NAO eh vizinho de 0\n";
 */
	return 0;
}