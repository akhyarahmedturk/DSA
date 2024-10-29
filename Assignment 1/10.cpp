#include<iostream>
#include<stack>
#include "Node.h"

using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){ }
    ListNode(int x) : val(x), next(nullptr){ }
    ListNode(int x, ListNode* next) : val(x), next(next){ }
};

void display_list(ListNode* head){
    while (head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void inorderTraversal(Node* node){ // Recursive inorder traversal function
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

void preOrderTraversal(Node* node){ // Recursive preorder traversal function
    if (node == nullptr) return;
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

ListNode* middle(ListNode* slow, ListNode* end){
    ListNode* fast = slow;
    while (fast != end && fast->next != end){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node* get_tree(ListNode* head, ListNode* end){
    if (!head) return nullptr;
    Node* new_node = new Node(head->val);
    if (head->next == end) return new_node;
    ListNode* mid = middle(head, end);
    new_node->data = mid->val;
    if (head != mid)
        new_node->left = get_tree(head, mid);
    if (mid->next != end)
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
    Node* tree = get_tree(head, nullptr);
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