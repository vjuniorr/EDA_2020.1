#ifndef mgrapf_h
#define mgrapf_h
#include <stdexcept>
#include <list>
#include "mgraph.h"


using namespace std;

/**
 * Class MGraph : implementação de um grafo com matriz
*/

class MGraph : public Graph{
private:
    int N; // Vertices
    int M; // Arestas
    int** matrix; // Matriz
    int* mark; // Caso marque um vertice

    void checkVertex(int v){
        if(v < 0 || v > N-1){
            throw runtime_error("Intervalo de valor de vertice invalido");
        }
    }

public:
    // Construtor
    MGraph(int n){
        if(n <= 0){
            throw runtime_error("Tamanho Invalido");
        }
        N = n;
        M = 0;
        mark = new int[n];
        matrix = new int*[n];
        for(int i = 0; i <= n-1; i++){
            matrix[i] = new int[n];
        }

        for(int i = 0; i <= n-1; i++){
            for(int j = 0; j <= n-1; j++){
                matrix[i][j] = 0;
            }
        }
    } 

    // Destrutor
    ~MGraph(){
        delete[] mark;
        for(int i = 0; i < N; i++){
            delete[] matrix[i];
        }
        delete matrix;
    }

    // Retorna o numero de vertices e arestas da matriz
    int n(){
        return N;
    }
    int m(){
        return M;
    }

    // Retorna a lista de vizinhos de um vertice
    list<int>& neighbors(int v){
        list<int>* lis = new list<int>();
        for(int i = 0; i < N; i++){
            if(matrix[v][i] != 0){
                lis->push_back(i);
            }
        }
        return *lis;
    } 

    // Setando o peso de uma aresta
    void setEdgeWeight(int v1, int v2, int wgt){
        if(wgt < 0){
            throw runtime_error("Peso negativo");
        }
        if(!isEdge(v1, v2)){
            ++M;
        }
        matrix[v1][v2] = wgt;
    }

    // Adicionando uma nova aresta entre os vertices
    void addEdge(int v1, int v2){
        setEdgeWeight(v1, v2, 1);
    }

    // Deletando a aresta entre os vertices
    void delEdge(int v1, int v2){
        if(isEdge(v1, v2)){
            M--;
            matrix[v1][v2] = 0;
        }
    }

    // Determine if an edge is in the graph
    bool isEdge(int v1, int v2){
        return (matrix[v1][v2] > 0);
    }
    
    // Retorna o peso de uma aresta e 0 caso não exista essa aresta
    int weight(int v1, int v2){
        if(isEdge(v1, v2)){
            return matrix[v1][v2];
        }else{
            return 0;
        }
    }

    // Retorna a marca de um vertice 
    int getMark(int v){
        return mark[v];
    }
    
    // Setando a marca de um vertice 
    void setMark(int v, int value){
        checkVertex(v);
        mark[v] = value;
    }

    // Retorna a lista de arestas que chegam naquele vertice
    list<Edge>& incidentEdges(int v){
        list<Edge>* lis = new list<Edge>();
        for(int i = 0; i < N; i++){
            if(matrix[v][i] != 0){
                lis->push_back( Edge(i, matrix [v][i]));
            }
        }
        return *lis;
    }

};

#endif 