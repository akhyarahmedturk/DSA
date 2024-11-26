#include<iostream>
#include<vector>
using namespace std;

void BubbleSort(vector<int>& arr){
    bool check = false;
    for (int i = 0;i < arr.size() - 1;i++){
        for (int j = 0;j < arr.size() - i - 1;j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                check = true;
            }
        }
        if (!check) return;
    }
}
void display(vector<int>& arr, int n){
    for (int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0;i < arr.size();i++)
        cin >> arr[i];
    cout << "Unsorted : ";
    display(arr, n);
    BubbleSort(arr);
    cout << "Sorted : ";
    display(arr, n);
}