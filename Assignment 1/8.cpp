#include<iostream>
#include<stack>

class Node{ // Node structure for the binary tree
public:
    char data;
    Node* left;
    Node* right;
    Node(char value, Node* l = nullptr, Node* r = nullptr){ // Constructor to initialize node
        data = value;
        left = l;
        right = r;
    }
};

using namespace std;

Node* tree_exp(string postfix){
    stack<Node*> st;
    Node* temp;
    for (int i = 0;i < postfix.length();i++){
        temp = new Node(postfix[i]);
        if (postfix[i] < 'a' || postfix[i] > 'z'){
            temp->right = st.top();
            st.pop();
            temp->left = st.top();
            st.pop();
        }
        st.push(temp);
    }
    return st.top();
}

void inorderTraversal(Node* root){ // Recursive preorder traversal function
    if (root == nullptr) return;
    //if (root->data == '*' || root->data == '/' || root->data == '^')
    cout << "( ";
    inorderTraversal(root->left);
    cout << root->data;
    inorderTraversal(root->right);
    //if (root->data == '*' || root->data == '/' || root->data == '^')
    cout << " )";
}

int main(){
    string postfix = "abc*+de*-";
    Node* root = tree_exp(postfix);
    cout << "Expression by inorder traversal : ";
    inorderTraversal(root);
    return 0;
}

