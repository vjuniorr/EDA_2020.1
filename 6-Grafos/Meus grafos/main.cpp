#include <iostream>
#include "mgraph.h"
#include "Mgraph.h"

using namespace std;

int main(){
    int N = 8;
    Graph* grafo;
    grafo = new MGraph(N);
    for(int i = 0; i < N-1; i++){
        grafo->addEdge(i,i+1);
        grafo->addEdge(i+1, i);
    }
    for(int i = 0; i < N-1; i++){
        cout << "Vizinho do " << i << ":";
        for(int viz : grafo->neighbors(i)){
            cout << viz << " ";
        }
        cout << endl;
    }
    return 0;
}