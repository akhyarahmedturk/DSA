#include<iostream>
using namespace std;
template<class T>
class ListNode{
public:
    T data;
    ListNode* prev;
    ListNode* next;
    ListNode(T v) :data(v), prev(nullptr), next(nullptr){ }
    ListNode(T v, ListNode* p, ListNode* n) :data(v), prev(p), next(n){ }
};

template<class T>
class Deque{
    ListNode<T>* front;
    ListNode<T>* rear;
public:
    Deque(){ }
    void enqueue_front(T val){
        if (!front){
            front = new ListNode<T>(val);
            rear = front;
        }
        else{
            front->prev = new ListNode<T>(val, nullptr, front);
            front = front->prev;
        }
    }
    void enqueue_rear(T val){
        if (!rear){
            rear = new ListNode<T>(val);
            front = rear;
        }
        else{
            rear->next = new ListNode<T>(val, rear, nullptr);
            rear = rear->next;
        }
    }
    void dequeue_front(){
        if (front == rear){
            front = nullptr;
            rear = nullptr;
        }
        else if (front){
            front = front->next;
            delete front->prev;
            front->prev = nullptr;
        }
    }
    void dequeue_rear(){
        if (front == rear){
            front = nullptr;
            rear = nullptr;
        }
        else if (rear){
            rear = rear->prev;
            delete rear->next;
            rear->next = nullptr;
        }
    }
    T Front(){
        if (front){
            return front->data;
        }
        T temp;
        return temp;
    }
    T Rear(){
        if (rear){
            return rear->data;
        }
        T temp;
        return temp;
    }
    bool isempty(){
        return !front;
    }
    ~Deque(){
        ListNode<T>* temp;
        while (front){
            temp = front;
            front = front->next;
            delete temp;
        }
    }
};
int main(){
    Deque<int> dq;
    dq.enqueue_front(9);
    cout << "Front: " << dq.Front() << endl;
    cout << "Rear: " << dq.Rear() << endl;
    dq.enqueue_front(5);
    cout << "Front: " << dq.Front() << endl;
    cout << "Rear: " << dq.Rear() << endl;
    dq.dequeue_rear();
    cout << "Front: " << dq.Front() << endl;
    cout << "Rear: " << dq.Rear() << endl;
    dq.dequeue_rear();
    dq.enqueue_rear(4);
    cout << "Front: " << dq.Front() << endl;
    cout << "Rear: " << dq.Rear() << endl;
    return 0;
}