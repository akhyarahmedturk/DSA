#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            ++i;
        }
        else{
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1){
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2){
        arr[k] = R[j];
        ++j;
        ++k;
    }
}
void mergesort(vector<int>& arr){
    int count = 0;
    int n = arr.size();
    stack<vector<int>> s;
    s.push({ 0, n - 1 });
    vector<pair<int, int>> mergeIntervals;
    while (!s.empty()){
        vector<int> bounds = s.top();
        s.pop();
        int left = bounds[0];
        int right = bounds[1];
        count++;
        if (left < right){
            int mid = left + (right - left) / 2;
            s.push({ left, mid });
            s.push({ mid + 1, right });
            mergeIntervals.push_back({ left, right });
        }
    }
    for (int i = mergeIntervals.size() - 1; i >= 0; --i){
        int left = mergeIntervals[i].first;
        int right = mergeIntervals[i].second;
        int mid = left + (right - left) / 2;
        if (left < right){
            count += (right - left);
            merge(arr, left, mid, right);
        }
    }
    cout << "n " << n << " count " << count << endl;
}
int main(){
    vector<int> arr = { 0,23,1,4,4,4,4,4, 0,23,1,4,4,4,4,4 };
    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    mergesort(arr);
    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}