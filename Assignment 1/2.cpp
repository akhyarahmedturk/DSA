#include<iostream>
#include<queue>
#include "Node.h"

using namespace std;

int full_nodes(Node* root){
    if (!root) return 0;
    if (root->left && root->right){
        return 1 + full_nodes(root->left) + full_nodes(root->right);
    }
    else if (root->left){
        return full_nodes(root->left);
    }
    else if (root->right){
        return full_nodes(root->right);
    }
    else
        return 1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left = new Node(6);
    cout << "Total full nodes are: " << full_nodes(root) << endl;
    return 0;
}