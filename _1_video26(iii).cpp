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

bool printAncestors(Node* root, Node* node) {
    if (root == nullptr) {
        return false;

        if (root == node) {
            return true;
        }
        bool left = printAncestors(root->left, node);
        bool right = false;
        if (!left) {
            right = printAncestors(root->right, node);
        }
        if (left || right) {
            cout << root->data << " ";
        }
        return left || right;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* node = root->right->right;
    printAncestors(root, node);
    return 0;
}