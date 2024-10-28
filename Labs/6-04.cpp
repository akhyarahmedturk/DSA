#include<iostream>
#include<stack>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){ }
    ListNode(int x) : val(x), next(nullptr){ }
    ListNode(int x, ListNode* next) : val(x), next(next){ }
};
void display(ListNode* head){
    while (head){
        cout << head->val << ",";
        head = head->next;
    }
    cout << endl;
}
ListNode* Input(){
    int n;
    ListNode* head = new ListNode(), * temp;
    temp = head;
    cout << "Enter size : ";
    cin >> n;
    for (int i = 0;i < n;i++){
        temp->next = new ListNode();
        temp = temp->next;
        cin >> temp->val;
    }
    temp = head;
    head = head->next;
    delete temp;
    return head;
}

ListNode* middle(ListNode* head){
    ListNode* slow = head, * fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->next;
}
bool isPalindrome(ListNode* head){
    ListNode* mid;
    mid = middle(head);
    stack<int> st;
    while (mid){
        st.push(mid->val);
        mid = mid->next;
    }
    while (!st.empty()){
        if (head->val != st.top()){
            return false;
        }
        st.pop();
        head = head->next;
    }
    return true;
}

int main(){
    ListNode* List = Input();
    cout << "List : ";
    display(List);
    if (isPalindrome(List))
        cout << "The above list is palindrome " << endl;
    else
        cout << "The above list is not palindrome " << endl;
    return 0;
}