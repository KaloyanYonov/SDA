#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int convert(char c){
    if('0' <= c && c <= '9'){
        return c - '0';
    }
    else if('a' <= c && c <= 'z'){
        return c - 'a' + 10;
    }
    else if('A' <= c && c <= 'Z'){
        return c - 'A' +36;
    }
    return c;
}

std::string StringSorted(std::string& str){
    std::sort(str.begin(),str.end(), [](char a, char b){
            return convert(a) < convert(b);
    });
    return str;
}


int main() {
    int n;
    std::cin >> n;
    std::string str;
    std::cin >> str;
    
    std::cout << StringSorted(str);
    
    
    return 0;
}