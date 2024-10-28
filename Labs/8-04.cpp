#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Node{ // Node structure for the binary tree
public:
    int data;
    Node* left;
    Node* right;
    Node(int value){ // Constructor to initialize node
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* Construct(vector<int>& pre, vector<int>& in, int pre_s, int in_s, int in_end){
    if (pre_s >= pre.size() || in_s > in_end) return nullptr;
    Node* root = new Node(pre[pre_s]);
    int curr_idx = 0;
    for (int i = in_s;i <= in_end;i++){
        if (in[i] == pre[pre_s]){
            curr_idx = i;
            break;
        }
    }
    root->left = Construct(pre, in, pre_s + 1, in_s, curr_idx - 1);
    root->right = Construct(pre, in, pre_s + (curr_idx - in_s) + 1, curr_idx + 1, in_end);
    return root;
}

void inorder_display(Node* node){ // Recursive inorder traversal function
    if (node == nullptr) return;
    inorder_display(node->left);
    cout << node->data << " ";
    inorder_display(node->right);
}

void preorder_display(Node* node){ // Recursive preorder traversal function
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder_display(node->left);
    preorder_display(node->right);
}

int main(){
    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };
    Node* root = Construct(preorder, inorder, 0, 0, inorder.size() - 1);
    cout << "inorder dispay : ";
    inorder_display(root);
    cout << endl;
    cout << "preorder dispay : ";
    preorder_display(root);
    cout << endl;
    return 0;
}