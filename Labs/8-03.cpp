#include<iostream>
#include<queue>
using namespace std;

class TreeNode{ // TreeNode structure for the binary tree
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value){ // Constructor to initialize node
		data = value;
		left = nullptr;
		right = nullptr;
	}
};


int is_balanced(TreeNode* root, bool& res){
	if (!root) return 0;
	int left_height = is_balanced(root->left, res);
	int right_height = is_balanced(root->right, res);
	if (abs(left_height - right_height) > 1) res = false;
	return max(left_height, right_height) + 1;
}
void is_balanced(TreeNode* root){
	bool res = true;
	int temp = is_balanced(root, res);
	if (res) cout << "Balanced" << endl;
	else cout << "Not Balanced" << endl;
}
int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	is_balanced(root);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(4);
	root->right = new TreeNode(4);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(5);
	is_balanced(root);
}