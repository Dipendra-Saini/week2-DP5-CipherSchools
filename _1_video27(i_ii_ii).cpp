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

void range(Node* root,const pair<int,int> &rg,vector<int>&result){
    if(root==NULL){
        return;
    }
    if(root->data < rg.first){
        range(root->right,rg,result);
    }
    else if(root->data > rg.second){
        range(root->left,rg,result);
    }
    else{
        result.push_back(root->data);
        range(root->left,rg,result);
        range(root->right,rg,result);
    }
}


Node* solve(int s , int e , vector<int>& nums){
    if(s > e)
        return NULL;

    int mid = (s+e)/2;

    Node* root = new Node(nums[mid]);
    root->left = solve(s , mid-1, nums);
    root->right = solve(mid+1 , e , nums);

    return root;
}

Node* sortedArrayToBST(vector<int>& nums) {
    return solve(0 , nums.size()-1 , nums);
}


Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    int small = min(p->data, q->data);
    int large = max(p->data, q->data);
    while (root != nullptr) {
        if (root->data > large)
            root = root->left;
        else if (root->data < small)
            root = root->right;
        else
            return root;
    }
    return NULL;
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
