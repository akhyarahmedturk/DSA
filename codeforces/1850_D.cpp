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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        int res=0,curr=1;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]<=k) curr++;
            else{
                res=max(res,curr);
                curr=1;
            }
        }
        cout<<n-max(res,curr)<<endl;
    }
    return 0;
}