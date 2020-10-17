#include <iostream>
#include <vector>
#include "graph.h"
#include "graphm.h"

using namespace std;

int melhor_caso(Graph* grafo){
	list<int>* irao = new list<int>();

	for(int i = 0; i < grafo->n(); i++){
		if(grafo->neighbors(i).empty()){
			irao->push_back(i);
		}
	}

	for(int i = 0; i < grafo->n(); i++){
		if(grafo->getMark(i) != 5 && !grafo->neighbors(i).empty()){
			list<int> vizinhos = grafo->neighbors(i);
			for(list<int>::iterator it = vizinhos.begin(); it != vizinhos.end(); ++it){
				for(list<int>::iterator at = irao->begin(); at != irao->end(); ++at){
					if(*it == *at){
						grafo->setMark(i, 5);
					}
				}
			}
			if(grafo->getMark(i) != 5){
				for(list<int>::iterator it = vizinhos.begin(); it != vizinhos.end(); it++){
					grafo->setMark(*it, 5);
				}
				irao->push_back(i);
			}
		}
	}

	for(list<int>::iterator it = irao->begin(); it != irao->end(); it++){
		cout << *it << endl;
	}
	return irao->size();
}

/* int dfs(int u, int pai, bool posso, Graph* dp){
  if(dp[u][posso] != -1)
    return dp[u][posso];
  int ans1 = 1, ans2 = 0;
  for(int filho: adj[u]){
    if(filho != pai){
      ans1 += dfs(filho, u, false);
      ans2 += dfs(filho, u, true);
    }
  }
  if(posso)
    return dp[u][posso] = max(ans1, ans2);
  else
    return dp[u][posso] = ans2;
} */

int dfs(Graph* grafo, int u, int pai, bool posso){
	int aux[grafo->n()][2];
	if(aux[u][posso] != -1)
    	return aux[u][posso];
  	int ans1 = 1, ans2 = 0;
  	for(int filho: grafo->neighbors(u)){
    	if(filho != pai){
      		ans1 += dfs(grafo,filho, u, false);
      		ans2 += dfs(grafo,filho, u, true);
    	}
  	}
  	if(posso)
    	return aux[u][posso] = max(ans1, ans2);
  	else
    	return aux[u][posso] = ans2;

}

int main(){
	// criando um grafo de 4 vértices
	Graph* grafo = new GraphM(20) ;
	vector<string>* nomes = new vector<string>();

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

	grafo->addEdge(0, 0);
    grafo->addEdge(0, 2);
	grafo->addEdge(2, 1);
	grafo->addEdge(2, 3);
	grafo->addEdge(3, 4);
	grafo->addEdge(4, 5);
	grafo->addEdge(3, 6);
	grafo->addEdge(6, 11);
	grafo->addEdge(11,12);
	grafo->addEdge(6,13);
	grafo->addEdge(13,14);
	grafo->addEdge(6,15);
	grafo->addEdge(15,16);
	grafo->addEdge(6,17);
	grafo->addEdge(17,18);
	grafo->addEdge(17,19);
	grafo->addEdge(6,7);
	grafo->addEdge(7,8);
	grafo->addEdge(8,9);
	grafo->addEdge(7,10);
	
	/* cout << melhor_caso(grafo) << endl; */

	grafo->~Graph();

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