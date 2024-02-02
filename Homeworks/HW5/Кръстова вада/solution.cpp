#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

int biggestArea(std::vector<int> v) {
    std::stack<int> st;
    int result = 0;
    int size = v.size();

    for (int i = 0; i < size; i++) {
        while (!st.empty() && v[i] < v[st.top()]) {
            int height = v[st.top()];
            st.pop();
            int width;
            if (st.empty()) {
                 width = i;
            } 
            else {
                width = i - st.top() - 1;
            }
            result = std::max(result, height * width);
        }
        st.push(i);
    }

    while (!st.empty()) {
        int height = v[st.top()];
        st.pop();
        int width;
        if (st.empty()) {
            width = size;
        } 
        else {
          width = size - st.top() - 1;
        }
        result = std::max(result, height * width);
    }

    return result;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> v(N);

    for (int i = 0; i < N; i++) {
        std::cin >> v[i];
    }

    
    std::cout << biggestArea(v);

    return 0;
}
