#include <iostream>
#include <vector>
#include <cmath>

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int q;
    std::cin >> q;
    while (q--) {
        int x, closestIndex = -1;
        std::cin >> x;
        int low = 0, high = n - 1, mid;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                closestIndex = mid;
                break;
            } else if (arr[mid] < x) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (closestIndex == -1) { 
            closestIndex = low; 
            if (closestIndex >= n || (closestIndex > 0 && std::abs(arr[closestIndex - 1] - x) <= std::abs(arr[closestIndex] - x))) {
                closestIndex--; 
            }
        }

        if (closestIndex == 0) {
            std::cout << "-1" << std::endl;
        } else {
            std::cout << arr[closestIndex - 1] << std::endl;
        }
    }

    return 0;
}