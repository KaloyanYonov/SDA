#include <bits/stdc++.h>

void dfs(int i, int j, std::vector<std::vector<int>> &forest, int &RowStart, int &RowEnd, int &ColStart, int &ColEnd) {
    if (i < 0 || i >= forest.size() || j < 0 || j >= forest[0].size() || forest[i][j] == 0) {
        return;
    }

    forest[i][j] = 0;
    RowStart = std::min(RowStart, i);
    RowEnd = std::max(RowEnd, i);
    ColStart = std::min(ColStart, j);
    ColEnd = std::max(ColEnd, j);

    dfs(i - 1, j, forest, RowStart, RowEnd, ColStart, ColEnd);
    dfs(i + 1, j, forest, RowStart, RowEnd, ColStart, ColEnd);
    dfs(i, j - 1, forest, RowStart, RowEnd, ColStart, ColEnd);
    dfs(i, j + 1, forest, RowStart, RowEnd, ColStart, ColEnd);
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<int> areas;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                int startR = i, endR = i, startC = j, endC = j;
                dfs(i, j, matrix, startR, endR, startC, endC);
                areas.push_back((endR - startR + 1) * (endC - startC + 1));
            }
        }
    }

    std::sort(areas.rbegin(), areas.rend());

    for (auto area : areas) {
        std::cout << area << " ";
    }

    return 0;
}