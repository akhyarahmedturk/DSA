#include<iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){ }
    ListNode(int x) : val(x), next(nullptr){ }
    ListNode(int x, ListNode* next) : val(x), next(next){ }
};

class Circular_queue{
    ListNode* tail;
public:
    Circular_queue() :tail(nullptr){ }
    void Enqueue(int val){
        if (isempty()){
            tail = new ListNode(val);
            tail->next = tail;
        }
        else{
            tail->next = new ListNode(val, tail->next);
            tail = tail->next;
        }
    }
    void Dequeue(){
        if (isempty()) return;
        if (tail->next == tail){
            delete tail;
            tail = nullptr;
        }
        else{
            tail->next = tail->next->next;
        }
    }
    int front(){
        if (isempty()) return -123456789;
        else return tail->next->val;
    }
    bool isempty(){
        return !tail;
    }
    void display(){
        if (tail){
            ListNode* temp = tail;
            do{
                temp = temp->next;
                cout << " " << temp->val;
            } while (temp != tail);
        }
        cout << endl;
    }
};

int main(){
    Circular_queue c;
    c.Enqueue(5);
    cout << "Enqueue 5 " << endl;
    c.Enqueue(2);
    cout << "Enqueue 2 " << endl;
    cout << "display ";
    c.display();
    c.Enqueue(45);
    cout << "Enqueue 45 " << endl;
    cout << "display ";
    c.display();
    cout << "front " << c.front() << endl;
    c.Dequeue();
    cout << "Dnqueue" << endl;
    cout << "display ";
    c.display();
    c.Dequeue();
    cout << "Dnqueue" << endl;
    cout << "display ";
    c.display();
    return 0;
}