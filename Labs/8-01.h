#include <iostream>
#include <queue>

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
class BinaryTree{ // Binary Tree Class
public:
	Node* root;
	BinaryTree(){
		root = nullptr;
	}
	void insert(int data){ // Function to insert data in level-order (simple binary tree, not based on value comparison)
		Node* newNode = new Node(data);
		if (root == nullptr){ // If the tree is empty, set the new node as the root
			root = newNode;
			return;
		}
		queue<Node*> q; // Use a queue for level-order traversal to find the first available position
		q.push(root);
		while (!q.empty()){
			Node* current = q.front();
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
	Node* search(int val){
		if (root == nullptr){ // If the tree is empty, set the new node as the root
			return nullptr;
		}
		Node* current;
		queue<Node*> q; // Use a queue for level-order traversal to find the first available position
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
		Node* todelete = nullptr, * deepest, * parent;
		queue<Node*> q;
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
	void inorderTraversal(Node* node){ // Recursive inorder traversal function
		if (node == nullptr) return;
		inorderTraversal(node->left);
		cout << node->data << " ";
		inorderTraversal(node->right);
	}
	void postOrderTraversal(Node* node){ // Recursive postorder traversal function
		if (node == nullptr) return;
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		cout << node->data << " ";
	}
	void preOrderTraversal(Node* node){ // Recursive preorder traversal function
		if (node == nullptr) return;
		cout << node->data << " ";
		preOrderTraversal(node->left);
		preOrderTraversal(node->right);
	}

};
