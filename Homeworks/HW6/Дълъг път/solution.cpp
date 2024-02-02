#include <bits/stdc++.h>


struct Node {
    long data;
    Node* left;
    Node* right;
    Node() : data(0), left(nullptr), right(nullptr) {}
};

std::vector<Node> nodes;

void addNode(long value, int index, int left, int right) {
    nodes[index].data = value;
    if (left != -1) {
        nodes[index].left = &nodes[left];
    }
    if (right != -1) {
        nodes[index].right = &nodes[right];
    }
}

long maxPathSumUtil(Node* root, long& maxSum) {
    if (root == nullptr) {
        return 0;
    }

    long leftMax = std::max(maxPathSumUtil(root->left, maxSum), 0L);
    long rightMax = std::max(maxPathSumUtil(root->right, maxSum), 0L);

    long currentMax = root->data + leftMax + rightMax;
    maxSum = std::max(maxSum, currentMax);

    return root->data + std::max(leftMax, rightMax);
}

long maxPathSum(Node* root) {
    long maxSum = std::numeric_limits<long>::min();
    maxPathSumUtil(root, maxSum);
    return maxSum;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    long a;
    int indexL, indexR;
    long n;
    std::cin >> n;
    nodes.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> indexL >> indexR;
        addNode(a, i, indexL, indexR);
    }

    std::cout << maxPathSum(&nodes[0]) << std::endl;

    return 0;
}
