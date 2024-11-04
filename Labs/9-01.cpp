#include<iostream>
#include<stack>
#include"Node.h"
using namespace std;

void PreorderTraversal(Node* root){
    if (!root) return;
    stack<Node*> st;
    st.push(root);
    Node* temp;
    while (!st.empty()){
        temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
    }
}

void PostorderTraversal(Node* root){
    if (!root) return;
    stack<Node*> st;
    st.push(new Node(root->data, root->left, root->right));// using deep comp so original tree remain as it is.
    while (!st.empty()){
        Node* temp1 = nullptr, * temp2 = nullptr;
        if (st.top()->right){
            temp1 = new Node(st.top()->right->data, st.top()->right->left, st.top()->right->right);
            st.top()->right = nullptr;// doing null because next time we pop we ge child free node to print 
        }
        if (st.top()->left){
            temp2 = new Node(st.top()->left->data, st.top()->left->left, st.top()->left->right);
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
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(20);
    root->right->right = new Node(65);
    root->right->left = new Node(55);
    cout << "Postorder traversal: ";
    PostorderTraversal(root);
    cout << endl;
    cout << "Printing Prestorder traversal to show the tree has not changed: ";
    PreorderTraversal(root);
    cout << endl;
    return 0;
}