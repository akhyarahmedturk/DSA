#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int v) :data(v), next(nullptr), prev(nullptr){ }
    Node(int v, Node* p, Node* n) :data(v), prev(p), next(n){ }
};

void display(Node* head){
    Node* tail = nullptr;
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

Node* concatinate(Node* L, Node* M){
    Node* head = new Node(0), * temp;
    temp = head;
    while (L && M){
        temp->next = new Node(L->data, temp, nullptr);
        temp = temp->next;
        L = L->next;

        temp->next = new Node(M->data, temp, nullptr);
        temp = temp->next;
        M = M->next;
    }
    while (L){
        temp->next = new Node(L->data, temp, nullptr);
        temp = temp->next;
        L = L->next;
    }
    while (M){
        temp->next = new Node(M->data, temp, nullptr);
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
    Node* L = new Node(1), * M = new Node(2), * temp_L, * temp_M;
    temp_L = L;
    temp_M = M;
    for (int i = 4;i <= 10;i += 2){
        temp_L->next = new Node(i - 1, temp_L, nullptr);
        temp_M->next = new Node(i, temp_M, nullptr);
        temp_L = temp_L->next;
        temp_M = temp_M->next;
    }
    cout << "L : ";
    display(L);
    cout << "M : ";
    display(M);
    Node* conc = concatinate(L, M);
    cout << "Concatinated List: ";
    display(conc);
    return 0;
}