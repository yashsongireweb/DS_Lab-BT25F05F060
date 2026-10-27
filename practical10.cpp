
#include <iostream>
using namespace std;

int graph[20][20];
int visited[20];
int n;

void DFS(int v)
{
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int edges, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;

        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    return 0;
}
