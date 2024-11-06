#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Node{ // Node structure for the binary tree
public:
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int value, Node* l = nullptr, Node* r = nullptr){ // Constructor to initialize node
        height = 1;
        data = value;
        left = l;
        right = r;
    }
};

class AVL_Tree{
    Node* root;
    Node* insert(Node* root, int val){
        if (!root){
            root = new Node(val);
        }
        else if (val > root->data){
            root->right = insert(root->right, val);
        }
        else{
            root->left = insert(root->left, val);
        }
        root = Balance_tree(root);
        return root;
    }
public:
    AVL_Tree() :root(nullptr){ }
    void insert(int val){
        root = insert(root, val);
    }
    int get_height(Node* root){
        if (!root) return 0;
        return root->height;
    }
    int get_root_height(){
        if (!root) return 0;
        return root->height;
    }
    void set_height(Node* root){
        root->height = 1 + max(get_height(root->left), get_height(root->right));
    }
    Node* rotate_left(Node* root){
        Node* temp = root->right;
        root->right = temp->left;
        temp->left = root;
        set_height(root);
        set_height(temp);
        return temp;
    }
    Node* rotate_right(Node* root){
        Node* temp = root->left;
        root->left = temp->right;
        temp->right = root;
        set_height(root);
        set_height(temp);
        return temp;
    }
    Node* Balance_tree(Node* root){
        set_height(root);
        int BF = get_height(root->left) - get_height(root->right);
        if (BF > 1){
            BF = get_height(root->left->left) - get_height(root->left->right);
            if (BF < 0){
                root->left = rotate_left(root->left);
            }
            root = rotate_right(root);
        }
        else if (BF < -1){
            BF = get_height(root->right->left) - get_height(root->right->right);
            if (BF > 0){
                root->right = rotate_right(root->right);
            }
            root = rotate_left(root);
        }
        return root;
    }
    void inorderTraversal(Node* node){ // Recursive inorder traversal function
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
    void display(){
        cout << "tree: ";
        inorderTraversal(root);
        cout << endl;
    }
};

int main(){
    AVL_Tree avl;
    avl.insert(10);
    cout << avl.get_root_height() << endl;
    avl.insert(20);
    cout << avl.get_root_height() << endl;
    avl.insert(30);
    cout << avl.get_root_height() << endl;
    avl.insert(40);
    cout << avl.get_root_height() << endl;
    avl.insert(50);
    cout << avl.get_root_height() << endl;
    avl.insert(60);
    cout << avl.get_root_height() << endl;
    avl.insert(70);
    cout << avl.get_root_height() << endl;
    avl.insert(80);
    cout << avl.get_root_height() << endl;
    avl.insert(90);
    cout << avl.get_root_height() << endl;
    avl.insert(100);
    cout << avl.get_root_height() << endl;
    avl.insert(110);
    cout << avl.get_root_height() << endl;
    avl.insert(120);
    cout << avl.get_root_height() << endl;
    avl.insert(130);
    cout << avl.get_root_height() << endl;
    avl.insert(140);
    cout << avl.get_root_height() << endl;
    avl.insert(150);
    cout << avl.get_root_height() << endl;
    return 0;
}