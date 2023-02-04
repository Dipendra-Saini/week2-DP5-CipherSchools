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


vector<vector<int>> verticalTraversal(Node* root) {
    map<int, map<int, multiset<int>>>m;
    queue<pair<Node*, pair<int, int>>>q;
    q.push({root, {0, 0}});
    while(!q.empty()){
        root=q.front().first;
        int vert=q.front().second.first, lvl=q.front().second.second;
        q.pop();
        m[vert][lvl].insert(root->data);
        if(root->left!=NULL){q.push({root->left, {vert-1, lvl+1}});}
        if(root->right!=NULL){q.push({root->right, {vert+1, lvl+1}});}
    }
    vector<vector<int>>ans;
    for(auto it: m){
        vector<int>v;
        for(auto it1: it.second){
            v.insert(v.end(), it1.second.begin(), it1.second.end());
        }
        ans.push_back(v);
    }
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

    vector<vector<int>> result;
    result = verticalTraversal(root);
    for(auto keyval : result){
        for(auto i : keyval){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}
