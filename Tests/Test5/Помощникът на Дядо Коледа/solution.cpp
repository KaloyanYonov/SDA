//this solution gives 21.43/50 (1 timeout 1 segmentation fault)
#include <bits/stdc++.h>

constexpr int MAX_N = 1000000;

bool hasPath(const std::vector<int> graph[], int from, int to) {
    std::vector<bool> visited(MAX_N, false);

    std::queue<int> q;
    q.push(from);
    visited[from] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == to) {
            return true;
        }

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> graph[MAX_N];

    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    int Q;
    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        int source, destination;
        std::cin >> source >> destination;

        bool pathExists = hasPath(graph, source, destination);

        std::cout << (pathExists ? 1 : 0) << " ";
    }

    return 0;
}