#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,x;
        cin>>n>>x;
        long long sum;
        vector<long long> arr(n+1);
        arr[0]=0;
        for(long long i=1;i<=n;i++){
            cin>>arr[i];
            arr[i]+=arr[i-1];
        }
        sum=arr.back();
        for(long long i=0;i<x;i++){
            long long l,r,k;
            cin>>l>>r>>k;
            if((sum-arr[r]+arr[l-1] + (r-l+1)*k)%2==1) cout<<"YES\n";
            else cout<<"NO\n";
        } 
    }
    return 0;
}