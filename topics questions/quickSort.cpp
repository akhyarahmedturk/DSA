#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr,int left,int right){
    int i=left+1,j=right;
    while(i<=j){
        while(i<=j && arr[i]<=arr[left]) i++;
        while(i<=j && arr[j]>arr[left]) j--;
        if(i<j)  swap(arr[i],arr[j]);
    }
    swap(arr[left],arr[j]);
    return j;
}
void QuickSort(vector<int> &arr,int left,int right){
    if(left<right){
        int par=partition(arr,left,right);
        QuickSort(arr,left,par-1);
        QuickSort(arr,par+1,right);
    }
}
void display(vector<int> &arr,int n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
    cout<<"Unsorted : ";
    display(arr,n);
    QuickSort(arr,0,arr.size()-1);
    cout<<"Sorted : ";
    display(arr,n);
}