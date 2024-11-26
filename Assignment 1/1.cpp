#include<iostream>
#include<queue>
#include "TreeNode.h"


using namespace std;

int full_nodes(TreeNode* root){
    int result = 0;
    if (root == nullptr){
        return 0;// no node in the tree
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        if (current->left && current->right){// have both left and right childs
            result++;
            q.push(current->left);
            q.push(current->right);
        }
        else if (current->left){
            q.push(current->left);
        }
        else if (current->right){
            q.push(current->right);
        }
    }
    return result;
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