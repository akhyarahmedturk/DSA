#include<iostream>
#include<stack>
#include "Node.h"

using namespace std;

void zigzagLevelOrder(Node* root){
    if (!root) return;
    stack<Node*> st1, st2;
    st1.push(root);
    Node* current;
    while (!st1.empty()){
        while (!st1.empty()){
            current = st1.top();
            st1.pop();
            cout << current->data << " ";
            if (current->left){
                st2.push(current->left);
            }
            if (current->right){
                st2.push(current->right);
            }
        }
        cout << endl;
        if (st2.empty()) break;
        while (!st2.empty()){
            current = st2.top();
            st2.pop();
            cout << current->data << " ";
            if (current->right){
                st1.push(current->right);
            }
            if (current->left){
                st1.push(current->left);
            }
        }
        cout << endl;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(5);
    zigzagLevelOrder(root);
    return 0;
}