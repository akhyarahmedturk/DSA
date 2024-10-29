#include<iostream>
#include<queue>
#include "Node.h"

using namespace std;

bool print_ancestors(Node* root, int key){
    if (root == nullptr)   return false;
    if (root->data == key) return true;
    if (print_ancestors(root->left, key) || print_ancestors(root->right, key)){
        cout << root->data << " ";
        return true;
    }
    return false;
}

void print_all_ancestors(Node* root, int key){
    cout << "Ancestors of " << key << " in the tree are: ";
    bool dummy = print_ancestors(root, key);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left = new Node(6);
    int key = 6;
    print_all_ancestors(root, key);
    return 0;
}