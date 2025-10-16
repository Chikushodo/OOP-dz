#include <iostream>
#include <vector>

const int MAX_VERTICES = 100; 
struct Edge {
    int to_vertex;
    int weight;
};
std::vector<Edge> adj[MAX_VERTICES];
int V; 
const int INFINITY_VAL = 999999999;

int key[MAX_VERTICES];     
int parent[MAX_VERTICES];     
bool mstSet[MAX_VERTICES];    

int minKey() {
    int min_val = INFINITY_VAL;
    int min_index = -1;

    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < min_val) {
            min_val = key[v];
            min_index = v;
        }
    }
    return min_index;
}
void addEdge(int u, int v, int weight) {
    adj[u].push_back({ v, weight }); 
    adj[v].push_back({ u, weight }); 
}

void primMST() {
    for (int i = 0; i < V; ++i) {
        key[i] = INFINITY_VAL;
        parent[i] = -1;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V; ++count) {
        int u = minKey();

        if (u == -1) {
            std::cout << "Graph is disconnected. Cannot form a single MST." << std::endl;
            break;
        }

        mstSet[u] = true;

        for (const auto& edge : adj[u]) { 
            int v = edge.to_vertex;
            int weight = edge.weight;

            if (!mstSet[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }
    std::cout << "Edges in MST:" << std::endl;
    int total_weight = 0;
    for (int i = 1; i < V; ++i) {
        if (parent[i] != -1) {
            std::cout << parent[i] << " - " << i << " \tWeight: " << key[i] << std::endl;
            total_weight += key[i];
        }
    }
    std::cout << "Total weight of MST: " << total_weight << std::endl;
}

int main() {
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;

    std::cout << "Enter the number of edges: ";
    int num_edges;
    std::cin >> num_edges;

    std::cout << "Enter edges (u v weight) where u and v are 0-indexed vertex numbers:\n";
    for (int i = 0; i < num_edges; ++i) {
        int u, v, weight;
        std::cin >> u >> v >> weight;
        addEdge(u, v, weight);
    }

    primMST();
}