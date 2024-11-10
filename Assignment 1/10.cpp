#include<iostream>
#include<stack>
#include "TreeNode.h"

using namespace std;

class ListNode{// class for linked list
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){ }
    ListNode(int x) : val(x), next(nullptr){ }
    ListNode(int x, ListNode* next) : val(x), next(next){ }
};

void display_list(ListNode* head){// no need to write in assignment
    while (head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void inorderTraversal(TreeNode* node){ // no need to write in assignment
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

void preOrderTraversal(TreeNode* node){ // no need to write in assignment
    if (node == nullptr) return;
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

ListNode* middle(ListNode* slow, ListNode* end){// to get the middle element
    ListNode* fast = slow;
    while (fast != end && fast->next != end){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
TreeNode* get_tree(ListNode* head, ListNode* end){ // reccursive function
    if (!head) return nullptr;
    TreeNode* new_node = new TreeNode(head->val);
    if (head->next == end) return new_node;
    ListNode* mid = middle(head, end);
    new_node->data = mid->val;// middle element as root 
    if (head != mid) // left part as left subtree
        new_node->left = get_tree(head, mid);
    if (mid->next != end)// right part as right subtree
        new_node->right = get_tree(mid->next, end);
    return new_node;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(10);
    TreeNode* tree = get_tree(head, nullptr);
    cout << "list: ";
    display_list(head);
    cout << "Ineorder traversal of tree: ";
    inorderTraversal(tree);
    cout << endl;
    cout << "Preorder traversal of tree: ";
    preOrderTraversal(tree);
    cout << endl;
    return 0;
}