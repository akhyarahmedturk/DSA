#include<iostream>
#include<vector>

using namespace std;

class Node{
public:
    string data;
    Node* prev, * next;
    Node(string d) :data(d), prev(nullptr), next(nullptr){ }
    Node(string d, Node* p, Node* n) :data(d), prev(p), next(n){ }
};

class BrowserHistory{
    Node* head;
public:
    BrowserHistory(string homepage){
        head = new Node(homepage);
    }

    void visit(string url){
        Node* temp1 = head->next, * temp2;
        head->next = new Node(url, head, nullptr);
        head = head->next;
        while (temp1){
            temp2 = temp1->next;
            delete temp1;
            temp1 = temp2;
        }
    }

    string back(int steps){
        while (steps > 0 && head->prev){
            head = head->prev;
            steps--;
        }
        return head->data;
    }

    string forward(int steps){
        while (steps > 0 && head->next){
            head = head->next;
            steps--;
        }
        return head->data;
    }
};

int main(){
    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");
    cout << browserHistory.back(1) << endl;
    cout << browserHistory.back(1) << endl;
    cout << browserHistory.forward(1) << endl;
    browserHistory.visit("linkedin.com");
    cout << browserHistory.forward(2) << endl;
    cout << browserHistory.back(2) << endl;
    cout << browserHistory.back(7) << endl;
    return 0;
}