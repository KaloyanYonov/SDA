//Това решение дава само 30/100

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<long long> grades(n);

    for (int i = 0; i < n; i++) {
        std::cin >> grades[i];
    }

    std::sort(grades.begin(), grades.end());

    for (int i = 0; i < q; i++) {
        long long a, b;
        std::cin >> a >> b;
        
        long long count = std::upper_bound(grades.begin(), grades.end(), b) -
                         std::lower_bound(grades.begin(), grades.end(), a);

        std::cout << count << std::endl;
    }

    return 0;
}