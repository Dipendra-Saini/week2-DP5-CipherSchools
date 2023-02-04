#include <bits/stdc++.h>
using namespace std;

//Find the maximum sum path between two leaves in a binary tree

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

int findMaxSumPath(Node* root, int &max_sum)
{
    if (root == nullptr) {
        return 0;
    }
    int left = findMaxSumPath(root->left, max_sum);
    int right = findMaxSumPath(root->right, max_sum);

    if (root->left == nullptr) {
        return right + root->data;
    }

    if (root->right == nullptr) {
        return left + root->data;
    }
    int cur_sum = left + right + root->data;
    max_sum = max(cur_sum, max_sum);
    return max(left, right) + root->data;
}

int findMaxSumPath(Node* root)
{
    int max_sum = INT_MIN;
    findMaxSumPath(root, max_sum);

    return max_sum;
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << findMaxSumPath(root) << endl;

    return 0;
}
