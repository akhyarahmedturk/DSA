#include<iostream>
#include<vector>

using namespace std;

class ListNode{
public:
    string data;
    ListNode* prev, * next;
    ListNode(string d) :data(d), prev(nullptr), next(nullptr){ }
    ListNode(string d, ListNode* p, ListNode* n) :data(d), prev(p), next(n){ }
};

class BrowserHistory{
    ListNode* head;
public:
    BrowserHistory(string homepage){
        head = new ListNode(homepage);
    }

    void visit(string url){
        ListNode* temp1 = head->next, * temp2;
        head->next = new ListNode(url, head, nullptr);
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