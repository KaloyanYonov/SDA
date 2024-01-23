#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    
    
    std::string word;
    std::cin >> word;
    int N;
    std::cin >> N;
    char symbol;
    std::cin >> symbol;
    
    long count =0;
    int length = word.length();
    while(N>0){
        if(N < length){
            word.resize(length-(length-N));
        }
        for(const char& c : word){
            if(symbol == c){
                count++;
            }
        }
        N = N - word.length();
    }
    std::cout << count;
    
    return 0;
}
