#include <bits/stdc++.h>

int babiDistance(std::vector<int>& topics) {
    int size = topics.size();
    
    std::unordered_map<int, int> topicMap;
    int minDist = INT_MAX;

    for (int i = 0; i < size; ++i) {
        if (topicMap.find(topics[i]) != topicMap.end()) {
            int distance = i - topicMap[topics[i]];
            minDist = std::min(minDist, distance);
        }
        topicMap[topics[i]] = i;
    }
    
    if (minDist != INT_MAX) {
        return minDist;
    } 
    else {
        return -1;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;

    std::vector<int> topics(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> topics[i];
    }

    std::cout << babiDistance(topics);

    return 0;
}