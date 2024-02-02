#include <bits/stdc++.h>



int main() {
    int N, M;
    std::cin >> N >> M;

    std::set<int> notUsed;
    for (int i = 1; i < N+1; ++i) {
        notUsed.insert(i);
    }

    std::vector<int> P(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> P[i];
        notUsed.erase(P[i]);
    }

    std::vector<int> result;
    int lastNumber = 0;

    for (int i = 0; i < M; ++i) {
        int currentNumber = P[i];

        for (int j = lastNumber + 1; j < currentNumber; ++j) {
            if (notUsed.count(j)) {
                result.push_back(j);
                notUsed.erase(j);
            }
        }

        result.push_back(currentNumber);
        lastNumber = currentNumber;
    }

    for (int number : notUsed) {
        result.push_back(number);
    }

    for (int num : result) {
        std::cout << num << " ";
    }


    return 0;
}