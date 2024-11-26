#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high], x = low - 1;
    for (int i = low;i < high;i++){
        if (arr[i] <= pivot){
            swap(arr[++x], arr[i]);
        }
    }
    swap(arr[++x], arr[high]);
    return x;
}

void quick_sort(vector<int>& arr, int high){
    stack<pair<int, int>> st;
    pair<int, int> temp;
    st.push({ 0,high });
    while (!st.empty()){
        temp = st.top();
        st.pop();
        int pivot = partition(arr, temp.first, temp.second);
        if (pivot > temp.first + 1){
            st.push({ temp.first,pivot - 1 });
        }
        if (pivot < temp.second - 1){
            st.push({ pivot + 1,temp.second });
        }
    }
}

void display(vector<int>& arr){
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << ",";
    }
    cout << "]" << endl;
}

int main(){
    vector<int> arr = { 3,4,5,1,2,90,3 };
    display(arr);
    quick_sort(arr, arr.size() - 1);
    display(arr);
    return 0;
}