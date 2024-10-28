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

ListNode* merge(ListNode* list1, ListNode* list2){
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
ListNode* get_middle(ListNode* slow){
    ListNode* fast = slow;
    while (fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* sort(ListNode* start){
    if (start != nullptr && start->next != nullptr){
        ListNode* middle = get_middle(start), * start_right;
        start_right = middle->next;
        middle->next = nullptr;
        start = sort(start);
        start_right = sort(start_right);
        start = merge(start, start_right);
    }
    return start;
}

int main(){
    ListNode* List = Input();
    cout << "Before Sorting : ";
    display(List);
    List = sort(List);
    cout << "After Sorting : ";
    display(List);
    return 0;
}