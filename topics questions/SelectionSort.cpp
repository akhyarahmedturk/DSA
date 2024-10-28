#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(vector<int> &arr){
    int min;
    for(int i=0;i<arr.size()-1;i++){
        min=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[min]) min=j;
        }
        swap(arr[min],arr[i]);
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
    SelectionSort(arr);
    cout<<"Sorted : ";
    display(arr,n);
}