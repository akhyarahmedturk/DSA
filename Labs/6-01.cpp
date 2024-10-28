#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){ }
    ListNode(int x) : val(x), next(nullptr){ }
    ListNode(int x, ListNode* next) : val(x), next(next){ }
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode* head = new ListNode(), * temp;
    temp = head;
    while (list1 && list2){
        if (list1->val < list2->val){
            temp->next = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if (list1) temp->next = list1;
    else temp->next = list2;
    temp = head;
    head = head->next;
    delete temp;
    return head;
}

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
int main(){
    ListNode* L1, * L2;
    cout << endl << "Enter data of List 1" << endl;
    L1 = Input();
    cout << endl << "Enter data of List 2" << endl;
    L2 = Input();
    cout << endl << "List 1 : ";
    display(L1);
    cout << endl << "List 2 : ";
    display(L2);
    L1 = mergeTwoLists(L1, L2);
    cout << endl << "Merged list : ";
    display(L1);
    return 0;
}