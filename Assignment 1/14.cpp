#include<iostream>
#include<vector>
#include"max_heap.h"
using namespace std;

// time complexity O(m+n)
vector<int> mergeHeaps(vector<int> heap1, vector<int> heap2){
    heap1.insert(heap1.end(), heap2.begin(), heap2.end());// merging both vectors to create a single vector
    for (int i = heap1.size() - 1;i >= 0;i--){// heapify_down all the nodes of the merged vector
        int j = i;
        while (2 * j + 1 < heap1.size()){
            int LC = 2 * j + 1;
            int RC = 2 * j + 2;
            int largest = LC;
            if (RC<heap1.size() && heap1[RC] > heap1[largest])
                largest = RC;
            if (heap1[largest] < heap1[j]) break;
            swap(heap1[largest], heap1[j]);
            j = largest;
        }
    }
    return heap1;
}

void display(vector<int>& vec){
    for (int i = 0;i < vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> heap1 = { 50,30,40,20,10,20,10 }, heap2 = { 100,80,90,50,60,50,60 };
    display(heap1);
    display(heap2);
    heap1 = mergeHeaps(heap1, heap2);
    display(heap1);
    return 0;
}