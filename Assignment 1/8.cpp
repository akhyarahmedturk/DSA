#include<iostream>
#include<stack>

class TreeNode{ // TreeNode for char data structure
public:
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char value, TreeNode* l = nullptr, TreeNode* r = nullptr){ // Constructor to initialize node
        data = value;
        left = l;
        right = r;
    }
};

using namespace std;

TreeNode* tree_exp(string postfix){
    stack<TreeNode*> st;
    TreeNode* temp;
    for (int i = 0;i < postfix.length();i++){
        temp = new TreeNode(postfix[i]);
        if (postfix[i] < 'a' || postfix[i] > 'z'){// an operator found
            temp->right = st.top();
            st.pop();
            temp->left = st.top();
            st.pop();
        }
        st.push(temp);// pushing nodes in stack, node contain an operator with left and right contain other nodes
    }
    return st.top();
    // leaf nodes contain values while other contain operators
}

void inorderTraversal(TreeNode* root){ // no need to right in assignment
    if (root == nullptr) return;
    cout << "( ";
    inorderTraversal(root->left);
    cout << root->data;
    inorderTraversal(root->right);
    cout << " )";
}

int main(){ // no need to right in assignment
    string postfix = "abc*+de*-";
    TreeNode* root = tree_exp(postfix);
    cout << "Expression by inorder traversal : ";
    inorderTraversal(root);
    return 0;
}

