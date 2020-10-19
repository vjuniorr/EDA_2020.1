#ifndef Mgraph_h
#define Mgraph_h
#include <stdexcept>
#include <list>
#include <queue>

using namespace std;

// Francisco Valdemi Leal Costa Junior - 485325
// Roberto de Oliveira Coutinho - 499484

class MGraph : public Graph{
private:
    int N;        // Vertices
    int M;        // Arestas
    int **matrix; // Matriz
    int *mark;    // Caso marque um vertice

    void checkVertex(int v){
        if (v < 0 || v > N - 1){
            throw runtime_error("Intervalo de valor de vertice invalido");
        }
    }

public:
    // Construtor
    MGraph(int n){
        if (n <= 0){
            throw runtime_error("Tamanho Invalido");
        }
        N = n;
        M = 0;
        mark = new int[n];
        matrix = new int *[n];
        for (int i = 0; i <= n - 1; i++){
            matrix[i] = new int[n];
        }

        for (int i = 0; i <= n - 1; i++){
            for (int j = 0; j <= n - 1; j++){
                matrix[i][j] = 0;
            }
        }
    }

    // Destrutor
    ~MGraph(){
        delete[] mark;
        for (int i = 0; i < N; i++){
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
    list<int> &neighbors(int v){
        list<int> *lis = new list<int>();
        for (int i = 0; i < N; i++){
            if (matrix[v][i] != 0){
                lis->push_back(i);
            }
        }
        return *lis;
    }

    // Setando o peso de uma aresta
    void setEdgeWeight(int v1, int v2, int wgt){
        if (wgt < 0){
            throw runtime_error("Peso negativo");
        }
        if (!isEdge(v1, v2)){
            ++M;
        }
        matrix[v1][v2] = wgt;
        matrix[v2][v1] = wgt;
    }

    // Adicionando uma nova aresta entre os vertices
    void addEdge(int v1, int v2){
        setEdgeWeight(v1, v2, 1);
    }

    // Deletando a aresta entre os vertices
    void delEdge(int v1, int v2){
        if (isEdge(v1, v2)){
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
        if (isEdge(v1, v2)){
            return matrix[v1][v2];
        }
        else{
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
    list<Edge> &incidentEdges(int v){
        list<Edge> *lis = new list<Edge>();
        for (int i = 0; i < N; i++){
            if (matrix[v][i] != 0){
                lis->push_back(Edge(i, matrix[v][i]));
            }
        }
        return *lis;
    }

    // Função que vai me dizer se o meu grafo é bipartido ou não
    bool isBipartite(){
        // Crinando um array de tamanho N e preenchendo com -1 todos os espaços
        int color[N];
        for (int i = 0; i < N; ++i){
            color[i] = -1;
        }
        
        // Percorrendo o meu array e passando ele para verificar as cores dos vizinhos de i
        // Se isBipartite() retornar false meu grafo não é bipartido então printo NAO na tela
        for (int i = 0; i < N; i++){
            if (color[i] == -1){
                if (colorindo(i, color) == false){
                    cout << "NAO" << endl;
                    return false;
                }
            }
        }

        // Se ele percorreu tudo sem retornar então meu grafo é bipartido
        // Eu printo SIM e caso o vertice i possua 1 no meu array sua cor é RED, caso contrario é BLACK
        cout << "SIM" << endl;
        for (int i = 0; i < N; i++){
            if (color[i] == 1){
                cout << i << " R" << endl;
            }
            else{
                cout << i << " B" << endl;
            }
        }

        return true;
    }

    // Função que vai colorir o vert e seus vizinhos
    bool colorindo(int vert, int color[]){
        // Setando a cor de um vertice que ainda não foi visitado
        color[vert] = 1;
        
        // Criando uma pilha com o vert que foi passado
        queue<int> q;
        q.push(vert);

        // Percorre todos os nós que são vizinhos vert e vizinhos de vizinhos
        // Se um vizinho ainda não tiver uma cor ele seta a cor 
        while (!q.empty()){
            
            int u = q.front();
            q.pop();

            // Se um vertice é vizinho dele mesmo esse grafo não pode ser bipartido
            if (isEdge(u, u)){
                return false;
            }
            
            // Buscando os vertices adjacentes de vert
            for (int v = 0; v < N; ++v){
                // Verificando se u e v são vizinhos e verifica se o meu array na posição v ainda é -1
                // Se for ele marca a posição v no meu array com a cor oposta de u e coloca o v na pilha
                if (isEdge(u, v) && color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }

                // Se u e v são vizinhos e suas cores são iguais o grafo não é bipartido
                else if (isEdge(u, v) && color[v] == color[u]){
                    return false;
                }
            }
        }

        // Coloriu o vert os seus vizinho, e vizinho de vizinhos dele sem dar conflito de cores
        return true;
    }
};

#endif