#include<iostream>
using namespace std;
template<class T>
class Node{
public:
    T data;
    Node* prev;
    Node* next;
    Node(T v) :data(v), prev(nullptr), next(nullptr){ }
    Node(T v, Node* p, Node* n) :data(v), prev(p), next(n){ }
};

template<class T>
class Deque{
    Node<T>* front;
    Node<T>* rear;
public:
    Deque(){ }
    void enqueue_front(T val){
        if (!front){
            front = new Node<T>(val);
            rear = front;
        }
        else{
            front->prev = new Node<T>(val, nullptr, front);
            front = front->prev;
        }
    }
    void enqueue_rear(T val){
        if (!rear){
            rear = new Node<T>(val);
            front = rear;
        }
        else{
            rear->next = new Node<T>(val, rear, nullptr);
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
        Node<T>* temp;
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