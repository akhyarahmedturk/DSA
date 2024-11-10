#include<iostream>
#include<vector>
using namespace std;
// Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

//TreeNode struct is defined as follows:
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

bool validateBST(TreeNode* root, long long minVal, long long maxVal){
    if (!root)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return validateBST(root->left, minVal, root->data) && validateBST(root->right, root->data, maxVal);
}
bool checkBST(TreeNode* root){
    return validateBST(root, -1, 10000000);
}