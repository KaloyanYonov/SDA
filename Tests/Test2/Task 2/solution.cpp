#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        int target, t;
        std::cin >> target >> t;
        std::vector<int> weights(t);
        std::unordered_map<int, int> weightToIndex;

        for (int i = 0; i < t; ++i) {
            std::cin >> weights[i];
            weightToIndex[weights[i]] = i;
        }

        for (int i = 0; i < t; ++i) {
            int diff = target - weights[i];
            if (weightToIndex.count(diff) && weightToIndex[diff] != i) {
                std::cout << std::min(i + 1, weightToIndex[diff] + 1) << " " << std::max(i + 1, weightToIndex[diff] + 1) << std::endl;
                break;
            }
        }
    }

    return 0;
}