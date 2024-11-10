#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;

void insert_elements(TreeNode* root, queue<int>& q){
    if (root->left) insert_elements(root->left, q);
    q.push(root->data);
    if (root->right) insert_elements(root->right, q);
}

bool check_BST(TreeNode* root, queue<int>& q){
    if (root->left){
        if (!check_BST(root->left, q)) return false;// if left branch not satisfied no need check further
    }
    if (!q.empty() && root->data == q.front()) q.pop();// as data is sorted in q and it is inorder traversal 
    //so data should be equal to q.front() for same elements BST's
    else return false;
    if (root->right){
        if (!check_BST(root->right, q)) return false;
    }
    return true;
}

bool have_same_elements(TreeNode* root1, TreeNode* root2){
    queue<int> q;
    if (root1) insert_elements(root1, q);// now all the elemnts of root1 are inserted in queue in sorted order
    if (root2) return check_BST(root2, q);// now inorder traverse to check root2 have same elements or not
    return q.empty();
}

int main(){  //write main in assignment
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);
    TreeNode* root1 = new TreeNode(6);
    root1->left = new TreeNode(5);
    root1->left->left = new TreeNode(4);
    root1->left->left->left = new TreeNode(3);
    root1->left->left->left->left = new TreeNode(2);
    root1->left->left->left->left->left = new TreeNode(1);
    if (have_same_elements(root, root1))
        cout << "Both have same elemens.";
    else
        cout << "Both dose not have all elemens same.";
    return 0;
}