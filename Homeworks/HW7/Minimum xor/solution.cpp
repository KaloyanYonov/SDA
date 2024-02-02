#include<bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n;
    std::cin >> n;

    std::set<size_t> numbers = {0};
    size_t minXOR = SIZE_MAX;

    while (n-- > 0) {
        size_t temp;
        std::cin >> temp;

        auto it = numbers.insert(temp).first;
        size_t xorWithPrev = (it != numbers.begin()) ? *std::prev(it) ^ temp : minXOR;
        size_t xorWithNext = (std::next(it) != numbers.end()) ? *std::next(it) ^ temp : minXOR;

        minXOR = std::min({minXOR, xorWithPrev, xorWithNext});

        std::cout << minXOR << '\n';
    }

    return 0;
}
