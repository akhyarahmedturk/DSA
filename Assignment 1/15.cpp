#include<iostream>
#include"min_heap.h"// both heaps are imported from classes we have used in previous questions
#include"max_heap.h"

using namespace std;

// ->We have used two heap 
//  1) for the last half elements we are using  min heap , by using this the middle element (which is the highest element of fist half)
//  will be on top and we can directly get it.
//  2) for the second half elements we are using  min heap, by using this the middle element (which is the smalest element of second half)
//  will be on top and we can directly get it.
// ->for Each insertion we store the element based on it,s value either in max or min heap, then
//  if the difference of size in both heaps in >1 then we rebalance then by removing top from one and adding in another heap
// ->For each deletion we check
//  1) if heap1 i:e max heap has >= elements as min heap then we delete the top of max heap
//  2) else we delete from min heap
//  for ex. if no of nodes are (max_heap=5, min_heap=4) then we delete from max heap i:e 5th element of total 9
//  (max_heap=4, min_heap=4) then we delete from max heap i:e 4th element of total 8 (n/2)th element
//  (max_heap=4, min_heap=5) then we delete from minx heap i:e 5th element of total 9 
class middle_heap{
    max_heap max_h;//to store the first half part
    min_heap min_h;//to store the second half part
public:
    void push(int val){
        if (val > max_h.top()){// pushing based on value
            min_h.push(val);
        }
        else{
            max_h.push(val);
        }
        if (max_h.size() - min_h.size() > 1){// balancing size
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