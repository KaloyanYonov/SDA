#include <bits/stdc++.h>

class Road{
    public:
    static int m;
    
    int nOne;
    int from;
    int to;
    long cOne;
    long cTwo;
    
    Road();
    bool operator<(const Road& other) const;
    
    
};

int Road::m = 0;


Road::Road(){
    this->m++;
    this->nOne= this->m;
}

bool Road::operator<(const Road& other) const{
    if(this->cOne != other.cOne){
        return this->cOne > other.cOne;
    }
    return this->cTwo < other.cTwo;
}


std::vector<Road> PrimAlgo(std::vector<std::vector<Road>>&neighbours,int n){
    
    std::vector<bool> connectivity(n,false);
    std::vector<Road> MST;
    int connectedRoads = 1;
    
    std::priority_queue<Road> roads;
    connectivity[0] = true; // first road
    int neighboursZeroSize = neighbours[0].size();
    for(int i = 0 ; i< neighboursZeroSize;++i){
        roads.push(neighbours[0][i]);
    }
    while(connectedRoads < n){
        Road current = roads.top();
        roads.pop();
        
        if(!connectivity[current.to]){
            MST.push_back(current);
            connectivity[current.to] = true;
            connectedRoads++;
            int neighboursCTsize = neighbours[current.to].size();
            for(int j = 0 ; j < neighboursCTsize;++j){
                roads.push(neighbours[current.to][j]);
            }
        }
        
    }
    return MST;
}


int main() {
    
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<Road>>neighbours(n);
    
    
    
    for(int i = 0 ; i < m;++i){
        Road road;
        std::cin >> road.from >> road.to >> road.cOne >> road.cTwo;
        road.to--;
        road.from--;
        
        neighbours[road.from].push_back(road);
        std::swap(road.from, road.to);
        neighbours[road.from].push_back(road);
        
        
    }
    std::vector<Road> MST = PrimAlgo(neighbours,n);
    int MSTsize = MST.size();
    for(int j = 0 ; j < MSTsize;++j){
        std::cout << MST[j].nOne << std::endl;
    }
    
    
    return 0;
}