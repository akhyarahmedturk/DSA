#include<iostream>
#include<queue>
#include"8-01.h"
using namespace std;

bool validate(Node* L, Node* R){
	if (!L && !R) return true;
	if (!L || !R) return false;
	if (L->data != R->data) return false;
	if (!validate(L->left, R->right) || !validate(L->right, R->left)) return false;
	return true;
}

int main(){
	BinaryTree tree;
	// Insert values into the binary tree in level-order
	tree.insert(1);
	tree.insert(2);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(4);
	tree.insert(3);
	if (validate(tree.root->left, tree.root->right)){
		cout << "Mirror" << endl;
	}
	else{
		cout << "Not Mirror" << endl;
	}
	tree.insert(7);
	if (validate(tree.root->left, tree.root->right)){
		cout << "Mirror" << endl;
	}
	else{
		cout << "Not Mirror" << endl;
	}
}