#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include"../../Assignment 1/TreeNode.h"
using namespace std;

TreeNode* delete_Node(TreeNode* root, int val){
    if (!root) return root;
    TreeNode* last_node = nullptr, * to_delete = nullptr, * LSP = nullptr; //LSP last node parent
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        last_node = q.front();
        q.pop();
        if (last_node->data == val) to_delete = last_node;
        if (last_node->left){
            LSP = last_node;
            q.push(last_node->left);
        }
        if (last_node->right){
            LSP = last_node;
            q.push(last_node->right);
        }
    }
    if (!to_delete) return root;
    if (to_delete == last_node && to_delete == root){
        delete to_delete;
        return nullptr;
    }
    else{
        to_delete->data = last_node->data;
        if (LSP->left == last_node){
            LSP->left = nullptr;
        }
        else LSP->right = nullptr;
        delete last_node;
    }
    return root;
}

void inorder(TreeNode* root){
    if (root->left) inorder(root->left);
    cout << root->data << " ";
    if (root->right) inorder(root->right);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left = new TreeNode(7);
    inorder(root);
    cout << endl;
    root = delete_Node(root, 1);
    inorder(root);
    cout << endl;
    root = delete_Node(root, 5);
    inorder(root);
    cout << endl;
    root = delete_Node(root, 6);
    inorder(root);
    cout << endl;
    root = delete_Node(root, 3);
    inorder(root);
    cout << endl;
    root = delete_Node(root, 4);
    inorder(root);
    cout << endl;
    root = delete_Node(root, 2);
    inorder(root);
    cout << endl;
    root = delete_Node(root, 7);
    inorder(root);
    cout << endl;
    return 0;
}