#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;

bool print_ancestors(TreeNode* root, int key){// helper function 
    if (root == nullptr)   return false;
    if (root->data == key) return true;
    if (print_ancestors(root->left, key) || print_ancestors(root->right, key)){
        // if key was found in left_subtree or right_subtree print root
        cout << root->data << " ";
        return true;
    }
    return false;
}

void print_all_ancestors(TreeNode* root, int key){
    cout << "Ancestors of " << key << " in the tree are: ";
    bool dummy = print_ancestors(root, key);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    int key = 6;
    print_all_ancestors(root, key);
    return 0;
}