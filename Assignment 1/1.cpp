#include<iostream>
#include<queue>
#include "Node.h"

using namespace std;

int full_nodes(Node* root){
    int result = 0;
    if (root == nullptr){ // If the tree is empty, set the new node as the root
        return 0;
    }
    queue<Node*> q; // Use a queue for level-order traversal to find the first available position
    q.push(root);
    while (!q.empty()){
        Node* current = q.front();
        q.pop();
        if (current->left && current->right){
            result++;
            q.push(current->left);
            q.push(current->right);
        }
        else if (current->left){
            q.push(current->left);
        }
        else if (current->right){
            q.push(current->right);
        }
        else{
            result++;
        }
    }
    return result;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left = new Node(6);
    cout << "Total full nodes are: " << full_nodes(root) << endl;
    return 0;
}