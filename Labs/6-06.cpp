#include<iostream>
#include<vector>
using namespace std;

template<class T>
class ListNode{
public:
    T val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){ }
    ListNode(T x) : val(x), next(nullptr){ }
    ListNode(T x, ListNode* next) : val(x), next(next){ }
};

template<class T>
class Stack{
    ListNode<T>* head;
public:
    Stack() :head(nullptr){ }
    void push(int val){
        head = new ListNode<T>(val, head);
    }
    int top(){
        if (!isempty()) return head->val;
        else return -123456789;
    }
    void pop(){
        if (!isempty()){
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    bool isempty(){
        return !head;
    }
};

int main(){
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    while (!st.isempty()){
        cout << "," << st.top();
        st.pop();
    }
    return 0;
}