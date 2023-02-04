#include <bits/stdc++.h>
using namespace std;

//Level order traversal using queue only

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

void level_Order_traversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> que;
    que.push(root);
    que.push(NULL);
    while(!que.empty()){
        Node* node = que.front();
        que.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left!=NULL){
                que.push(node->left);
            }
            if(node->right!=NULL){
                que.push(node->right);
            }
        }
        else if(!que.empty()){
            que.push(NULL);
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

    level_Order_traversal(root);
    return 0;
}
