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


void right_view_of_tree(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> que;
    que.push(root);

    while(!que.empty()){
        int size = que.size();
        for(int i=0;i<size;i++){
            Node* node = que.front();
            que.pop();
            if(i==(size-1)){
                cout<<node->data<<" ";
            }
            if(node->left!=NULL){
                que.push(node->left);
            }
            if(node->right!=NULL){
                que.push(node->right);
            }
        }
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

    right_view_of_tree(root);

    return 0;
}
