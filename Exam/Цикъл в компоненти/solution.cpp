#include <iostream>
#include <vector>
#include <list>

struct Graph {
    int v; 
    std::list<int> *adj;

    Graph(int _v) {
        this->v = _v;
        adj = new std::list<int>[v];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool dfs(int v, std::vector<bool>& visited, int parent) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, visited, v)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    int cycleCounter() {
        std::vector<bool> visited(v, false);
        int count = 0;
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, -1)) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int q;
    std::cin >> q;
    while (q--) {
        int n, m;
        std::cin >> n >> m;
        Graph g(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            g.addEdge(u, v);
        }
        std::cout << g.cycleCounter() << std::endl;
    }
    return 0;
}