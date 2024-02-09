//This solution gives 12.50/50 points
#include <iostream>
#include <queue>
#include <vector>

long days_to_strengthen_papayas(long n, long min_strength, std::vector<long>& strengths) {
    std::priority_queue<long, std::vector<long>, std::greater<long>> pq(strengths.begin(), strengths.end());
    int days = 0;

    while (!pq.empty() && pq.top() < min_strength) {
        if (pq.size() < 2) {
            return -1;
        }
        long weakest = pq.top(); pq.pop();
        long second_weakest = pq.top(); pq.pop();
        long new_papaya_strength = weakest + second_weakest;
        pq.push(new_papaya_strength);
        days++;
        if (pq.size() == 1 && pq.top() < min_strength) {
            return -1;
        }
    }

    return days;
}

int main() {
    long n, min_strength;
    std::cin >> n >> min_strength;
    
    std::vector<long> strengths(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> strengths[i];
    }

    long result = days_to_strengthen_papayas(n, min_strength, strengths);
    std::cout << result << std::endl;

    return 0;
}