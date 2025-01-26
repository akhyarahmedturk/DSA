#include<iostream>
#include<vector>

using namespace std;
class sort{
    void max_heapify_down(vector<int>& heap, int i, int size){
        while (2 * i + 1 < size){
            int LC = 2 * i + 1;
            int RC = 2 * i + 2;
            int largest = LC;
            if (RC<size && heap[RC] > heap[largest])
                largest = RC;
            if (heap[largest] < heap[i]) break;
            swap(heap[largest], heap[i]);
            i = largest;
        }
    }
    void min_heapify_down(vector<int>& heap, int i, int size){
        while (2 * i + 1 < size){
            int LC = 2 * i + 1;
            int RC = 2 * i + 2;
            int smallest = LC;
            if (RC < size && heap[RC] < heap[smallest])
                smallest = RC;
            if (heap[smallest] > heap[i]) break;
            swap(heap[smallest], heap[i]);
            i = smallest;
        }
    }
public:
    void sort_asc(vector<int>& vec){
        int size = vec.size();
        for (int i = size / 2;i >= 0;i--){
            max_heapify_down(vec, i, size);
        }
        int curr_size = size;
        for (int i = 0;i < size - 1;i++){
            swap(vec[0], vec[curr_size - 1]);
            curr_size--;// now the last element is at sorted position
            max_heapify_down(vec, 0, curr_size);
        }
    }
    void sort_dsc(vector<int>& vec){
        int size = vec.size();
        for (int i = size / 2;i >= 0;i--){
            min_heapify_down(vec, i, size);
        }
        int curr_size = size;
        for (int i = 0;i < size - 1;i++){
            swap(vec[0], vec[curr_size - 1]);
            curr_size--;// now the last element is at sorted position
            min_heapify_down(vec, 0, curr_size);
        }
    }
};

void display(vector<int>& vec){
    for (int i = 0;i < vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(){
    sort sort;
    vector<int> vec = { 2,56,3,87,5,9,34,0,90,87 };
    cout << "Before sorting: ";
    display(vec);
    sort.sort_asc(vec);
    cout << "After sorting in Ascending order: ";
    display(vec);
    sort.sort_dsc(vec);
    cout << "After sorting in Descending order: ";
    display(vec);
    return 0;
}