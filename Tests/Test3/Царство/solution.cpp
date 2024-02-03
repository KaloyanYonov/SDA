#include <bits/stdc++.h>

void dfs(int node, std::vector<int> v[], std::vector<int>& subs, std::vector<bool>& visited) {
    visited[node] = true;
    int count = 0;
    for (int child : v[node]) {
        if (!visited[child]) {
            dfs(child, v, subs, visited);
            count += 1 + subs[child];
        }
    }
    subs[node] = count;
}

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    std::vector<int> v[N];
    for (int i = 1; i < N; ++i) {
        int parent, child;
        std::cin >> parent >> child;
        v[parent].push_back(child);
    }
    
    std::vector<int> sub(N, 0);
    std::vector<bool> visited(N, false);
    
    dfs(0, v, sub, visited);
    
    for (int i = 0; i < N; ++i) {
        std::cout << sub[i] << " ";
    }
    
    return 0;
}