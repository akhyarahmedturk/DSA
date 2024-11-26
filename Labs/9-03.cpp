#include<iostream>
#include<vector>
#include<stack>
#include"TreeNode.h"
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if (p->data > root->data && q->data > root->data){
        return lowestCommonAncestor(root->right, p, q);
    }
    else if (p->data < root->data && q->data < root->data){
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}


int main(){
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(20);
    root->right->right = new TreeNode(65);
    root->right->left = new TreeNode(55);
    TreeNode* a = root->left->left, * b = root->right->right;
    cout << "LCS of node a: " << a->data << " and b: " << b->data << " is: " << lowestCommonAncestor(root, a, b)->data << endl;
    a = root->right->left;
    b = root->right->right;
    cout << "LCS of node a: " << a->data << " and b: " << b->data << " is: " << lowestCommonAncestor(root, a, b)->data << endl;
    return 0;
}