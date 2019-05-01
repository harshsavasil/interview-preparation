#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void addEdge(vvi &graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printGraph(const vvi &adj, int V) { 
    for (int v = 0; v < V; ++v) 
    { 
        cout << "\n Adjacency list of vertex "
             << v << "\n head "; 
        for (auto x : adj[v]) 
           cout << "-> " << x; 
        printf("\n"); 
    } 
}

void DFSutil(int v, vector<bool> &visited, const vvi &adj) {
    visited[v] = true;
    cout << v << " --> " ;
    for(auto i: adj[v]) {
        if(!visited[i]) {
            DFSutil(i, visited, adj);
        }
    }
}

void dfs(int v, const vvi &adj) {
    vector<bool> visited(5, false);
    DFSutil(v, visited, adj);
}

// void topological_sort() {}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int V = 5;
    vvi graph(V);
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
    printGraph(graph, V);
    cout << endl;
    cout << "DFS: " << endl;
    dfs(0, graph); 
    return 0;
}