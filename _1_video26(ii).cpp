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

vector<string> ans;
void dfs(Node* node, string path) {
    if(node->left == NULL and node->right == NULL) ans.push_back(path + to_string(node->data));
    if(node->left) dfs(node->left, path + to_string(node->data) + "->");
    if(node->right) dfs(node->right, path + to_string(node->data) + "->");
}

vector<string> binaryTreePaths(Node* root) {
    dfs(root, "");
    return ans;
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<string> result;
    result = binaryTreePaths(root);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}
