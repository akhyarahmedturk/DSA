#include<iostream>
#include<queue>
#include "Node.h"

using namespace std;

bool path_with_sum_k(Node* root, int k){
    if (root == nullptr){
        return false;
    }
    k -= root->data;
    if (k == 0) return true;
    if (k < 0) return false;
    bool op1 = false, op2 = false;
    if (root->left){
        op1 = path_with_sum_k(root->left, k);
    }
    if (root->right){
        op2 = path_with_sum_k(root->right, k);
    }
    return (op1 || op2);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left = new Node(6);
    int k = 5;
    if (path_with_sum_k(root, k))
        cout << "There exist a path in tree with sum: " << k << endl;
    else
        cout << "There not exist any path in tree with sum: " << k << endl;
    return 0;
}