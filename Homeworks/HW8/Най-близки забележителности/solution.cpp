#include <bits/stdc++.h>

struct Destination {
    int x, y;
    double dist;

    Destination() : x(0), y(0), dist(0) {}

    void calculateDistance(int X, int Y) {
        dist = sqrt(pow(x - X, 2) + pow(y - Y, 2));
    }
};

bool compareDestinations(const Destination &a, const Destination &b) {
    if (a.dist < b.dist){
        return true;
    }
    else if (a.dist == b.dist){
        return a.x < b.x;
    }
    
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int X, Y, N, K;
    std::cin >> X >> Y >> N >> K;

    std::vector<Destination> attractions(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> attractions[i].x >> attractions[i].y;
        attractions[i].calculateDistance(X, Y);
    }

    std::sort(attractions.begin(), attractions.end(), compareDestinations);

    for (int i = 0; i < K && i < N; ++i) {
        std::cout << attractions[i].x << " " << attractions[i].y << std::endl;
    }

    return 0;
}