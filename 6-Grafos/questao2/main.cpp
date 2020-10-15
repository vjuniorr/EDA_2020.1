#include <iostream>
#include "mgraph.h"
#include "Mgraph.h"
#define BLACK 3
#define RED 4

using namespace std;

void DFS_VISIT(Graph *G, int v, int *d, int *f, int &tempo)
{
    tempo++;
    d[v] = tempo;
    G->setMark(v, RED);
    cout << " Vertex " << v << " visited " << endl;
    for (int &w : G->neighbors(v))
        if (G->getMark(w) == BLACK)
            DFS_VISIT(G, w, d, f, tempo);
    G->setMark(v, RED);
    tempo++;
    f[v] = tempo;
}

void DFS(Graph *G){

    for (int v = 0; v < G->n(); v++){
        if (G->getMark(v) != RED && G->getMark(v) != BLACK)  {
            G->setMark(v, RED);
        }
        for (int j : G->neighbors(v)){
            for (int z = 0; z < G->n(); z++){
                if (G->getMark(j) != RED && G->getMark(j) != BLACK){
                    if (j == z){
                        if (G->getMark(v) == RED){
                            G->setMark(z, BLACK);
                        }
                        else{
                            G->setMark(z, RED);
                        }
                    }
                }
            }
        }
    }

}

bool verifica(Graph *G){
    bool ver = true;

    for (int i = 0; i < G->n(); i++){
        if(!G->neighbors(i).empty()){
            for (int vizinhos : G->neighbors(i)){
            if (G->getMark(i) == G->getMark(vizinhos)){
                ver = false;
                return ver;
            }
        }
        }
    }

    return ver;
}

int main(){
    int N = 11;
    Graph *grafo;
    grafo = new MGraph(N);

    /* grafo->addEdge(0, 3);
    grafo->addEdge(0, 4);
    grafo->addEdge(0, 5);
    grafo->addEdge(1, 3);
    grafo->addEdge(1, 4);
    grafo->addEdge(1, 5);
    grafo->addEdge(2, 3);
    grafo->addEdge(2, 4);
    grafo->addEdge(2, 5); */

    /* grafo->addEdge(0,1);
    grafo->addEdge(1,2);
    grafo->addEdge(2,3);
    grafo->addEdge(0,3);
    grafo->addEdge(1,3);
    grafo->addEdge(0,2); */

    grafo->addEdge(0,1);
    grafo->addEdge(2,4);
    grafo->addEdge(1,3);
    grafo->addEdge(3,4);
    grafo->addEdge(2,5);
    grafo->addEdge(5,6);
    grafo->addEdge(6,7);
    grafo->addEdge(7,8);
    grafo->addEdge(8,9);
    grafo->addEdge(9,0);
    
    
    /* grafo->addEdge(0,1);
    grafo->addEdge(0,2);
    grafo->addEdge(0,3);
    grafo->addEdge(1,4);
    grafo->addEdge(1,5);
    grafo->addEdge(2,6);
    grafo->addEdge(2,7);
    grafo->addEdge(3,8);
    grafo->addEdge(3,9);
    grafo->addEdge(4,6);
    grafo->addEdge(4,8);
    grafo->addEdge(5,7);
    grafo->addEdge(5,9);
    grafo->addEdge(6,9);
    grafo->addEdge(7,8); */

    /* for(int i = 0; i < N-1; ++i) {
		grafo->addEdge(i, i+1);
		grafo->addEdge(i+1, i);
	} */

    DFS(grafo);

    if (verifica(grafo)){
        cout << "SIM" << endl;
        for (int i = 0; i < N; i++){
            cout << "Vertex " << i << ":";
            if (grafo->getMark(i) == 3){
                cout << "B";
            }
            else{
                cout << "R";
            }
            cout << endl;
        }
    }else{
        cout << "NAO" << endl;
    }

    grafo->~Graph();
    return 0;
}