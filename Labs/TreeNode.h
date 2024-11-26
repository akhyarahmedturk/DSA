class TreeNode{ // TreeNode structure for the binary tree
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value, TreeNode* l = nullptr, TreeNode* r = nullptr){ // Constructor to initialize node
        data = value;
        left = l;
        right = r;
    }
};