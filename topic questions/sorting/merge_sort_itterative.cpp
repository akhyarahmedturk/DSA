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

void merge_sort(vector<int>& arr, int n){
    int count = 0;
    stack<pair<int, int>> st1, st2;
    pair<int, int> temp1, temp2;
    for (int i = 0;i < n;i++){
        //count++;
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
            count += (temp2.second - temp1.first);
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
            count += (temp2.second - temp1.first);
        }
        if (!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    cout << count << endl;
}

void display(vector<int>& arr){
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << ",";
    }
    cout << "]" << endl;
}

int main(){
    vector<int> arr = { 34,67,0,1,1,1,1,1,1,1,1,1,45,34,23,67 };
    int n = arr.size();
    cout << n << endl;
    display(arr);
    merge_sort(arr, n);
    display(arr);
    return 0;
}