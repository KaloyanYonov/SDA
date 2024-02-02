#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>



int main() {
    std::string str;
    std::cin >> str;

    const int MAX_CHAR = 128;

    std::vector<int> charCount(MAX_CHAR, 0);

    for (char c : str) {
        charCount[c]++;
    }

    for (int i = 0; i < str.size(); ++i) {
        if (charCount[str[i]] == 1) {
            std::cout << i << " ";
        }
    }

    return 0;
}
   