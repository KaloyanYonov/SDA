#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>


int minCount(std::vector<int>& v) {
    std::vector<int> sorted = v;
    int size = v.size();
    std::sort(sorted.begin(), sorted.end());

    int left = 0;
    int right = size - 1;

    while (left < size && v[left] == sorted[left]) {
        left++;
    }

    while (right >= 0 && v[right] == sorted[right]) {
        right--;
    }

    if (left <= right) {
        return (right - left + 1);
    } 
    return 0;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::cout << minCount(arr);   
    return 0;
}