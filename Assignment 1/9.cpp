#include<iostream>
#include<stack>
#include "TreeNode.h"

using namespace std;

int distance_from_root(TreeNode* root, int key){// assuming both nodes are present in the tree
    if (root->data == key) return 0;// node found
    else if (key > root->data) return 1 + distance_from_root(root->right, key);// key on right size
    else return 1 + distance_from_root(root->left, key);// on left size
}

// time complexity in worst case will be O(log n) + O(log n) ~ O(log n)
int distance_btw_nodes(TreeNode* root, int a, int b){
    if (!root) - 123456789;
    if (a > root->data && b > root->data){
        return distance_btw_nodes(root->right, a, b);// both are on right
    }
    else if (a < root->data && b < root->data){
        return distance_btw_nodes(root->left, a, b); // both are on left
    }
    else return distance_from_root(root, a) + distance_from_root(root, b);// now one is on left and one is on right so find distances from
    // current node to the these nodes andd add them.
}

int main(){
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);
    int a = 80, b = 20;
    cout << "The distance between nodes with value a: " << a << " and b: " << b << " is: " << distance_btw_nodes(root, a, b) << endl;
    return 0;
}