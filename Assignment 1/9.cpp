#include<iostream>
#include<stack>
#include "Node.h"

using namespace std;

int distance_from_root(Node* root, int key){
    if (!root) return -1234;// if key not found
    else if (root->data == key) return 0;
    else if (key > root->data) return 1 + distance_from_root(root->right, key);
    else return 1 + distance_from_root(root->left, key);
}

int distance_btw_nodes(Node* root, int a, int b){
    if (!root) - 123456789;
    if (a > root->data && b > root->data){
        return distance_btw_nodes(root->right, a, b);// both are on right
    }
    else if (a < root->data && b < root->data){
        return distance_btw_nodes(root->left, a, b); // both are on left
    }
    else return distance_from_root(root, a) + distance_from_root(root, b);
}

int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    int a = 80, b = 20;
    cout << "The distance between nodes with value a: " << a << " and b: " << b << " is: " << distance_btw_nodes(root, a, b) << endl;
    return 0;
}