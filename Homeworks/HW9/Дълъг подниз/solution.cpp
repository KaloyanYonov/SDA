// Това решение дава 95/100
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>


int main() {
    
    
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    std::string first , second;
    std::cin >> first >> second ;
    
    int maxLength =0;
    int* substrlen[2];
    int firstSize = first.size();
    int secondSize = second.size();
    
    substrlen[0] = new int[firstSize+1];
    substrlen[1] = new int[firstSize+1];
    
    for(int i = 0 ; i < firstSize + 1;++i){
        substrlen[0][i] = 0;
        substrlen[1][i] = 0;
    }
    for(int i = 0 ; i < firstSize;++i){
        for(int j = 0 ; j < secondSize;++j){
            if(first[i] == second[j]){
                substrlen[i%2][j+1] = substrlen[(i+1)%2][j]+1;
                if (substrlen[i % 2][j + 1] > maxLength)
                {
                    maxLength = substrlen[i % 2][j + 1];
                }
            }
            else{
                substrlen[i%2][j+1] = 0;
            }
        }
    }
    std::cout << maxLength << " ";
    
    
    return 0;
}