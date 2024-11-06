#include<iostream>
#include"min_heap.h"
#include"max_heap.h"

using namespace std;

class middle_heap{
    min_heap min_h;
    max_heap max_h;
public:
    void push(int val){
        if (val > max_h.top()){
            min_h.push(val);
        }
        else{
            max_h.push(val);
        }
        if (max_h.size() - min_h.size() > 1){
            min_h.push(max_h.top());
            max_h.pop();
        }
        else if (min_h.size() - max_h.size() > 1){
            max_h.push(min_h.top());
            min_h.pop();
        }
    }
    int middle(){
        if (size() == 0) return -123456789;
        else if (max_h.size() >= min_h.size()){//for even no. of elements return (n)/2 th element
            return max_h.top();
        }
        else return min_h.top();
    }
    void pop(){
        if (size() == 0) return;
        else if (max_h.size() >= min_h.size()){//for even no. of elements remove (n)/2 th element
            max_h.pop();
        }
        else min_h.pop();
    }
    bool is_empty(){
        return size() == 0;
    }
    int size(){
        return max_h.size() + min_h.size();
    }
};

int main(){
    middle_heap mh;
    mh.push(50);
    cout << "Middle: " << mh.middle() << endl;
    mh.push(40);
    cout << "Middle: " << mh.middle() << endl;
    mh.push(30);
    cout << "Middle: " << mh.middle() << endl;
    mh.push(60);
    cout << "Middle: " << mh.middle() << endl;
    mh.pop();
    cout << "Middle: " << mh.middle() << endl;
    mh.pop();
    cout << "Middle: " << mh.middle() << endl;
    mh.pop();
    cout << "Middle: " << mh.middle() << endl;
    mh.pop();
    cout << "Middle: " << mh.middle() << endl;//No elements in heap
    return 0;
}