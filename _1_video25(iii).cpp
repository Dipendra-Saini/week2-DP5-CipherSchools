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

int get_pos(vector<int> preorder,vector<int> inorder,int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}

Node* build_tree(vector<int> preorder,vector<int> inorder,int start,int end){
    static int index = 0;
    if(start>end){
        return NULL;
    }
    int curr = preorder[index];
    index++;

    Node* node = new Node(curr);
    if(start==end){
        return node;
    }
    int pos = get_pos(preorder,inorder,start,end,curr);
    node->left = build_tree(preorder,inorder,start,pos-1);
    node->right = build_tree(preorder,inorder,pos+1,end);

    return node;
}

void inorder_traversal(Node* root){
    if(root==NULL){
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}

int main() {

    vector<int> preorder = {1,2,4,3,5};
    vector<int> inorder = {4,2,1,5,3};

    Node* root = build_tree(preorder,inorder,0,inorder.size()-1);
    inorder_traversal(root);
    return 0;
}
