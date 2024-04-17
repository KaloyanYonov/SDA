// 80/100 на изпита е бях решил с един тест повече за 90/100 

#include <iostream>
#include <vector>

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    while (n--) {
        std::string s;
        std::cin >> s;
        std::vector<int> freq(100, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        std::vector<int> count(100, 0);
        int maxFreq = 0;
        for (int f : freq) {
            if (f > 0) {
                count[f]++;
                maxFreq = std::max(maxFreq, f);
            }
        }
        bool possible = false;
        for (int i = 1; i <= maxFreq; i++) {
            if (count[i] == 1 && (i == 1 || count[i - 1] * (i - 1) + i == s.size() || count[i + 1] * (i + 1) + 1 == s.size())) {
                possible = true;
                break;
            }
        }
        std::cout << (possible ? 1 : 0) << std::endl;
    }
    return 0;
}