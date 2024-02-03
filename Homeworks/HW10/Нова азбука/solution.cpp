// Това решение дава 88.89/100

#include <bits/stdc++.h>

void dfs(char current, std::unordered_map<char, std::set<char>> &graph, std::unordered_map<char, bool> &visited, std::vector<char> &result) {
    visited[current] = true;
    for (char neighbor : graph[current]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, result);
        }
    }
    result.push_back(current);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> words(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> words[i];
    }

    std::unordered_map<char, std::set<char>> graph;

    for (int i = 0; i < n - 1; ++i) {
         std::string word1 = words[i];
         std::string word2 = words[i + 1];

        int len = std::min(word1.length(), word2.length());

        for (int j = 0; j < len; ++j) {
            if (word1[j] != word2[j]) {
                graph[word1[j]].insert(word2[j]);
                break;
            }
        }
    }

    std::vector<char> result;
    std::unordered_map<char, bool> visited;

    for (const auto &entry : graph) {
        char letter = entry.first;
        if (!visited[letter]) {
            dfs(letter, graph, visited, result);
        }
    }

    for (int i = result.size() - 1; i >= 0; --i) {
        std::cout << result[i] << " ";
    }

    return 0;
}
