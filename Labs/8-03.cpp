#include<iostream>
#include<queue>
using namespace std;

class Node{ // Node structure for the binary tree
public:
	int data;
	Node* left;
	Node* right;
	Node(int value){ // Constructor to initialize node
		data = value;
		left = nullptr;
		right = nullptr;
	}
};


int is_balanced(Node* root, bool& res){
	if (!root) return 0;
	int left_height = is_balanced(root->left, res);
	int right_height = is_balanced(root->right, res);
	if (abs(left_height - right_height) > 1) res = false;
	return max(left_height, right_height) + 1;
}
void is_balanced(Node* root){
	bool res = true;
	int temp = is_balanced(root, res);
	if (res) cout << "Balanced" << endl;
	else cout << "Not Balanced" << endl;
}
int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	is_balanced(root);
	root->left->left = new Node(3);
	root->left->left->left = new Node(4);
	root->right = new Node(4);
	root->right->right = new Node(4);
	root->right->right->right = new Node(5);
	is_balanced(root);
}