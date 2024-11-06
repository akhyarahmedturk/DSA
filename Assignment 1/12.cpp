#include<iostream>
#include<queue>
#include "Node.h"

using namespace std;

Node* removekeys(Node* root, int l, int r){
    Node* temp;
    if (!root) return nullptr;
    else if (root->data < l){
        temp = root->right;
        delete root;
        return removekeys(temp, l, r);
    }
    else if (root->data > r){
        temp = root->left;
        delete root;
        return removekeys(temp, l, r);
    }
    else{
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        return root;
    }
}

void inorderTraversal(Node* node){ // Recursive inorder traversal function
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(20);
    root->right->right = new Node(65);
    root->right->left = new Node(55);
    int l = 30, r = 60;
    cout << "Inorder traversal before: ";
    inorderTraversal(root);
    cout << endl;
    root = removekeys(root, l, r);
    cout << "Inorder traversal after: ";
    inorderTraversal(root);
    return 0;
}