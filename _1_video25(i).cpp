#include <bits/stdc++.h>
using namespace std;

//Find the maximum sum path from root to leaves in a binary tree

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

bool printPath (Node* root, int sum)
{
    if (sum == 0 && root == nullptr) {
        return true;
    }
    if (root == nullptr) {
        return false;
    }

    bool left = printPath(root->left, sum - root->data);
    bool right = false;

    if (!left) {
        right = printPath(root->right, sum - root->data);
    }

    if (left || right) {
        cout << root->data << " ";
    }

    return left || right;
}

int getRootToLeafSum(Node* root)
{
    if (root == nullptr) {
        return INT_MIN;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    int left = getRootToLeafSum(root->left);
    int right = getRootToLeafSum(root->right);

    return (left > right? left : right) + root->data;
}

void findMaxSumPath(Node* root)
{
    int sum = getRootToLeafSum(root);
    cout << "The Maximum sum is " << sum << endl;
    cout << "The Maximum sum path is ";

    printPath(root, sum);
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    findMaxSumPath(root);

    return 0;
}
