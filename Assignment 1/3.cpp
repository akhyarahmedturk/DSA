#include<iostream>
#include<queue>
#include "Node.h"

using namespace std;
//structurally identical for me is they have the same structure and structrully same nodes have same data
bool are_identical(Node* root1, Node* root2){
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    if (root1->data != root2->data) return false;
    return (are_identical(root1->left, root2->left) && are_identical(root1->right, root2->right));
}

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->right->right = new Node(5);
    root1->right->left = new Node(6);
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->right->right = new Node(5);
    root2->right->left = new Node(6);
    if (are_identical(root1, root2))
        cout << "They are structurally identical." << endl;
    else
        cout << "They are not structurally identical." << endl;
    return 0;
}