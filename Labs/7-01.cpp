#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node() : data(0), next(nullptr){ }
    Node(int x) : data(x), next(nullptr){ }
    Node(int x, Node* next) : data(x), next(next){ }
};
class Circular_queue{
    Node* tail;
public:
    Circular_queue() :tail(nullptr){ }
    void Enqueue(int val){
        Node* temp = new Node(val);
        if (!tail){
            tail = temp;
            tail->next = tail;
        }
        else{
            temp->next = tail->next;
            tail->next = temp;
            tail = tail->next;
        }
    }
    int Front(){
        if (is_empty()) return -123456789;
        else{
            return tail->next->data;
        }
    }
    void Dequeue(){
        if (is_empty()) return;
        Node* temp = tail->next;
        if (tail->next == tail){
            tail = nullptr;
        }
        else{
            tail->next = temp->next;
        }
        delete temp;
    }
    bool is_empty(){
        return !tail;
    }
    void display(){
        cout << "Queue: ";
        if (tail){
            Node* temp = tail->next;
            do{
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != tail->next);
        }
        cout << endl;
    }
};

int main(){
    Circular_queue q;
    q.Enqueue(5);
    q.Enqueue(10);
    q.display();
    cout << "Front: " << q.Front() << endl;
    q.Dequeue();
    cout << "Front: " << q.Front() << endl;
    q.Dequeue();
    cout << "Front: " << q.Front() << endl; // List is empty
    q.Dequeue();
    return 0;
}