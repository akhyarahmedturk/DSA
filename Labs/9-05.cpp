#include<iostream>
#include<vector>
#include<stack>

#include"TreeNode.h"
using namespace std;


class Min_difference{
    int res = INT_MAX;
    int prv = -100000;// assuming values are not less than -10^5
public:
    void inorder(TreeNode* root){
        if (root->left) inorder(root->left);
        res = min(res, root->data - prv);
        prv = root->data;
        if (root->right) inorder(root->right);
    }
    int minDiffInBST(TreeNode* root){
        inorder(root);
        return res;
    }
};


int main(){
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(20);
    root->right->right = new TreeNode(65);
    root->right->left = new TreeNode(55);
    Min_difference tree;
    cout << "Minimum difference between two nodes is: " << tree.minDiffInBST(root) << endl;
    return 0;
}
