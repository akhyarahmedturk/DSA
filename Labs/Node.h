class Node{ // Node structure for the binary tree
public:
    int data;
    Node* left;
    Node* right;
    Node(int value,Node *l=nullptr,Node *r=nullptr){ // Constructor to initialize node
        data = value;
        left = l;
        right = r;
    }
};