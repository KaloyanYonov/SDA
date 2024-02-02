// Това решение дава 60/100

#include <iostream>
#include <vector>

int calculateDaysUntilFinal(std::vector<int>& hungerLevels) {
    int days = 0;
    bool eliminated;
    do {
        eliminated = false;
        for (int i = hungerLevels.size() - 1; i > 0; i--) {
            if (hungerLevels[i] > hungerLevels[i - 1]) {
                hungerLevels.erase(hungerLevels.begin() + i);
                eliminated = true;
            }
        }
        if (eliminated) days++;
    } while (eliminated);
    return days;
}

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> hungerLevels;
    int n, hungerLevel;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> hungerLevel;
        hungerLevels.push_back(hungerLevel);
    }

    std::cout <<  calculateDaysUntilFinal(hungerLevels) << std::endl;

    return 0;
}