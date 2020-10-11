#include <iostream>
#include "graph.h"
#include "graphm.h"
using namespace std;

int main()
{
	// Creating a path with 8 vertices 
	int N = 8;
	Graph *grafo;
	grafo = new GraphM( N );

	// Adding edges
	for(int i = 0; i <= N-2; ++i) {
		grafo->addEdge(i, i+1);
		grafo->addEdge(i+1, i);
	}
	
	// Printing the neighbours of each vertex
	for(int i = 0; i <= N-1; ++i) {
		cout << "Vizinhos do " << i << ": ";
		for( int vizinho : grafo->neighbors(i) ) {
			cout << vizinho << " ";
		}
		cout << endl;
	}

	return 0;
}