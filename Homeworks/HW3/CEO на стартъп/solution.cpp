// това решение дава само 50/100

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


bool isPossible(const std::vector<int>& developers, int maxSum, int squads) {
    int currentSum = 0;
    int currentSquads = 0;
    int size = developers.size();

    for (int i = 0; i < size; i++) {
        if (currentSum + developers[i] > maxSum) {
            currentSquads++;
            currentSum = 0;
        }
        currentSum += developers[i];
    }

    currentSquads++;
    
    return currentSquads <= squads;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, t;
    std::cin >> n >> t;

    std::vector<int> developers(n);
    int totalUsefulness = 0;
    int maxDeveloperUsefulness = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> developers[i];
        totalUsefulness += developers[i];
        maxDeveloperUsefulness = std::max(maxDeveloperUsefulness, developers[i]);
    }

    int left = maxDeveloperUsefulness;
    int right = totalUsefulness;

    while (left < right) {
        int mid = (left + right) / 2;
        if (isPossible(developers, mid, t)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    std::cout << left << std::endl;

    return 0;
}