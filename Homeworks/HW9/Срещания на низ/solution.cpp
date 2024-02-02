// Това решение дава 91.67/100
#include<bits/stdc++.h>

int count(std::string s1, std::string s2) {
    std::unordered_map<std::string, int> m;
    long long str1L = s1.length();
    long long str2L = s2.length();
    long long diff = str2L - str1L;

    for (long i = 0; i <= diff; ++i) {
        std::string substring = s2.substr(i, str1L);
        m[substring]++;
    }

    return m[s1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s1;
    std::string s2;
    std::cin >> s1;
    std::cin >> s2;
    std::cout << count(s1,s2);
    return 0;
}