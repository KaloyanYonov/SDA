#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(1);

    int n;
    double m;

    std::cin >> n;
    std::cin >> m;
    std::cout << m << std::endl;

    std::priority_queue<int> smaller;
    std::priority_queue<int, std::vector<int>, std::greater<int>> larger; 
    

    smaller.push(m);

    for (int i = 1; i < n; i++)
    {
        int a;
        std::cin >> a;

        if (a > m)
        {
            larger.push(a);
        }
        else
        {
            smaller.push(a);
        }

        if (larger.size() == smaller.size() + 2)
        {
            smaller.push(larger.top());
            larger.pop();
        }
        else if (smaller.size() == larger.size() + 2)
        {
            larger.push(smaller.top());
            smaller.pop();
        }

        if (larger.size() == smaller.size())
        {
            m = (smaller.top() + larger.top()) / 2.0;
        }
        else if (larger.size() > smaller.size())
        {
            m = larger.top();
        }
        else
        {
            m = smaller.top();
        }

        std::cout << m << std::endl;
    }

    return 0;
}