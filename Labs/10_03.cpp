#include<iostream>
#include<queue>

using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int data) :data(data), next(nullptr){ }
    ListNode(int data, ListNode* n) :data(data), next(n){ }
};

class TreeNode{
public:
    int data;
    TreeNode* left, * right;
    TreeNode(int data) :data(data), left(nullptr), right(nullptr){ }
    TreeNode(int data, TreeNode* l, TreeNode* r) :data(data), left(l), right(r){ }
};

ListNode* middle(ListNode* slow){
    ListNode* fast = slow, * prev;
    while (fast && fast->next){
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    prev->next = nullptr;
    return slow;
}

TreeNode* Sorted_list_to_BST(ListNode* head){
    if (!head) return nullptr;
    TreeNode* new_node = new TreeNode(head->data);
    if (!head->next) return new_node;
    ListNode* mid = middle(head);
    new_node->data = mid->data;
    new_node->left = Sorted_list_to_BST(head);
    new_node->right = Sorted_list_to_BST(mid->next);
    delete mid;
    return new_node;
}

void lavel_order_traversal(TreeNode* root){ // traversal function
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        while (size > 0){
            TreeNode* temp = q.front();
            q.pop();
            if (!temp){
                cout << "null" << " ";
            }
            else{
                cout << temp->data << " ";
                q.push(temp->left);
                q.push(temp->right);
            }
            size--;
        }
        cout << endl;
    }
}

int main(){
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    TreeNode* root = Sorted_list_to_BST(head);
    cout << "Tree:" << endl;
    lavel_order_traversal(root);
    return 0;
}