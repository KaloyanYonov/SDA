#include <bits/stdc++.h>


struct g {
    
    int V;
    std::vector<std::vector<std::pair<int, int>>> adjList;

    g(int vertices) : V(vertices), adjList(vertices) {}

    void insert(int u, int v, int w) {
        adjList[u].emplace_back(v, w);
    }

    int Djikstra(int source, int destination, std::vector<int>& arr) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        std::vector<int> dist(V, INT_MAX);

        pq.push({0, source});
        dist[source] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                int waitTime = (dist[u] % arr[u] == 0) ? 0 : arr[u] - (dist[u] % arr[u]);
                int arrivalTime = dist[u] + weight + waitTime;

                if (arrivalTime < dist[v]) {
                    dist[v] = arrivalTime;
                    pq.push({dist[v], v});
                }
            }
        }

        return (dist[destination] == INT_MAX) ? -1 : dist[destination];
    }
};

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int V, E, s, e;
    std::cin >> V >> E >> s >> e;

    std::vector<int> v(V);
    for (int i = 0; i < V; ++i) {
        std::cin >> v[i];
    }

    g graph(V);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph.insert(u, v, w);
    }


    std::cout << graph.Djikstra(s, e, v) << std::endl;

    return 0;
}