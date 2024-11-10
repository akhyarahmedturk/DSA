#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;
//Assuming structurally identical is that they have the same structure and structrully identical nodes have same data
bool are_identical(TreeNode* root1, TreeNode* root2){
    if (!root1 && !root2) return true;// both are null
    if (!root1 || !root2) return false;// either one of them is null
    if (root1->data != root2->data) return false; // have different data
    return (are_identical(root1->left, root2->left) && are_identical(root1->right, root2->right));
}

int main(){
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->right->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->right->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    if (are_identical(root1, root2))
        cout << "They are structurally identical." << endl;
    else
        cout << "They are not structurally identical." << endl;
    return 0;
}