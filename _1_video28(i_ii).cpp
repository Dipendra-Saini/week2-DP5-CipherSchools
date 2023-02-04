#include <bits/stdc++.h>
using namespace std;

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

int numTrees(int n) {
    if(n <= 1) return 1;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += numTrees(i-1) * numTrees(n-i);
    return ans;
}

void inorder(Node* root, vector<int> &nums){
    if (root == NULL) return;
    inorder(root->left, nums);
    nums.push_back(root->data);
    inorder(root->right, nums);
}

Node* buildTree(vector<int> &nums, int s , int e){
    if (s > e) return NULL;
    int mid = (s+e)/2;
    Node *root = new Node(nums[mid]);
    root->left = buildTree(nums, s, mid-1);
    root->right = buildTree(nums, mid+1, e);
    return root;
}

Node* balanceBST(Node* root) {
    vector<int> nums;
    inorder(root, nums);
    int n = nums.size()-1;
    return buildTree(nums, 0, n);
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    return 0;
}
