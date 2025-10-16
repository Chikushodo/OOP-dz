#include <iostream> 
#include <vector>   
#include <stack>    
const int MAX_VERTICES = 100;
std::vector<int> adj[MAX_VERTICES];
bool visited[MAX_VERTICES];

using namespace std;

void dfs_recursive(int u) { 
    visited[u] = true;
    cout << u << " "; 

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs_recursive(v);
        }
    }
}

void dfs_iterative(int start_node) {
    cout << "Iterative DFS starting from node " << start_node << ": ";

    stack<int> s;
    s.push(start_node);

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (!visited[u]) {
            visited[u] = true;
            cout << u << " ";

            for (int v : adj[u]) { 

                if (!visited[v]) {
                    s.push(v);
                }
            }
        }
    }
    cout << endl; 
}

int main() {
    int num_vertices, num_edges;

    cout << "Enter the number of vertices: ";
    cin >> num_vertices;

    cout << "Enter the number of edges: ";
    cin >> num_edges;
    for (int i = 0; i < num_vertices; ++i) {
        visited[i] = false;
    }

    cout << "Enter edges (u v) where u and v are 0-indexed vertex numbers:\n";
    for (int i = 0; i < num_edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    int start_node;
    cout << "Enter the starting node for DFS (0 to " << num_vertices - 1 << "): ";
    cin >> start_node;
    for (int i = 0; i < num_vertices; ++i) {
        visited[i] = false; 
    }
    cout << "Recursive DFS traversal starting from node " << start_node << ": ";
    dfs_recursive(start_node);
    cout << endl; 
    for (int i = 0; i < num_vertices; ++i) {
        visited[i] = false; 
    }
    dfs_iterative(start_node);
}