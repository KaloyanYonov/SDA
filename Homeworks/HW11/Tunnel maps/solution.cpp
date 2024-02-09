#include <bits/stdc++.h>


struct Tunnel {
    int endVertex;
    int distance;
    int kg; 
};


std::vector<std::deque<Tunnel>> graph;
int maxDistance;
int target;
int minWeight = -1;

bool PathForWeight(int kg) {
    const int n = graph.size();
    std::vector<int> distances(n, INT_MAX);
    std::vector<bool> visited(n, false);
    distances[0] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();

        if (visited[current]) continue;
        visited[current] = true;

        if (current == target) break;

        for (const auto& tunnel : graph[current]) {
            if (tunnel.kg > kg || visited[tunnel.endVertex]) {
                continue;
            }
            int newDist = distances[current] + tunnel.distance;

            if (newDist < distances[tunnel.endVertex]) {
                pq.emplace(newDist, tunnel.endVertex);
                distances[tunnel.endVertex] = newDist;
            }
        }
    }

    return distances[target] <= maxDistance;
}

void BinarySearch(int lowerBound, int upperBound) {
    while (lowerBound <= upperBound) {
        int mid = lowerBound + (upperBound - lowerBound) / 2;

        if (PathForWeight(mid)) {
            minWeight = mid;
            upperBound = mid - 1;
        } else {
            lowerBound = mid + 1;
        }
    }
}

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M >> maxDistance;
    
    graph.resize(N);

    target = N - 1;

    int maxWeight = 0;
    while (M--) {
        int startVertex, endVertex, weight, distance;
        std::cin >> startVertex >> endVertex >> weight >> distance;
        --startVertex;
        --endVertex;
        graph[startVertex].push_back({ endVertex, distance, weight });
        maxWeight = std::max(maxWeight, weight);
    }

    BinarySearch(0, maxWeight);

    std::cout << minWeight;

    return 0;
}