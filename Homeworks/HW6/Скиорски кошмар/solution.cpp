#include <bits/stdc++.h>

struct Node {
    long data;
    Node* left;
    Node* right;
    Node() : data(0), left(nullptr), right(nullptr) {}
};

std::vector<Node> nodes;

void verticalSumcheck(Node* root, int index, std::vector<long>& tree) {
    if (root == nullptr) {
        return;
    }
    verticalSumcheck(root->left, index - 1, tree);
    tree[index] += root->data;
    verticalSumcheck(root->right, index + 1, tree);
}

void verticalSum(Node* root) {
    int treeSize = 2 * nodes.size(); 
    std::vector<long> tree(treeSize, 0);
    verticalSumcheck(root, nodes.size(), tree);
    
    for (int i = 0; i < treeSize; ++i) {
        if (tree[i] != 0) {
            std::cout << tree[i] << " ";
        }
    }
}

void addNode(long value, int index, int left, int right) {
    nodes[index].data = value;
    if (left != -1) {
        nodes[index].left = &nodes[left];
    }
    if (right != -1) {
        nodes[index].right = &nodes[right];
    }
}

int main() {
    long a;
    int indexL, indexR;
    long n;
    std::cin >> n;
    nodes.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> indexL >> indexR;
        addNode(a, i, indexL, indexR);
    }
    verticalSum(&nodes[0]);
    
    return 0;
}