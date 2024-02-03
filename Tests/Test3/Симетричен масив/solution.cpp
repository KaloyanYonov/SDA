// Това решение дава 35/50

#include<bits/stdc++.h>

bool isSymmetrical(const std::vector<int>& v) {
    int size = v.size();
    for (int i = 0; i < size / 2; ++i) {
        if (v[i] != -v[size - i - 1] || v[i] == 0) { 
            return false;
        }
    }
    return true;
}

int main() {
    
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; ++i){
        int size;
        std::cin >> size;
        std::vector<int> v(size);

        for(int j = 0; j < size; ++j){
            std::cin >> v[j];
        }

        if(isSymmetrical(v)){ 
            std::cout << "YES" << std::endl;
        }
        else{
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}
