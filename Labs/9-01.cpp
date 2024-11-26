#include<iostream>
#include<stack>
#include"TreeNode.h"
using namespace std;

void PreorderTraversal(TreeNode* root){
    if (!root) return;
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* temp;
    while (!st.empty()){
        temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
    }
}

void PostorderTraversal(TreeNode* root){
    if (!root) return;
    stack<TreeNode*> st;
    st.push(new TreeNode(root->data, root->left, root->right));// using deep comp so original tree remain as it is.
    while (!st.empty()){
        TreeNode* temp1 = nullptr, * temp2 = nullptr;
        if (st.top()->right){
            temp1 = new TreeNode(st.top()->right->data, st.top()->right->left, st.top()->right->right);
            st.top()->right = nullptr;// doing null because next time we pop we ge child free node to print 
        }
        if (st.top()->left){
            temp2 = new TreeNode(st.top()->left->data, st.top()->left->left, st.top()->left->right);
            st.top()->left = nullptr; // doing null because next time we pop we ge child free node to print 
        }
        if (temp1) st.push(temp1);
        if (temp2) st.push(temp2);
        if (!temp1 && !temp2){
            temp1 = st.top();
            st.pop();
            cout << temp1->data << " ";
            delete temp1;
        }
    }
}


int main(){
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(20);
    root->right->right = new TreeNode(65);
    root->right->left = new TreeNode(55);
    cout << "Postorder traversal: ";
    PostorderTraversal(root);
    cout << endl;
    cout << "Printing Prestorder traversal to show the tree has not changed: ";
    PreorderTraversal(root);
    cout << endl;
    return 0;
}