#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        if(arr[0]==1) arr[0]++;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]==1) arr[i+1]++;
            if(arr[i+1]%arr[i]==0){
                while(arr[i+1]%arr[i]==0){
                    arr[i+1]++;
                }
            }
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}