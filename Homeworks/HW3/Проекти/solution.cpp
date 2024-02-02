#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int occurrences(int* a, int size, int d) {
    std::sort(a, a + size); 

    int count = 0;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (std::abs(a[j] - a[i]) == d) {
                count++;
            } else if (std::abs(a[j] - a[i]) > d) {
                break; 
            }
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);  

    int n, d;
    std::cin >> n  >> d;

    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::cout << occurrences(a,n,d);
    return 0;
}
