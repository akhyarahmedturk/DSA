#include<iostream>
#include"TreeNode.h"

using namespace std;

int DFS(TreeNode* root){
    if (root == nullptr) return 0;
    int sum = root->data;
    if (root->left) sum += DFS(root->left);
    if (root->right) sum += DFS(root->right);
    return sum;
}

int main(){
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(20);
    root->right->right = new TreeNode(65);
    root->right->left = new TreeNode(55);
    cout << "Sum: " << DFS(root) << endl;
    return 0;
}