#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;

int full_nodes(TreeNode* root){
    if (!root) return 0;
    if (root->left && root->right){// have both right and left child
        return 1 + full_nodes(root->left) + full_nodes(root->right);
    }
    else if (root->left){
        return full_nodes(root->left);
    }
    else if (root->right){
        return full_nodes(root->right);
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    cout << "Total full nodes are: " << full_nodes(root) << endl;
    return 0;
}