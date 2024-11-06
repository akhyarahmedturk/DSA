#include<iostream>
#include<vector>

using namespace std;

class min_heap{
    void heapify_down(int i, int size){
        while (2 * i + 1 < size){
            int LC = 2 * i + 1;
            int RC = 2 * i + 2;
            int smallest = LC;
            if (RC < size && vec[RC] < vec[smallest])
                smallest = RC;
            if (vec[smallest] > vec[i]) break;
            swap(vec[smallest], vec[i]);
            i = smallest;
        }
    }
    void heapify_up(int i){
        while (i > 0 && vec[i] < vec[(i - 1) / 2]){
            swap(vec[i], vec[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
public:
    vector<int> vec;
    void push(int val){
        vec.push_back(val);
        heapify_up(vec.size() - 1);
    }
    int top(){
        if (vec.empty()) return -123456789;
        else return vec[0];
    }
    void pop(){
        if (vec.empty()) return;
        swap(vec[0], vec.back());
        vec.pop_back();
        heapify_down(0, vec.size());
    }
    bool is_empty(){
        return vec.size() == 0;
    }
    int size(){
        return vec.size();
    }
};