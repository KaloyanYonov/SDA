#include <bits/stdc++.h>
using namespace std;

void markCleanRoads(int start, vector<vector<int>>& roads, vector<int>& components, int mark) {
    queue<int> q;
    q.push(start);
    components[start] = mark;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int neighbor : roads[cur]) {
            if (components[neighbor] != mark) {
                components[neighbor] = mark;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    long q;
    cin >> n >> m;
    vector<vector<int>> roads(n);

    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;

        roads[start - 1].push_back(end - 1);
        roads[end - 1].push_back(start - 1);
    }

    vector<int> nodes(n, -1);
    int count = 0;
    for (int j = 0; j < n; ++j) {
        if (nodes[j] == -1) {
            count++;
            markCleanRoads(j, roads, nodes, count);
        }
    }

    cin >> q;
    for (int k = 0; k < q; ++k) {
        int cleared, a, b;
        cin >> cleared >> a >> b;
        a--;
        b--;

        if (cleared == 1) {
            cout << (nodes[a] == nodes[b]);
        } else {
            roads[a].push_back(b);
            roads[b].push_back(a);

            if (nodes[a] != nodes[b]) {
                int newMark = (nodes[a] == -1) ? ++count : nodes[a];
                markCleanRoads(b, roads, nodes, newMark);
            }
        }
    }

    return 0;
}