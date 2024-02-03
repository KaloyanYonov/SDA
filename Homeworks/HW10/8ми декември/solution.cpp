#include<bits/stdc++.h>

int bfs(const std::vector<std::vector<int>>& graph, int start, const std::vector<int>& group, int myGroup) {
    std::vector<int> distance(graph.size(), INT_MAX);
    std::queue<int> q;

    distance[start] = 0;
    q.push(start);

    int minDistance = INT_MAX;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (distance[neighbor] == INT_MAX) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);

                if (group[neighbor] == myGroup) {
                    minDistance = std::min(minDistance, distance[neighbor]);
                }
            }
        }
    }

    return minDistance;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    std::vector<int> group(N + 1);
    int myGroup;
    for (int i = 1; i <= N; ++i) {
        std::cin >> group[i];
    }
    std::cin >> myGroup;

    int minDistance = INT_MAX;
    for (int i = 1; i <= N; ++i) {
        if (group[i] == myGroup) {
            minDistance = std::min(minDistance, bfs(graph, i, group, myGroup));
        }
    }

    std::cout << (minDistance == INT_MAX ? 0 : minDistance) << std::endl;

    return 0;
}
