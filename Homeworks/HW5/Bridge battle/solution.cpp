#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>


int main() {
    long n,compare;
    std::vector<long>ans;
    std::stack<long>rhs;
    std::stack<long>compared;
    std::cin >> n;
    std::cin>> compare;
    while(compare <0){
        if(n==0){
            break;
        }
        ans.push_back(compare);
        n--;
        std::cin >> compare;
    }
    
    while(compare >0){
        if(n==0){
            break;
        }
        rhs.push(compare);
        n--;
        std::cin >> compare;
        
    }
    while(n>0){
        if(!rhs.empty() && compare < 0 && abs(compare)<rhs.top()){
            std::cin >> compare;
            n--;
        }
        else if(compare>0){
            
            rhs.push(compare);
            n--;
            std::cin>>compare;
        }
        
        else if(!rhs.empty()&& abs(compare)==rhs.top()){
            rhs.pop();
            std::cin >> compare;
            n--;
        }
        else if(!rhs.empty()&& abs(compare) > rhs.top()){
            rhs.pop();
        }
        
        
        else{
            ans.push_back(compare);
            std::cin>>compare;
            n--;
        }
    }
        while(!rhs.empty()){
            compared.push(rhs.top());
            rhs.pop();
        }
    
        long size = ans.size();
        for(long i =0;i<size;++i){
            std::cout << ans[i]<< " ";
        }
        while(!compared.empty()){
            std::cout << compared.top()<<" ";
            compared.pop();
        }
        return 0;
    }