#include<iostream>
#include<stack>
#include "TreeNode.h"

using namespace std;

void zigzagLevelOrder(TreeNode* root){
    if (!root) return;
    stack<TreeNode*> st1, st2;
    st1.push(root);
    TreeNode* current;
    while (!st1.empty()){// level order traversal using nested while loops
        while (!st1.empty()){//stack 1 for even levels
            current = st1.top();
            st1.pop();
            cout << current->data << " ";
            if (current->left){// pushing left to right in st2 because odd levels are to be printed from right to left
                st2.push(current->left);
            }
            if (current->right){
                st2.push(current->right);
            }
        }
        cout << endl;
        if (st2.empty()) break;
        while (!st2.empty()){//stack 2 for odd levels
            current = st2.top();
            st2.pop();
            cout << current->data << " ";
            if (current->right){// pushing right to left in st1 because even levels are to be printed from left to right
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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    zigzagLevelOrder(root);
    return 0;
}