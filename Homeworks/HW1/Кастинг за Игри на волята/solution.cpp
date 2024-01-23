#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    int k;
    std::cin >> k;
    std::vector<long> arr;

    for (int i = 0; i < n; ++i) {
        long cont;
        std::cin >> cont;
        arr.push_back(cont);
    }

    std::sort(arr.begin(), arr.end());

    long smallestDifference = arr[k - 1] - arr[0];

    for (int i = 1; i <= n - k; ++i) {
        long currentDifference = arr[i + k - 1] - arr[i];
        if (currentDifference < smallestDifference) {
            smallestDifference = currentDifference;
        }
    }

    std::cout << smallestDifference;

    return 0;
}