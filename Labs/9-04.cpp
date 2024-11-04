#include<iostream>
#include"Node.h"

using namespace std;

int DFS(Node* root){
    if (root == nullptr) return 0;
    int sum = root->data;
    if (root->left) sum += DFS(root->left);
    if (root->right) sum += DFS(root->right);
    return sum;
}

int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(20);
    root->right->right = new Node(65);
    root->right->left = new Node(55);
    cout << "Sum: " << DFS(root) << endl;
    return 0;
}