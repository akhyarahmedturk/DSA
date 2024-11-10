#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;

TreeNode* removekeys(TreeNode* root, int l, int r){// reccursive function
    TreeNode* temp;
    if (!root) return nullptr;
    else if (root->data < l){// removing elements smaller than "l"
        temp = root->right;
        delete root;
        return removekeys(temp, l, r);// this will return false so the link will be eliminated from parent
    }
    else if (root->data > r){ // removing elements greater than "r"
        temp = root->left;
        delete root;
        return removekeys(temp, l, r);// this will return false so the link will be eliminated from parent
    }
    else{ // node is in the range so dont remove it
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        return root;
    }
}

void inorderTraversal(TreeNode* node){ // no need to write in assignment
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

int main(){
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(20);
    root->right->right = new TreeNode(65);
    root->right->left = new TreeNode(55);
    int l = 30, r = 60;
    cout << "Inorder traversal before: ";
    inorderTraversal(root);
    cout << endl;
    root = removekeys(root, l, r);
    cout << "Inorder traversal after: ";
    inorderTraversal(root);
    return 0;
}