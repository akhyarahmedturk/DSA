#include<iostream>
#include<queue>

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
    Node* Find_successor(Node* right){
        while (right->left){
            right = right->left;
        }
        return right;
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
    Node* delete_Node(Node* root, int key){
        if (key > root->data){
            if (root->right)
                root->right = delete_Node(root->right, key);
        }
        else if (key < root->data){
            if (root->left)
                root->left = delete_Node(root->left, key);
        }
        else{
            if (root->left && root->right){
                Node* successor = Find_successor(root->right);
                root->data = successor->data;
                root->right = delete_Node(root->right, successor->data);
            }
            else{
                Node* temp = root;
                root = (root->left) ? root->left : root->right;
                delete temp;
            }
        }
        if (root)
            root = Balance_tree(root);
        return root;
    }
    Node* insert(Node* root, int data){
        if (!root){
            root = new Node(data);
        }
        else if (data > root->data){
            root->right = insert(root->right, data);
        }
        else{
            root->left = insert(root->left, data);
        }
        root = Balance_tree(root);
        return root;
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
    void lavel_order_traversal(){ // Recursive inorder traversal function
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            while (size > 0){
                Node* temp = q.front();
                q.pop();
                if (!temp){
                    cout << "null" << " ";
                }
                else{
                    cout << temp->data << " ";
                    q.push(temp->left);
                    q.push(temp->right);
                }
                size--;
            }
            cout << endl;
        }
    }
public:
    AVL_Tree() :root(nullptr){ }
    void insert(int data){
        root = insert(root, data);
    }
    void delete_Node(int key){
        root = delete_Node(root, key);
    }
    int get_height(Node* root){
        if (!root) return 0;
        return root->height;
    }
    void display(){
        cout << "tree: " << endl;
        lavel_order_traversal();
        cout << endl;
    }
};

int main(){
    AVL_Tree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.display();
    avl.insert(40);
    avl.insert(50);
    avl.insert(60);
    avl.display();
    avl.delete_Node(10);
    avl.delete_Node(30);
    avl.delete_Node(60);
    avl.display();
    return 0;
}