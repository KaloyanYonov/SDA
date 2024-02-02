// Не препоръчвам това решение дава само 10/100

#include <bits/stdc++.h>
 

struct Group {
    int size, start, finish;
};

bool compareGroups(const Group& a, const Group& b) {
    return a.finish <= b.start;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int q;
    std::cin >> q;

    while (q--) {
        int n, c;
        std::cin >> n >> c;

        std::vector<Group> groups;
        for (int i = 0; i < n; ++i) {
            Group g;
            std::cin >> g.size >> g.start >> g.finish;
            groups.push_back(g);
        }


        int capacity = 0;
        bool canFit = true;

        for (const auto& group : groups) {
            capacity += group.size;

            if (capacity > c) {
                canFit = false;
                break;
            }

            capacity -= (group.finish <= groups.back().start) ? group.size : 0;
        }

        std::cout << (canFit ? 1 : 0) << std::endl;
    }

    return 0;
}