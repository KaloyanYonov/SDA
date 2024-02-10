#icnlude <bits/stdc++.h>

bool canFormSentence(std::map<std::string, int> &firstSentenceWords, std::map<std::string, int> &secondSentenceWords) {
    for (auto &word : secondSentenceWords) {
        if (firstSentenceWords[word.first] < word.second) {
            return false;
        }
    }
    return true;
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        int n1, n2;
        std::cin >> n1 >> n2;
        std::map<std::string, int> firstSentenceWords, secondSentenceWords;
        std::string word;

        for (int i = 0; i < n1; ++i) {
            std::cin >> word;
            firstSentenceWords[word]++;
        }

        for (int i = 0; i < n2; ++i) {
            std::cin >> word;
            secondSentenceWords[word]++;
        }

        if (canFormSentence(firstSentenceWords, secondSentenceWords)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
