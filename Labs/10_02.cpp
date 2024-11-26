#include<iostream>
#include<vector>
#include<queue>
#include"TreeNode.h"

using namespace std;

TreeNode* Sorted_array_to_BST(vector<int>& nums, int start, int end){
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode* new_node = new TreeNode(nums[mid]);
    new_node->left = Sorted_array_to_BST(nums, start, mid - 1);
    new_node->right = Sorted_array_to_BST(nums, mid + 1, end);
    return new_node;
}

void lavel_order_traversal(TreeNode* root){ // traversal function
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        while (size > 0){
            TreeNode* temp = q.front();
            q.pop();
            if (!temp){
                cout << "null" << " ";
            }
            else{
                cout << temp->data << " ";
                q.push(temp->left);
                q.push(temp->right);
            }
            size--;
        }
        cout << endl;
    }
}

int main(){
    vector<int> vec = { -10,-3,0,5,9 };
    TreeNode* root = Sorted_array_to_BST(vec, 0, vec.size() - 1);
    cout << "Tree:" << endl;
    lavel_order_traversal(root);
    return 0;
}