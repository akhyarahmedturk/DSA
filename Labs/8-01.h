#include <iostream>
#include <queue>

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
class BinaryTree{ // Binary Tree Class
public:
	TreeNode* root;
	BinaryTree(){
		root = nullptr;
	}
	void insert(int data){ // Function to insert data in level-order (simple binary tree, not based on value comparison)
		TreeNode* newNode = new TreeNode(data);
		if (root == nullptr){ // If the tree is empty, set the new node as the root
			root = newNode;
			return;
		}
		queue<TreeNode*> q; // Use a queue for level-order traversal to find the first available position
		q.push(root);
		while (!q.empty()){
			TreeNode* current = q.front();
			q.pop();
		// Check the left child
			if (current->left == nullptr){
				current->left = newNode;
				return;
			}
			else{
				q.push(current->left);
			}
			// Check the right child
			if (current->right == nullptr){
				current->right = newNode;
				return;
			}
			else{
				q.push(current->right);
			}
		}
	}
	void inorder(){ // Function to perform inorder traversal (left -> root -> right)
		inorderTraversal(root);
		cout << endl;
	}
	void preOrder(){ // Function to perform inorder traversal (left -> root -> right)
		preOrderTraversal(root);
		cout << endl;
	}
	void postOrder(){ // Function to perform inorder traversal (left -> root -> right)
		postOrderTraversal(root);
		cout << endl;
	}
	TreeNode* search(int val){
		if (root == nullptr){ // If the tree is empty, set the new node as the root
			return nullptr;
		}
		TreeNode* current;
		queue<TreeNode*> q; // Use a queue for level-order traversal to find the first available position
		q.push(root);
		while (!q.empty()){
			current = q.front();
			if (current->data == val) return current;
			q.pop();
			// Check the left child
			if (current->left){
				q.push(current->left);
			}
			else if (current->right){
				q.push(current->right);
			}
		}
		return nullptr;
	}
	void Delete(int val){
		if (root == nullptr){ // If the tree is empty, set the new node as the root
			return;
		}
		TreeNode* todelete = nullptr, * deepest, * parent;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()){
			deepest = q.front();
			q.pop();
			// Check the left child
			if (deepest->left){
				parent = deepest;
				q.push(deepest->left);
			}
			if (deepest->right){
				parent = deepest;
				q.push(deepest->right);
			}
			if (deepest->data == val) todelete = deepest;
		}
		if (!todelete) return;
		todelete->data = deepest->data;
		if (parent->left == deepest){
			parent->left = nullptr;
		}
		else{
			parent->right = nullptr;
		}
		delete deepest;
	}
private:
	void inorderTraversal(TreeNode* node){ // Recursive inorder traversal function
		if (node == nullptr) return;
		inorderTraversal(node->left);
		cout << node->data << " ";
		inorderTraversal(node->right);
	}
	void postOrderTraversal(TreeNode* node){ // Recursive postorder traversal function
		if (node == nullptr) return;
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		cout << node->data << " ";
	}
	void preOrderTraversal(TreeNode* node){ // Recursive preorder traversal function
		if (node == nullptr) return;
		cout << node->data << " ";
		preOrderTraversal(node->left);
		preOrderTraversal(node->right);
	}

};
