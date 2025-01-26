#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class TreeNode{ // TreeNode structure for the binary tree
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){ // Constructor to initialize node
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* Construct(vector<int>& pre, vector<int>& in, int& pre_s, int in_s, int in_end){
    if (pre_s >= pre.size() || in_s > in_end) return nullptr;
    TreeNode* root = new TreeNode(pre[pre_s]);
    int curr_idx = 0;
    for (int i = in_s;i <= in_end;i++){
        if (in[i] == pre[pre_s]){
            curr_idx = i;
            break;
        }
    }
    pre_s++;
    root->left = Construct(pre, in, pre_s, in_s, curr_idx - 1);
    root->right = Construct(pre, in, pre_s, curr_idx + 1, in_end);
    return root;
}

void inorder_display(TreeNode* node){ // Recursive inorder traversal function
    if (node == nullptr) return;
    inorder_display(node->left);
    cout << node->data << " ";
    inorder_display(node->right);
}

void preorder_display(TreeNode* node){ // Recursive preorder traversal function
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder_display(node->left);
    preorder_display(node->right);
}

int main(){
    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };
    int pre_s = 0;
    TreeNode* root = Construct(preorder, inorder, pre_s, 0, inorder.size() - 1);
    cout << "inorder dispay : ";
    inorder_display(root);
    cout << endl;
    cout << "preorder dispay : ";
    preorder_display(root);
    cout << endl;
    return 0;
}