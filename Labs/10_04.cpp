#include<iostream>
#include"Node.h"
using namespace std;

int diameter_by_height(Node* root, int& res){
    if (!root) return 0;
    int left_h = diameter_by_height(root->left, res);
    int right_h = diameter_by_height(root->right, res);
    res = max(res, left_h + right_h);
    return max(left_h, right_h) + 1;
}
int diameterOfBinaryTree(Node* root){
    int res = 0;
    int dummy = diameter_by_height(root, res);
    return res;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Diameter of the tree is: " << diameterOfBinaryTree(root) << endl;// By no of Edges
    return 0;
}