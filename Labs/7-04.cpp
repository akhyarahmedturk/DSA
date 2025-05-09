#include<iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* prev;
    ListNode* next;
    ListNode(int v) :data(v), next(nullptr), prev(nullptr){ }
    ListNode(int v, ListNode* p, ListNode* n) :data(v), prev(p), next(n){ }
};

void display(ListNode* head){
    ListNode* tail;
    cout << endl << "Forward traversal: ";
    while (head){
        cout << head->data << " ";
        tail = head;
        head = head->next;
    }
    cout << endl << " Backward traversal: ";
    while (tail){
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

ListNode* Input(){
    int n;
    ListNode* head = new ListNode(0, nullptr, nullptr), * temp;
    temp = head;
    cout << "Enter size : ";
    cin >> n;
    if (n < 1) return nullptr;
    for (int i = 0;i < n;i++){
        temp->next = new ListNode(0, temp, nullptr);
        temp = temp->next;
        cin >> temp->data;
    }
    temp = head;
    head = head->next;
    head->prev = nullptr;
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

ListNode* merge(ListNode* list1, ListNode* list2){
    ListNode* head = new ListNode(0), * temp, * previous;
    temp = head;
    while (list1 && list2){
        previous = temp;
        if (list1->data > list2->data){
            temp->next = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
        temp->prev = previous;
    }
    previous = temp;
    if (list1){
        temp->next = list1;
    }
    else{
        temp->next = list2;
    }
    temp = temp->next;
    temp->prev = previous;
    ListNode* ttemp = temp;
    temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
    return head;
}

ListNode* sort(ListNode* start){
    if (start != nullptr && start->next != nullptr){
        ListNode* middle = get_middle(start), * start_right;
        start_right = middle->next;
        middle->next = nullptr;
        start_right->prev = nullptr;
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