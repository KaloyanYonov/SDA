#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        int T, K;
        std::string fails;
        std::cin >> T >> K >> fails;

        std::vector<char> result;

        for (char c = 'A'; c <= 'Z'; c++) {
            int count = std::count(fails.begin(), fails.end(), c);

            if (count >= K) {
                result.push_back(c);
            }
        }

        std::sort(result.begin(), result.end());

        for (char c : result) {
            std::cout << c;
        }
        std::cout << std::endl;
    }

    return 0;
}