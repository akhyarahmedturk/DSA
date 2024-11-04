#include<iostream>
#include<vector>
#include<stack>
#include"Node.h"
using namespace std;

Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if (p->data > root->data && q->data > root->data){
        return lowestCommonAncestor(root->right, p, q);
    }
    else if (p->data < root->data && q->data < root->data){
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}


int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(20);
    root->right->right = new Node(65);
    root->right->left = new Node(55);
    Node* a = root->left->left, * b = root->right->right;
    cout << "LCS of node a: " << a->data << " and b: " << b->data << " is: " << lowestCommonAncestor(root, a, b)->data << endl;
    a = root->right->left;
    b = root->right->right;
    cout << "LCS of node a: " << a->data << " and b: " << b->data << " is: " << lowestCommonAncestor(root, a, b)->data << endl;
    return 0;
}