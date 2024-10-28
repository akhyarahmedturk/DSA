#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    int n = 0, m = 0, k = left;
    vector<int> x1(mid - left);
    vector<int> x2(right - mid);
    for (int i = 0;i < x1.size();i++)
        x1[i] = arr[left + i];
    for (int i = 0;i < x2.size();i++)
        x2[i] = arr[mid + i];
    while (n < x1.size() && m < x2.size()){
        if (x1[n] <= x2[m])
            arr[k++] = x1[n++];
        else
            arr[k++] = x2[m++];
    }
    while (n < x1.size()){
        arr[k++] = x1[n++];
    }
    while (m < x2.size()){
        arr[k++] = x2[m++];
    }
}

void merge_sort(vector<int>& arr, int n){// implementation using 2 stack
    stack<pair<int, int>> st1, st2;
    pair<int, int> temp1, temp2;
    for (int i = 0;i < n;i++){
        st1.push({ i,i + 1 });
    }
    while (st1.size() > 1){
        while (st1.size() > 1){
            temp2 = st1.top();
            st1.pop();
            temp1 = st1.top();
            st1.pop();
            merge(arr, temp1.first, temp1.second, temp2.second);
            st2.push({ temp1.first,temp2.second });
        }
        if (!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        while (st2.size() > 1){
            temp1 = st2.top();
            st2.pop();
            temp2 = st2.top();
            st2.pop();
            merge(arr, temp1.first, temp1.second, temp2.second);
            st1.push({ temp1.first,temp2.second });
        }
        if (!st2.empty()){
            st1.push(st2.top());
            st2.pop();
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
    vector<int> arr = { 3,0,1,8,2 };
    int n = arr.size();
    cout << "Unsorted : ";
    display(arr);
    merge_sort(arr, n);
    cout << "Sorted : ";
    display(arr);
    return 0;
}

// implementation using queue 
// void merge_sort(vector<int>& arr, int n){ 
//     queue<pair<int, int>> q;
//     pair<int, int> temp1, temp2;
//     for (int i = 0;i < n;i++){
//         q.push({ i,i + 1 });
//     }
//     while (q.size() > 1){
//         int size = q.size();
//         while (size > 1){
//             temp1 = q.front();
//             q.pop();
//             temp2 = q.front();
//             q.pop();
//             merge(arr, temp1.first, temp1.second, temp2.second);
//             q.push({ temp1.first,temp2.second });
//             size -= 2;
//         }
//         if (size == 1){
//             q.push(q.front());
//             q.pop();
//         }
//     }
// }