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
    ListNode* tail = nullptr;
    cout << "In Forward: order: ";
    while (head){
        cout << head->data << ",";
        tail = head;
        head = head->next;
    }
    cout << endl << "In reverse order: ";
    while (tail){
        cout << tail->data << ",";
        tail = tail->prev;
    }
    cout << endl;
}

ListNode* concatinate(ListNode* L, ListNode* M){
    ListNode* head = new ListNode(0), * temp;
    temp = head;
    while (L && M){
        temp->next = new ListNode(L->data, temp, nullptr);
        temp = temp->next;
        L = L->next;

        temp->next = new ListNode(M->data, temp, nullptr);
        temp = temp->next;
        M = M->next;
    }
    while (L){
        temp->next = new ListNode(L->data, temp, nullptr);
        temp = temp->next;
        L = L->next;
    }
    while (M){
        temp->next = new ListNode(M->data, temp, nullptr);
        temp = temp->next;
        M = M->next;
    }
    temp = head;
    head = head->next;
    delete temp;
    if (head){
        head->prev = nullptr;
    }
    return head;
}

int main(){
    ListNode* L = new ListNode(1), * M = new ListNode(2), * temp_L, * temp_M;
    temp_L = L;
    temp_M = M;
    for (int i = 4;i <= 10;i += 2){
        temp_L->next = new ListNode(i - 1, temp_L, nullptr);
        temp_M->next = new ListNode(i, temp_M, nullptr);
        temp_L = temp_L->next;
        temp_M = temp_M->next;
    }
    cout << "L : ";
    display(L);
    cout << "M : ";
    display(M);
    ListNode* conc = concatinate(L, M);
    cout << "Concatinated List: ";
    display(conc);
    return 0;
}