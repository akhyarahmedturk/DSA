#include<iostream>
#include<vector>
#include"min_heap.h"
using namespace std;

int find_max(min_heap& heap){
    if (heap.is_empty()) return -12345678;
    int MAX = INT_MIN, size = heap.vec.size();
    int i = size - 1;
    // no need to check whole tree, only check leaf nodes
    while (i >= 0 && 2 * i + 1 >= size){
        MAX = max(MAX, heap.vec[i]);
        i--;
    }
    return MAX;
}

int main(){
    min_heap heap;
    heap.push(2);
    heap.push(45);
    heap.push(6);
    heap.push(56);
    heap.push(9);
    heap.push(49);
    heap.push(5);
    heap.push(34);
    cout << "Max element in heap is: " << find_max(heap) << endl;
    return 0;
}