#include<iostream>
#include<vector>
#include<stack>

#include"Node.h"
using namespace std;


class Min_difference{
    int res = INT_MAX;
    int prv = -100000;// assuming values are not less than -10^5
public:
    void inorder(Node* root){
        if (root->left) inorder(root->left);
        res = min(res, root->data - prv);
        prv = root->data;
        if (root->right) inorder(root->right);
    }
    int minDiffInBST(Node* root){
        inorder(root);
        return res;
    }
};


int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(20);
    root->right->right = new Node(65);
    root->right->left = new Node(55);
    Min_difference tree;
    cout << "Minimum difference between two nodes is: " << tree.minDiffInBST(root) << endl;
    return 0;
}
