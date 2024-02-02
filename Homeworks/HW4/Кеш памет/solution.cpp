// това решение дава 40/100

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

class Element {
public:
    int key;
    int value;
    int accessTime;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, Q, K;
    std::cin >> N >> Q >> K;

    std::vector<Element> elements;
    int currentTime = 0;

    for (int i = 0; i < Q; i++) {
        std::string operation;
        std::cin >> operation;

        if (operation == "put") {
            int x, y;
            std::cin >> x >> y;
            int arrSize = elements.size();

            int foundIndex = -1;
            for (int j = 0; j < arrSize; ++j) {
                if (elements[j].key == x) {
                    elements[j].value = y;
                    elements[j].accessTime = currentTime++;
                    foundIndex = j;
                    break;
                }
            }

            if (foundIndex == -1) {
                Element newElement = {x, y, currentTime++};
                if (arrSize >= N) {
                    int oldestTime = elements[0].accessTime;
                    int removeIndex = 0;
                    for (int j = 1; j < arrSize; ++j) {
                        if (elements[j].accessTime < oldestTime) {
                            oldestTime = elements[j].accessTime;
                            removeIndex = j;
                        }
                    }
                    elements.erase(elements.begin() + removeIndex);
                }
                elements.push_back(newElement);
            }
        } else if (operation == "get") {
            int arrSize = elements.size();
            int x;
            std::cin >> x;
            int foundIndex = -1;

            for (int j = 0; j < arrSize; ++j) {
                if (elements[j].key == x) {
                    std::cout << elements[j].value << std::endl;
                    elements[j].accessTime = currentTime++;
                    foundIndex = j;
                    break;
                }
            }

            if (foundIndex == -1) {
                std::cout << "-1" << std::endl;
            }
        }

        if (i % K == K - 1) {
            int arrSize = elements.size();
            int oldestTime = elements[0].accessTime;
            int removeIndex = 0;
            for (int j = 1; j < arrSize; ++j) {
                if (elements[j].accessTime < oldestTime) {
                    oldestTime = elements[j].accessTime;
                    removeIndex = j;
                }
            }
            elements.erase(elements.begin() + removeIndex);
        }
    }

    return 0;
}