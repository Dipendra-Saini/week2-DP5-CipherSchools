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

int get_pos(vector<int> postorder,vector<int> inorder,int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}


Node* buildTree(vector<int> postorder,vector<int> inorder,int start,int end){
    static int index=postorder.size()-1;
    if(start>end){
        return NULL;
    }
    int curr = postorder[index];
    index--;

    Node* node = new Node(curr);
    if(start == end){
        return node;
    }

    int pos = get_pos(postorder,inorder,start,end,curr);
    node->right = buildTree(postorder,inorder,pos+1,end);
    node->left = buildTree(postorder,inorder,start,pos-1);

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

    vector<int> postorder = {4,5,2,6,7,3,1};
    vector<int> inorder = {4,2,5,1,6,3,7};

    Node* root = buildTree(postorder,inorder,0,inorder.size()-1);
    inorder_traversal(root);


    return 0;
}
