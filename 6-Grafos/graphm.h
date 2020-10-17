#ifndef graphm_h
#define graphm_h
#include <stdexcept>
#include <list>
#include <vector>
#include "graph.h"

/**
 * Class GraphM: implementation of a graph as an adjacency matrix 
 */
class GraphM : public Graph
{
private:
    int N;
    int M;
    int **matrix;
    int *mark;

    // Check if a vertex v is valid ( 0 <= v <= N-1 )
    void checkVertex(int v)
    {
        if (v < 0 || v > N - 1)
            throw std::runtime_error("Intervalo de valor de vertice invalido");
    }

public:
    // Constructor
    GraphM(int n)
    {
        if (n <= 0)
            throw std::runtime_error("Tamanho invalido");
        N = n;
        M = 0;
        // Aloccate memory for mark array
        mark = new int[n];
        // Allocate memory for a matrix n x n
        matrix = new int *[n];
        for (int i = 0; i <= n - 1; ++i)
        {
            matrix[i] = new int[n];
        }
        // Initialize matrix with 0's
        for (int i = 0; i <= n - 1; ++i)
            for (int j = 0; j <= n - 1; ++j)
                matrix[i][j] = 0;
    }

    // Destructor
    ~GraphM()
    {
        delete[] mark;
        for (int i = 0; i < N; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    // Return: the number of vertices and edges respectively
    int n() { return N; }
    int m() { return M; }

    // Return a list containing v's incident edges
    std::list<Edge> &incidentEdges(int v)
    {
        std::list<Edge> *lst = new std::list<Edge>();
        for (int i = 0; i < N; ++i)
        {
            if (matrix[v][i] != 0)
            {
                lst->push_back(Edge(i, matrix[v][i]));
            }
        }
        return *lst;
    }

    // Return a list containing vertex v's neighbors
    std::list<int> &neighbors(int v)
    {
        std::list<int> *lst = new std::list<int>();
        for (int i = 0; i < N; ++i)
        {
            if (matrix[v][i] != 0)
            {
                lst->push_back(i);
            }
        }
        return *lst;
    }

    void setEdgeWeight(int v1, int v2, int wgt)
    {
        if (wgt <= 0)
            throw std::runtime_error("Peso negativo ou igual a zero");
        if (!isEdge(v1, v2))
            ++M;
        matrix[v1][v2] = wgt;
    }

    // Add an edge
    void addEdge(int v1, int v2)
    {
        setEdgeWeight(v1, v2, 1);
    }

    // Delete an edge
    void delEdge(int v1, int v2)
    {
        if (isEdge(v1, v2))
        {
            M--;
            matrix[v1][v2] = 0;
        }
    }

    // Determine if an edge is in the graph
    bool isEdge(int v1, int v2)
    {
        return (matrix[v1][v2] > 0);
    }

    int weight(int v1, int v2)
    {
        checkVertex(v1);
        checkVertex(v2);
        if (isEdge(v1, v2))
            return matrix[v1][v2];
        else
            return 0;
    }

    int getMark(int v)
    {
        checkVertex(v);
        return mark[v];
    }

    void setMark(int v, int value)
    {
        checkVertex(v);
        mark[v] = value;
    }

    /* bool isBipartite(int src)
    {
        // Create a color array to store colors
        // assigned to all veritces. Vertex
        // number is used as index in this array.
        // The value '-1' of colorArr[i]
        // is used to indicate that no color
        // is assigned to vertex 'i'. The value 1
        // is used to indicate first color
        // is assigned and value 0 indicates
        // second color is assigned.
        int colorArr[N];
        for (int i = 0; i < N; ++i)
            colorArr[i] = -1;

        // Assign first color to source
        colorArr[src] = 1;

        // Create a queue (FIFO) of vertex
        // numbers and enqueue source vertex
        // for BFS traversal
        queue<int> q;
        q.push(src);

        // Run while there are vertices
        // in queue (Similar to BFS)
        while (!q.empty())
        {
            // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
            int u = q.front();
            q.pop();

            // Return false if there is a self-loop
            if (G[u][u] == 1)
                return false;

            // Find all non-colored adjacent vertices
            for (int v = 0; v < V; ++v)
            {
                // An edge from u to v exists and
                // destination v is not colored
                if (G[u][v] && colorArr[v] == -1)
                {
                    // Assign alternate color to this adjacent v of u
                    colorArr[v] = 1 - colorArr[u];
                    q.push(v);
                }

                // An edge from u to v exists and destination
                // v is colored with same color as u
                else if (G[u][v] && colorArr[v] == colorArr[u])
                    return false;
            }
        }

        // If we reach here, then all adjacent
        // vertices can be colored with alternate color
        return true;
    } */

    bool isBipartite(int v,vector<bool> *visited, vector<int> *color){

        for (int u : neighbors(v)){

            // if vertex u is not explored before
            if (visited[u] == false){

                // mark present vertic as visited
                visited[u] = true;

                // mark its color opposite to its parent
                color[u] = !color[v];

                // if the subtree rooted at vertex v is not bipartite
                if (!isBipartite(u, visited, color))
                    return false;
            }

            // if two adjacent are colored with same color then
            // the graph is not bipartite
            else if (color[u] == color[v])
                return false;
        }
        return true;
    }
};

#endif