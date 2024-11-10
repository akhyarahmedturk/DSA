#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;

// travel root to leave and subtracting the roots values from required sum i:e k 
// if k==0 then a path is found 
// if k<0 then don't need to go down because (assuming) tree contain +ve values only
bool path_with_sum_k(TreeNode* root, int k){
    if (root == nullptr){
        return false;
    }
    k -= root->data;
    if (k == 0) return true;
    bool op1 = false, op2 = false;
    if (root->left){ // check path in left subtree
        op1 = path_with_sum_k(root->left, k);
    }
    if (root->right){ // check path in right subtree
        op2 = path_with_sum_k(root->right, k);
    }
    return (op1 || op2);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    int k = 5;
    if (path_with_sum_k(root, k))
        cout << "There exist a path in tree with sum: " << k << endl;
    else
        cout << "There not exist any path in tree with sum: " << k << endl;
    return 0;
}