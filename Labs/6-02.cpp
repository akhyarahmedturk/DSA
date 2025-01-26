#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){ }
    ListNode(int x) : val(x), next(nullptr){ }
    ListNode(int x, ListNode* next) : val(x), next(next){ }
};
void display(ListNode* head){
    while (head){
        cout << head->val << ",";
        head = head->next;
    }
    cout << endl;
}
ListNode* Input(){
    int n;
    ListNode* head = new ListNode(), * temp;
    temp = head;
    cout << "Enter size : ";
    cin >> n;
    for (int i = 0;i < n;i++){
        temp->next = new ListNode();
        temp = temp->next;
        cin >> temp->val;
    }
    temp = head;
    head = head->next;
    delete temp;
    return head;
}


ListNode* deleteDuplicates(ListNode* head){
    if (!head) return head;
    ListNode* temp = head;
    while (temp->next){
        if (temp->next->val == temp->val){
            ListNode* duplicate=temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    ListNode* List = Input();
    cout << "Before deleting duplicates : ";
    display(List);
    List = deleteDuplicates(List);
    cout << "After deleting duplicates : ";
    display(List);
    return 0;
}