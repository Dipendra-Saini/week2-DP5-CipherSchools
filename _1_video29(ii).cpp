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

class Minheap{
    int capacity;
    int size;
    int *heap;
    int parent (int index){
        return (index-1) / 2;
    }
    int leafchild(int index){
        return (2*index+1);
    }
    int rightchild(int index){
        return (2*index+2);
    }
    void minHeapify(int index){
        int a = index;
        int l = leafchild(index),r = rightchild(index);
        if(l<this->size && this->heap[index] > this->heap[l]){
            a = l;
        }
        if(r<this->size && this->heap[index] > this->heap[r]){
            a = r;
        }
        if(a!=index){
            swap(this->heap[index],this->heap[a]);
            minHeapify(a);
        }
    }
public:
    Minheap(int capacity){
        this->capacity = capacity;
        this->size = size;
        this->heap = new int[this->capacity];
    }
    void push(int key){
        if(this->size == this->capacity){
            return;
        }
        this->size++;
        int index = this->size-1;
        this->heap[index] = key;

        while(index!=0 && this->heap[index] < this->heap[parent[index]]){
            swap(this->heap[index], this->heap[parent[index]]);
            index = parent[index];
        }

    }

    int top(){
        if(this->size == 0){
            return -1;
        }
        return this->heap[0];
    }
    void pop(){
        if(this->size ==0){
            return;
        }
        if(this->size==1){
            this->size--;
            return;
        }

        swap(this->heap[0],this->heap[this->size-1]);
        this->size--;
        minHeapify(this->size);
    }
};


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
