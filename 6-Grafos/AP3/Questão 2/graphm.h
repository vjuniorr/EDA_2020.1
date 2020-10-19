#ifndef graphm_h
#define graphm_h
#include <stdexcept>
#include <list>
#include <vector>
#include <queue>
#include "graph.h"

using namespace std;

// Francisco Valdemi Leal Costa Junior - 485325
// Roberto de Oliveira Coutinho - 499484

/**
 * Class GraphM: implementation of a graph as an adjacency matrix 
 */
class GraphM : public Graph{
private:
    int N;
    int M;
    int **matrix;
    int *mark;

    // Check if a vertex v is valid ( 0 <= v <= N-1 )
    void checkVertex(int v){
        if (v < 0 || v > N - 1)
            throw std::runtime_error("Intervalo de valor de vertice invalido");
    }

public:
    // Constructor
    GraphM(int n){
        if (n <= 0)
            throw std::runtime_error("Tamanho invalido");
        N = n;
        M = 0;
        // Aloccate memory for mark array
        mark = new int[n];
        // Allocate memory for a matrix n x n
        matrix = new int *[n];
        for (int i = 0; i <= n - 1; ++i){
            matrix[i] = new int[n];
        }
        // Initialize matrix with 0's
        for (int i = 0; i <= n - 1; ++i)
            for (int j = 0; j <= n - 1; ++j)
                matrix[i][j] = 0;
    }

    // Destructor
    ~GraphM(){
        delete[] mark;
        for (int i = 0; i < N; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    // Return: the number of vertices and edges respectively
    int n() { return N; }
    int m() { return M; }

    // Return a list containing v's incident edges
    std::list<Edge> &incidentEdges(int v){
        std::list<Edge> *lst = new std::list<Edge>();
        for (int i = 0; i < N; ++i){
            if (matrix[v][i] != 0){
                lst->push_back(Edge(i, matrix[v][i]));
            }
        }
        return *lst;
    }

    // Return a list containing vertex v's neighbors
    std::list<int> &neighbors(int v){
        std::list<int> *lst = new std::list<int>();
        for (int i = 0; i < N; ++i){
            if (matrix[v][i] != 0){
                lst->push_back(i);
            }
        }
        return *lst;
    }

    void setEdgeWeight(int v1, int v2, int wgt){
        if (wgt <= 0)
            throw std::runtime_error("Peso negativo ou igual a zero");
        if (!isEdge(v1, v2))
            ++M;
        matrix[v1][v2] = wgt;
    }

    // Add an edge
    void addEdge(int v1, int v2){
        setEdgeWeight(v1, v2, 1);
    }

    // Delete an edge
    void delEdge(int v1, int v2){
        if (isEdge(v1, v2))
        {
            M--;
            matrix[v1][v2] = 0;
        }
    }

    // Determine if an edge is in the graph
    bool isEdge(int v1, int v2){
        return (matrix[v1][v2] > 0);
    }

    int weight(int v1, int v2){
        checkVertex(v1);
        checkVertex(v2);
        if (isEdge(v1, v2))
            return matrix[v1][v2];
        else
            return 0;
    }

    int getMark(int v){
        checkVertex(v);
        return mark[v];
    }

    void setMark(int v, int value){
        checkVertex(v);
        mark[v] = value;
    }

    int melhor_caso(){
        list<int> *irao = new list<int>(); // Lista de pessoas que vai a festa

        for (int i = 0; i < N; i++){ // Pegando as pessoas que não possuem subordinados
            if (neighbors(i).empty()){
                irao->push_back(i);
            }
        }

        for (int i = 0; i < N; i++){ // Percorrendo a matriz
            if (getMark(i) != 5 && !neighbors(i).empty()){ // Verificando se aquele vertice já está marcado que não vai e se sua lista de vizinhos é vazia
                list<int> vizinhos = neighbors(i); // Lista de subordinados de i
                for (list<int>::iterator it = vizinhos.begin(); it != vizinhos.end(); ++it){
                    for (list<int>::iterator at = irao->begin(); at != irao->end(); ++at){
                        if (*it == *at){ // Se algum subordinado de i está marcado que vai, i é marcado que não vai
                            setMark(i, 5);
                        }
                    }
                }
                if (getMark(i) != 5){ // Se i não está marcado e seus subordinados não estão marcado que vão, ele marca que vai a festa e marca que seus subordinados não vão
                    for (list<int>::iterator it = vizinhos.begin(); it != vizinhos.end(); it++){
                        setMark(*it, 5); // Marcando que os subordinados de i não vão
                    }
                    irao->push_back(i); // Adicionando i a lista de pessoas que vai a festa
                }
            }
        }

        int resultado = irao->size(); // Resultado recebe o tamanho maximo de convidados
        delete irao; // Deletando minha lista 
        return resultado; // Retornando o resultado
    }

    /**
     * Função que tentamos fazer percorrendo todos os vertices do grafo de maneira recursiva
     * (Mais detalhes nas obs na parte solução do relatorio)
     * **/

    /* int DFSaux(int chefe, bool chefeVai){
        if (neighbors(chefe).empty() && chefeVai == false){ // Caso o chefe passado não tenha subordinados e o chefe dele não vai retorno 1
            return 1;
        }
        else if (neighbors(chefe).empty() && chefeVai){ // Caso o chefe passado não tenha subordinados e o chefe dele vai eu retorno 0
            return 0;
        }
        
        queue<int> subordinados; // Cria uma pilha com os subordinados do chefe passado
        int chefeV = 1;
        int chefeN = 0;

        for (int i = 0; i < N; i++){ 
            if (isEdge(chefe, i)){ // Percorro a matriz verificando se i é subordinado do meu chefe e se for eu adiciono a pilha
                subordinados.push(i);
            }
        }

        while (!subordinados.empty()){ // Enquanto minha pilha não estiver vazia
            int sub = subordinados.front(); // Pego o meu primeiro subordinado da pilha
            chefeV += DFSaux(sub, true); // Caso em que o chefe vai
            chefeN += DFSaux(sub, false); // Caso em que o chefe não vai
            subordinados.pop(); // Desempilho aquele subordinado 
        }

        if (chefeV >= chefeN){ // Se o caso em que o chefe vai for maior ou igual que o caso em que o chefe não vai eu retorno que ele vai
            return chefeV;
        }

        return chefeN; // Caso em que o chefe não vai é maior que o caso em que ele vai
        
    }

    int DFS(int chefe){
        queue<int> subordinados; // Crio uma pilha para armazenar os subordinados de i
        int chefeVai = 1;
        int chefeNvai = 0;

        for (int i = 0; i < N; i++){
            if (isEdge(chefe, i) && chefe != i){ // Percorro a matriz verificando se i é subordinado do meu chefe e se for eu adiciono a pilha
                subordinados.push(i);
            }
        }

        while (!subordinados.empty()){ // Enquanto minha pilha não estiver vazia
            int sub = subordinados.front(); // Pego o meu primeiro subordinado da pilha
            chefeVai += DFSaux(sub, true); // Caso em que o chefe vai
            chefeNvai += DFSaux(sub, false); // Caso em que o chefe não vai
            subordinados.pop(); // Desempilho aquele subordinado 
        }

        if (chefeVai >= chefeNvai){ // Se o caso em que o chefe vai for maior ou igual que o caso em que o chefe não vai eu retorno que ele vai
            return chefeVai;
        }

        return chefeNvai; // Caso em que o chefe não vai é maior que o caso em que ele vai
    } */
};

#endif