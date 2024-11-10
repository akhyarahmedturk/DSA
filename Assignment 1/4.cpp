#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;

pair<int, int> max_level_sum(TreeNode* root){ // pair<int,int> first value is level with max sum and second is sum of that level
    if (root == nullptr){
        return { -1,0 };// no levels in tree
    }
    pair<int, int> result = { 0,0 };// starting levels from zero
    int current_sum, current_level = 0;
    queue<TreeNode*> q; // Use a queue for level-order traversal
    q.push(root);
    while (!q.empty()){
        current_sum = 0;
        int size = q.size();
        while (size > 0){
            TreeNode* current = q.front();
            q.pop();
            current_sum += current->data;
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
            size--;
        }
        if (current_sum > result.second){// result.second contain previously maximum sum
            result = { current_level,current_sum };
        }
        current_level++;
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
    pair<int, int> result = max_level_sum(root);
    cout << "The level with maximum sum is level: " << result.first << " and sum is: " << result.second << endl;
    return 0;
}