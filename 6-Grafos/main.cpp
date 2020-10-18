#include <iostream>
#include <vector>
#include <queue>
#include "graph.h"
#include "graphm.h"

using namespace std;

int melhor_caso(Graph *grafo){
	list<int> *irao = new list<int>();

	for (int i = 0; i < grafo->n(); i++){
		if (grafo->neighbors(i).empty()){
			irao->push_back(i);
		}
	}

	for (int i = 0; i < grafo->n(); i++){
		if (grafo->getMark(i) != 5 && !grafo->neighbors(i).empty()){
			list<int> vizinhos = grafo->neighbors(i);
			for (list<int>::iterator it = vizinhos.begin(); it != vizinhos.end(); ++it){
				for (list<int>::iterator at = irao->begin(); at != irao->end(); ++at){
					if (*it == *at){
						grafo->setMark(i, 5);
					}
				}
			}
			if (grafo->getMark(i) != 5){
				for (list<int>::iterator it = vizinhos.begin(); it != vizinhos.end(); it++){
					grafo->setMark(*it, 5);
				}
				irao->push_back(i);
			}
		}
	}
	
	int resultado = irao->size();
	delete irao;
	return resultado;
}

/* int DFSaux(Graph* grafo, int chefe, bool chefeVai){
	if(grafo->neighbors(chefe).empty() && chefeVai == false){
		return 1;
	}else if(grafo->neighbors(chefe).empty() && chefeVai){
		return 0;
	}else{
		queue<int> subordinados;
		int chefeV = 1;
		int chefeN = 0;

		for(int i = 0; i < grafo->n(); i++){
			if(grafo->isEdge(chefe, i)){
				subordinados.push(i);
			}
		}

		while(!subordinados.empty()){
			int sub = subordinados.front();
			chefeV += DFSaux(grafo, sub, true);
			chefeN += DFSaux(grafo, sub, false);
			subordinados.pop();
		}

		if(chefeV >= chefeN){
			return chefeV;
		}
		
		return chefeN;
	}
}

int DFS(Graph* grafo, int chefe){
	queue<int> subordinados;
	int chefeVai = 1;
	int chefeNvai = 0;

	for(int i = 0; i < grafo->n(); i++){
		if(grafo->isEdge(chefe, i) && chefe != i){
			subordinados.push(i);
		}
	}
	
	while(!subordinados.empty()){
		int sub = subordinados.front();
		chefeVai += DFSaux(grafo, sub, true);
		chefeNvai += DFSaux(grafo, sub, false);
		subordinados.pop();
	}

	if(chefeVai >= chefeNvai){
		return chefeVai;
	}
	
	return chefeNvai;
} */

int main(){
	// criando um grafo de 4 vértices
	Graph *grafo = new GraphM(8);
	vector<string> *nomes = new vector<string>();
	vector<string> funcionario;

	// adicionando as arestas
	/*
		0 = Paulo
		1 = Jackson
		2 = karina
		3 = luiza
		4 = joao
		5 = carlos
		6 = santiago
		7 = pedro
	*/

	grafo->addEdge(0,0);
	grafo->addEdge(0,1);
	grafo->addEdge(0,3);
	grafo->addEdge(1,2);
	grafo->addEdge(1,4);
	grafo->addEdge(3,5);
	grafo->addEdge(4,6);
	grafo->addEdge(4,7);

	/* grafo->addEdge(0, 0);
	grafo->addEdge(0, 2);
	grafo->addEdge(2, 1);
	grafo->addEdge(2, 3);
	grafo->addEdge(3, 4);
	grafo->addEdge(4, 5);
	grafo->addEdge(3, 6);
	grafo->addEdge(6, 11);
	grafo->addEdge(11, 12);
	grafo->addEdge(6, 13);
	grafo->addEdge(13, 14);
	grafo->addEdge(6, 15);
	grafo->addEdge(15, 16);
	grafo->addEdge(6, 17);
	grafo->addEdge(17, 18);
	grafo->addEdge(17, 19);
	grafo->addEdge(6, 7);
	grafo->addEdge(7, 8);
	grafo->addEdge(8, 9);
	grafo->addEdge(7, 10); */

	/* dfsResult result = DFS(0, grafo); */
	//cout << melhor_caso(grafo) << endl;
	cout << melhor_caso(grafo) << endl;

	/* if (result.aux1 >= result.aux2)
	{
		cout << result.aux1 << endl;
	}
	else
	{
		cout << result.aux2 << endl;
	} */
	grafo->~Graph();

	return 0;
}